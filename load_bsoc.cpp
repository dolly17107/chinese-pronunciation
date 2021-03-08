#include <cinttypes>
#include <string>
#include <regex>
#include <vector>
#include <unordered_map>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/optional.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/vector.hpp>
#include <xlnt/xlnt.hpp>
#include <buffer.h>
#include <filesystem.h>
#include "mc_pron.h"
void console_log(std::string const& str) { using namespace std; cout << str << endl; }
std::vector<morpheme_data> load_bsoc() {
    using namespace std;
    using namespace xlnt;
    unordered_map<string, uint8_t> mc_initial_baxter_sagart_index;
    for (uint32_t i = 0; i < mc_initial_data.size(); i += 1)
        mc_initial_baxter_sagart_index.insert(make_pair(mc_initial_data[i].baxter_sagart, i));
    unordered_multimap<string, uint8_t> mc_final_baxter_sagart_index;
    for (uint32_t i = 0; i < mc_final_data.size(); i += 1)
        mc_final_baxter_sagart_index.insert(make_pair(mc_final_data[i].baxter_sagart, i));
    workbook wb;
    wb.load("BaxterSagartOC2015-10-13.xlsx"s);
    worksheet ws = wb.active_sheet();
    regex mc_pron_format("\\((.*)- \\+ -(.*) (.)\\)"s);
    vector<morpheme_data> baxter_sagart_oc_dictionary;
    for (cell_vector row : ws.rows()) {
        if (row[0].value<string>() == "zi"s) continue;
        morpheme_data entry;
        morpheme descendant;
        entry.form.phoneme = row[4].value<string>();
        entry.form.grapheme = row[0].value<string>();
        entry.meaning = row[5].value<string>();
        descendant.grapheme = row[0].value<string>();
        descendant.phoneme = mc_syllable{};
        string pron = row[3].value<string>();
        if (pron == "(kw- + -ae A)"s) pron = "(k- + -wae A)"s; // D1111
        if (pron == "(l- + -ok )"s) pron = "(l- + -ok D)"s; // D2014
        if (pron == "(dz- + -rea A)"s) pron = "(dzr- + -ea A)"s; // D4912
        smatch mc_pron_matches;
        if (!regex_match(pron, mc_pron_matches, mc_pron_format, regex_constants::match_any))
            console_log(pron);
        if (mc_initial_baxter_sagart_index.count(mc_pron_matches[1].str()))
            std::get<mc_syllable>(descendant.phoneme).initial = mc_initial_baxter_sagart_index[mc_pron_matches[1].str()];
        else {
            console_log(mc_pron_matches[1].str());
            continue; }
        if (mc_final_baxter_sagart_index.count(mc_pron_matches[2].str())) {
            if (mc_final_baxter_sagart_index.count(mc_pron_matches[2].str()) == 1)
                std::get<mc_syllable>(descendant.phoneme).final = mc_final_baxter_sagart_index.find(mc_pron_matches[2].str())->second;
            else if (mc_final_baxter_sagart_index.count(mc_pron_matches[2].str()) == 2) {
                auto er = mc_final_baxter_sagart_index.equal_range(mc_pron_matches[2].str());
                std::array<std::uint8_t, 2> index;
                index[0] = (er.first++)->second;
                index[1] = (er.first++)->second;
                if (mc_final_data[index[0]].韻圖.等 == 5 && mc_final_data[index[1]].韻圖.等 == 3) { std::swap(index[0], index[1]); }
                if (!(mc_final_data[index[0]].韻圖.等 == 3 && mc_final_data[index[1]].韻圖.等 == 5)) {
                    console_log(mc_pron_matches[2].str());
                    continue; }
                if (mc_initial_data[std::get<mc_syllable>(descendant.phoneme).initial].αβ == αβ::αβ) { std::get<mc_syllable>(descendant.phoneme).final = index[1]; }
                else if (mc_initial_data[std::get<mc_syllable>(descendant.phoneme).initial].αβ) { std::get<mc_syllable>(descendant.phoneme).final = index[0]; }
                else if (descendant.grapheme == "地") { std::get<mc_syllable>(descendant.phoneme).final = 16; } // FIXME: use enum.
                else {
                    console_log(descendant.grapheme + " " + mc_pron_matches[2].str());
                    continue; } }
            else if (mc_pron_matches[2].str() == "in" || mc_pron_matches[2].str() == "it") {
                std::unordered_map<std::string, mc_韻部> 真臻_table = {{"筆", mc_韻部::眞}, {"邲", mc_韻部::眞}, {"柲", mc_韻部::眞}, {"豳", mc_韻部::眞}, {"瞋", mc_韻部::眞}, {"塵", mc_韻部::眞}, {"陳", mc_韻部::眞}, {"辰", mc_韻部::眞}, {"晨", mc_韻部::眞}, {"臣", mc_韻部::眞}, {"晨", mc_韻部::眞}, {"疾", mc_韻部::眞}, {"佶", mc_韻部::眞}, {"堲", mc_韻部::眞}, {"巾", mc_韻部::眞}, {"津", mc_韻部::眞}, {"堇", mc_韻部::眞}, {"殣", mc_韻部::眞}, {"盡", mc_韻部::眞}, {"盡", mc_韻部::眞}, {"燼", mc_韻部::眞}, {"僅", mc_韻部::眞}, {"墐", mc_韻部::眞}, {"墐", mc_韻部::眞}, {"饉", mc_韻部::眞}, {"進", mc_韻部::眞}, {"晉", mc_韻部::眞}, {"栗", mc_韻部::眞}, {"鄰", mc_韻部::眞}, {"鱗", mc_韻部::眞}, {"粦", mc_韻部::眞}, {"吝", mc_韻部::眞}, {"密", mc_韻部::眞}, {"緡", mc_韻部::眞}, {"緡", mc_韻部::眞}, {"珉", mc_韻部::眞}, {"旻", mc_韻部::眞}, {"閩", mc_韻部::眞}, {"閔", mc_韻部::眞}, {"憫", mc_韻部::眞}, {"敏", mc_韻部::眞}, {"䵒", mc_韻部::眞}, {"䵑", mc_韻部::眞}, {"昵", mc_韻部::眞}, {"暱", mc_韻部::眞}, {"貧", mc_韻部::眞}, {"七", mc_韻部::眞}, {"桼", mc_韻部::眞}, {"漆", mc_韻部::眞}, {"親", mc_韻部::眞}, {"秦", mc_韻部::眞}, {"堇", mc_韻部::眞}, {"矜", mc_韻部::眞}, {"螼", mc_韻部::眞}, {"螼", mc_韻部::眞}, {"人", mc_韻部::眞}, {"仁", mc_韻部::眞}, {"忍", mc_韻部::眞}, {"忍", mc_韻部::眞}, {"刃", mc_韻部::眞}, {"認", mc_韻部::眞}, {"軔", mc_韻部::眞}, {"日", mc_韻部::眞}, {"衵", mc_韻部::眞}, {"瑟", mc_韻部::臻}, {"兟", mc_韻部::臻}, {"莘", mc_韻部::臻}, {"詵", mc_韻部::臻}, {"紳", mc_韻部::眞}, {"申", mc_韻部::眞}, {"伸", mc_韻部::眞}, {"呻", mc_韻部::眞}, {"身", mc_韻部::眞}, {"娠", mc_韻部::眞}, {"娠", mc_韻部::眞}, {"神", mc_韻部::眞}, {"哂", mc_韻部::眞}, {"腎", mc_韻部::眞}, {"蜃", mc_韻部::眞}, {"慎", mc_韻部::眞}, {"蝨", mc_韻部::臻}, {"失", mc_韻部::眞}, {"實", mc_韻部::眞}, {"室", mc_韻部::眞}, {"悉", mc_韻部::眞}, {"膝", mc_韻部::眞}, {"蟋", mc_韻部::眞}, {"辛", mc_韻部::眞}, {"薪", mc_韻部::眞}, {"新", mc_韻部::眞}, {"辛", mc_韻部::眞}, {"囟", mc_韻部::眞}, {"信", mc_韻部::眞}, {"釁", mc_韻部::眞}, {"衅", mc_韻部::眞}, {"訊", mc_韻部::眞}, {"乙", mc_韻部::眞}, {"溢", mc_韻部::眞}, {"佾", mc_韻部::眞}, {"逸", mc_韻部::眞}, {"鎰", mc_韻部::眞}, {"駰", mc_韻部::眞}, {"誾", mc_韻部::眞}, {"銀", mc_韻部::眞}, {"夤", mc_韻部::眞}, {"寅", mc_韻部::眞}, {"蚓", mc_韻部::眞}, {"螾", mc_韻部::眞}, {"引", mc_韻部::眞}, {"朄", mc_韻部::眞}, {"引", mc_韻部::眞}, {"胤", mc_韻部::眞}, {"珍", mc_韻部::眞}, {"蓁", mc_韻部::臻}, {"榛", mc_韻部::臻}, {"甄", mc_韻部::眞}, {"真", mc_韻部::眞}, {"縝", mc_韻部::眞}, {"振", mc_韻部::眞}, {"診", mc_韻部::眞}, {"辴", mc_韻部::眞}, {"㐱", mc_韻部::眞}, {"稹", mc_韻部::眞}, {"鬒", mc_韻部::眞}, {"畛", mc_韻部::眞}, {"袗", mc_韻部::眞}, {"軫", mc_韻部::眞}, {"診", mc_韻部::眞}, {"陳", mc_韻部::眞}, {"陣", mc_韻部::眞}, {"疹", mc_韻部::眞}, {"鎮", mc_韻部::眞}, {"振", mc_韻部::眞}, {"震", mc_韻部::眞}, {"窒", mc_韻部::眞}, {"楖", mc_韻部::臻}, {"質", mc_韻部::眞}};
                if (真臻_table.at(descendant.grapheme) == mc_韻部::眞) {
                    if (mc_initial_data[std::get<mc_syllable>(descendant.phoneme).initial].αβ == αβ::αβ) {
                        if (mc_pron_matches[2].str() == "in") { std::get<mc_syllable>(descendant.phoneme).final = 48; } // FIXME: use enum.
                        else if (mc_pron_matches[2].str() == "it") { std::get<mc_syllable>(descendant.phoneme).final = 49; } }
                    else if (mc_initial_data[std::get<mc_syllable>(descendant.phoneme).initial].αβ) {
                        if (mc_pron_matches[2].str() == "in") { std::get<mc_syllable>(descendant.phoneme).final = 52; }
                        else if (mc_pron_matches[2].str() == "it") { std::get<mc_syllable>(descendant.phoneme).final = 53; } }
                    else {
                        console_log(mc_pron_matches[2].str());
                        continue; } }
                else if (真臻_table.at(descendant.grapheme) == mc_韻部::臻) {
                    if (mc_pron_matches[2].str() == "in") { std::get<mc_syllable>(descendant.phoneme).final = 60; }
                    else if (mc_pron_matches[2].str() == "it") { std::get<mc_syllable>(descendant.phoneme).final = 61; } } }
            else {
                console_log(mc_pron_matches[2].str());
                continue; } }
        else {
            console_log(mc_pron_matches[2].str());
            continue; }
        if (mc_pron_matches[3].str() == "A"s)
            std::get<mc_syllable>(descendant.phoneme).四聲 = 0;
        else if (mc_pron_matches[3].str() == "B"s)
            std::get<mc_syllable>(descendant.phoneme).四聲 = 1;
        else if (mc_pron_matches[3].str() == "C"s)
            std::get<mc_syllable>(descendant.phoneme).四聲 = 2;
        else if (mc_pron_matches[3].str() == "D"s)
            std::get<mc_syllable>(descendant.phoneme).四聲 = 3;
        else {
            console_log(mc_pron_matches[3].str());
            continue; }
        entry.descendants.push_back(descendant);
        baxter_sagart_oc_dictionary.push_back(entry); }
    return baxter_sagart_oc_dictionary; }
int32_t main() {
    buffer_to_file(serialize(load_bsoc()), "BaxterSagartOC2015-10-13"s); }