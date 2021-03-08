#include <>
#include <vector>
#include <string>
#include <map>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <buffer.h>
#include <filesystem.h>
#include "mc_pron.h"
struct mc_pron_and_char {
    mc_syllable pronunciation;
    std::string character; };
namespace std {
template <> struct hash<mc_syllable> {
    std::size_t operator()(const mc_syllable & x) const {
        return std::hash<std::string>{}(std::string{char(x.initial), char(x.final), char(x.四聲)}); } };
template <> struct hash<mc_pron_and_char> {
    std::size_t operator()(const mc_pron_and_char & x) const {
        std::size_t seed = 0;
        seed ^= std::hash<mc_syllable>{}(x.pronunciation) + 0xc6a4a7935bd1e995 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<std::string>{}(x.character) + 0xc6a4a7935bd1e995 + (seed << 6) + (seed >> 2);
        return seed; } }; }
int main() {
    std::vector<bsoc_entry> bsoc = deserialize<std::vector<bsoc_entry>>(file_to_string("BaxterSagartOC2015-10-13"));
    std::multimap<mc_pron_and_char, bsoc_entry> bsoc_by_字;
    std::transform(bsoc.begin(), bsoc.end(), std::inserter(bsoc_by_字, bsoc_by_字.begin()),
        [](bsoc_entry entry) { return std::make_pair(mc_pron_and_char{entry.mc_pron, entry.字}, entry); });
    std::vector<sbgy_entry> sbgy = deserialize<std::vector<sbgy_entry>>(file_to_string("sbgy"));
    std::multimap<mc_pron_and_char, sbgy_entry> sbgy_by_字;
    std::transform(sbgy.begin(), sbgy.end(), std::inserter(sbgy_by_字, sbgy_by_字.begin()),
        [](sbgy_entry entry) { return std::make_pair(mc_pron_and_char{entry.mc_pron, entry.字}, entry); });
    
}