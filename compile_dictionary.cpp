#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/optional.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/vector.hpp>
#include <buffer.h>
#include <filesystem.h>
#include "mc_pron.h"
int main() {
    chinese_dictionary dict;
    std::vector<morpheme_data> bsoc = deserialize<std::vector<morpheme_data>>(file_to_string("BaxterSagartOC2015-10-13"));
    std::vector<morpheme_data> sbgy = deserialize<std::vector<morpheme_data>>(file_to_string("sbgy"));
    std::unordered_map<morpheme, morpheme_data *> sbgy_by_morpheme;
    std::transform(sbgy.begin(), sbgy.end(), std::inserter(sbgy_by_morpheme, sbgy_by_morpheme.begin()), [](morpheme_data & m) { return std::make_pair(m.form, &m); });
    std::for_each(bsoc.begin(), bsoc.end(), [&sbgy_by_morpheme](morpheme_data m) {
        if (sbgy_by_morpheme.count(m.descendants[0])) {
            sbgy_by_morpheme[m.descendants[0]]->ancestors.push_back(m.form); } });
    buffer_to_file(serialize(chinese_dictionary{bsoc, sbgy}), "dictionary"s); }