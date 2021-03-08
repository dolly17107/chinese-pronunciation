#include <cstdint>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/optional.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/vector.hpp>
#include "pugixml.hpp"
#include <buffer.h>
#include <filesystem.h>
#include "mc_pron.h"
std::unordered_map<std::string, std::uint8_t> initial_map = []() {
    std::unordered_map<std::string, std::uint8_t> im;
    for (std::size_t i = 0; i < mc_initial_data.size(); i++) { im.insert(std::make_pair(mc_initial_data[i].sbgy, i)); };
    return im; }();
std::unordered_multimap<std::string, std::uint8_t> final_map = []() {
    std::unordered_multimap<std::string, std::uint8_t> fm;
    for (std::size_t i = 0; i < mc_final_data.size(); i++) { fm.insert(std::make_pair(mc_final_data[i].sbgy, i)); }; // 3 matches for 重紐, 2 matches for ĭwĕn, ĭwĕt, ĭuĕn, and ĭuĕt, also 2 matches for ĭɛŋ, ĭɛk, ĭwɛŋ, ĭwɛk
    fm.insert(std::make_pair("ĭwĕn", 50));
    fm.insert(std::make_pair("ĭwĕt", 51));
    return fm; }();
std::unordered_map<std::string, std::uint8_t> tone_map = []() {
    std::unordered_map<std::string, std::uint8_t> tm;
    for (std::size_t i = 0; i < 四聲_classes.size(); i++) {
        tm.insert(std::make_pair(四聲_classes[i].sbgy[0], i));
        if (四聲_classes[i].sbgy[1] != 四聲_classes[i].sbgy[0]) { tm.insert(std::make_pair(四聲_classes[i].sbgy[1], i)); } };
    return tm; }();
mc_syllable parse_ipa(std::string ipa, std::string 小韻) {
    std::vector<mc_syllable> values;
    for (std::size_t i = 0; i <= ipa.size(); i++) {
        for (std::size_t j = i; j <= ipa.size(); j++) {
            std::array<std::string, 3> ipa_parts = {ipa.substr(0, i), ipa.substr(i, -i + j), ipa.substr(j, -j + ipa.size())};
            if (initial_map.count(ipa_parts[0]) && final_map.count(ipa_parts[1]) && tone_map.count(ipa_parts[2])) {
                if (final_map.count(ipa_parts[1]) == 1) {
                    values.push_back({initial_map.at(ipa_parts[0]), final_map.find(ipa_parts[1])->second, tone_map.at(ipa_parts[2])}); }
                else if (final_map.count(ipa_parts[1]) == 3) {
                    std::array<std::uint8_t, 3> indices;
                    auto er = final_map.equal_range(ipa_parts[1]);
                    indices[0] = (er.first++)->second;
                    indices[1] = (er.first++)->second;
                    indices[2] = (er.first++)->second;
                    std::sort(indices.begin(), indices.end());
                    for (std::uint8_t index : indices) {
                        if (mc_final_data[index].小韻.find(小韻) != std::string::npos) {
                            values.push_back({initial_map.at(ipa_parts[0]), index, tone_map.at(ipa_parts[2])}); } } }
                else if (ipa_parts[1] == "ĭwĕn" || ipa_parts[1] == "ĭwĕt" || ipa_parts[1] == "ĭuĕn" || ipa_parts[1] == "ĭuĕt"
                    || ipa_parts[1] == "ĭɛŋ" || ipa_parts[1] == "ĭɛk" || ipa_parts[1] == "ĭwɛŋ" || ipa_parts[1] == "ĭwɛk") {
                    std::array<std::uint8_t, 2> indices;
                    auto er = final_map.equal_range(ipa_parts[1]);
                    indices[0] = (er.first++)->second;
                    indices[1] = (er.first++)->second;
                    std::sort(indices.begin(), indices.end());
                    for (std::uint8_t index : indices) {
                        if (mc_final_data[index].小韻.find(小韻) != std::string::npos) {
                            values.push_back({initial_map.at(ipa_parts[0]), index, tone_map.at(ipa_parts[2])}); } } } } } }
    if (values.size() == 1) { return values[0]; }
    else { std::cout << values.size() << " matches for " << ipa << " " << 小韻 << "!" << 小韻.empty() << std::endl; return {std::uint8_t(-1), std::uint8_t(-1), std::uint8_t(-1)}; } }
std::vector<morpheme_data> load_sbgy() {
    std::vector<morpheme_data> dictionary;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("sbgy.xml");
    std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << std::endl;
    pugi::xml_node book = doc.child("book");
    for (pugi::xml_node volume : book.children("volume")) {
        for (pugi::xml_node rhyme : volume.children("rhyme")) {
            for (pugi::xml_node voice_part : rhyme.children("voice_part")) {
                std::string ipa = voice_part.attribute("ipa").value();
                pugi::xml_node first_word_head = voice_part.child("word_head");
                std::string first_character = first_word_head.first_child().value();
                mc_syllable value = parse_ipa(ipa, first_character);
                for (pugi::xml_node word_head : voice_part.children("word_head")) {
                    std::string 字 = word_head.first_child().value();
                    if (!字.empty()) {
                        dictionary.push_back({{value, 字}, word_head.child("note").first_child().value()}); } } } } }
    return dictionary; }
int main() {
    buffer_to_file(serialize(load_sbgy()), "sbgy"s);
    /*std::for_each(dictionary.begin(), dictionary.end(), [](auto entry) { std::cout << std::get<0>(std::get<1>(entry)) });*/ }