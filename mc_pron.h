#include <cinttypes>
#include <array>
#include <optional>
#include <string>
#include <regex>
using namespace std::literals::string_literals;
struct lattice_1 {
    std::string elsewhere;
    std::optional<std::string> triggered;
    lattice_1(std::string value) { elsewhere = value; }
    lattice_1(std::string value, std::string value0) { elsewhere = value; triggered = value0; } };
struct mc_initial_datus {
    std::string name;
    std::string baxter_sagart;
    lattice_1 金陵;
    std::string 鄴;
    lattice_1 中唐長安; };
static std::vector<mc_initial_datus> const mc_initial_data {
    { "幫"s, "p"s, { "p"s, "ɸ"s }, "p"s, { "p"s, "f"s } },
    { "滂"s, "ph"s, { "ph"s, "ɸh"s }, "ph"s, { "ph"s, "f"s } },
    { "並"s, "b"s, { "b"s, "β"s }, "b"s, { "b̤"s, "v̤"s } },
    { "明"s, "m"s, "m"s, "m"s, { "mb"s, "w̃"s } },
    { "端"s, "t"s, "t"s, "t"s, "t"s },
    { "透"s, "th"s, "th"s, "th"s, "th"s },
    { "定"s, "d"s, "d"s, "d"s, "d̤"s },
    { "泥"s, "n"s, "n"s, "n"s, "nd"s },
    { "來"s, "l"s, "l"s, "l"s, "l"s },
    { "知"s, "tr"s, "t"s, "ʈ"s, "ʈ"s },
    { "徹"s, "trh"s, "th"s, "ʈh"s, "ʈh"s },
    { "澄"s, "dr"s, "d"s, "ɖ"s, "ɖ̤"s },
    { "娘"s, "nr"s, "n"s, "ɳ"s, "ɳɖ"s },
    { "精"s, "ts"s, "tz"s, "tz"s, "tz"s },
    { "清"s, "tsh"s, "ts"s, "ts"s, "ts"s },
    { "從"s, "dz"s, "dz"s, "dz"s, "d̤z"s },
    { "心"s, "s"s, "s"s, "s"s, "s"s },
    { "邪"s, "z"s, "dz"s, "z"s, "z̤"s },
    { "莊"s, "tsr"s, "ʈʐ"s, "ʈʐ"s, "ʈʐ"s },
    { "初"s, "tsrh"s, "ʈʂ"s, "ʈʂ"s, "ʈʂ"s },
    { "崇"s, "dzr"s, "ɖʐ"s, "ɖʐ"s, "ɖ̤ʐ"s },
    { "生"s, "sr"s, "ʂ"s, "ʂ"s, "ʂ"s },
    { "崇"s, "zr"s, "ʐ"s, "ʐ"s, "ɖ̤ʐ"s },
    { "章"s, "tsy"s, "cʑ"s, "cʑ"s, "cʑ"s },
    { "昌"s, "tsyh"s, "cɕ"s, "cɕ"s, "cɕ"s },
    { "禪"s, "dzy"s, "ɟʑ"s, "ɟʑ"s, "ɟ̤ʑ"s },
    { "日"s, "ny"s, "ɲ"s, "ɲ"s, "ɲɟʑ"s },
    { "書"s, "sy"s, "ɕ"s, "ɕ"s, "ɕ"s },
    { "船"s, "zy"s, "ɟʑ"s, "ʑ"s, "ʑ̤"s },
    { "以"s, "y"s, "j"s, "j"s, "j"s },
    { "見"s, "k"s, "k"s, "k"s, "k"s },
    { "溪"s, "kh"s, "kh"s, "kh"s, "kh"s },
    { "群"s, "g"s, "g"s, "g"s, "g̤"s },
    { "疑"s, "ng"s, "ŋ"s, "ŋ"s, "ŋg"s },
    { "影"s, "'"s, "ʔ"s, "ʔ"s, "ʔ"s },
    { "曉"s, "x"s, "h"s, "x"s, "x"s },
    { "匣"s, "h"s, "ɦ"s, "ɣ"s, "ɣ̤"s },
    { "云"s, "hj"s, "ɦ"s, "w"s, "ɦ"s } };
// 矣 hj ɦ ʜ ɦ
enum class mc_攝 {
    通, 江, 止, 遇, 蟹, 臻, 山, 效, 果, 假, 宕, 梗, 流, 深, 咸, 曾 };
enum class mc_韻部 {
    東A, 東B, 冬, 鍾, 江, 支, 脂, 之, 微, 魚, 虞, 模, 泰, 齊, 祭, 佳, 皆, 夬, 灰, 咍, 廢, 眞, 臻, 文, 殷, 元, 魂, 痕, 寒, 刪, 山, 先, 仙, 蕭, 宵, 肴, 豪, 歌A, 歌B, 麻A, 麻B, 覃, 談, 陽, 唐, 庚A, 庚B, 耕, 清, 青, 尤, 侯, 幽, 侵, 鹽, 添, 蒸, 登, 咸, 銜, 嚴, 凡 };
struct mc_韻部_datus {
    std::string name;
    mc_攝 攝;
    std::string 金陵;
    std::string 鄴; };
std::vector<mc_韻部_datus> mc_韻部_data {
    { "東A"s, mc_攝::通, "ʉŋ"s, "ʉŋ"s },
    { "東B"s, mc_攝::通, "yŋ"s, "yŋ"s },
    { "冬"s, mc_攝::通, "uŋ"s, "əŋ"s },
    { "鍾"s, mc_攝::通, "øŋ"s, "øŋ"s },
    { "江"s, mc_攝::江, "ɔŋ"s, "ɔŋ"s },
    { "支"s, mc_攝::止, "e"s, "i"s },
    { "脂"s, mc_攝::止, "i, yj"s, "i"s },
    { "之"s, mc_攝::止, "i"s, "e"s },
    { "微"s, mc_攝::止, "yj"s, "yj"s },
    { "魚"s, mc_攝::遇, "œ"s, "ø"s },
    { "虞"s, mc_攝::遇, "ø"s, "ø"s },
    { "模"s, mc_攝::遇, "u"s, "ə"s },
    { "泰"s, mc_攝::蟹, "ɑj"s, "ɐj"s },
    { "齊"s, mc_攝::蟹, "ɐj"s, "ɪj"s },
    { "祭"s, mc_攝::蟹, "ej"s, "ej"s },
    { "佳"s, mc_攝::蟹, "ɛ"s, "ɛj"s },
    { "皆"s, mc_攝::蟹, "ɑj"s, "ɛj"s },
    { "夬"s, mc_攝::蟹, "æ"s, "ɛj"s },
    { "灰"s, mc_攝::蟹, "ʏj"s, "ʏj"s },
    { "咍"s, mc_攝::蟹, "əj"s, "əj"s },
    { "廢"s, mc_攝::蟹, "øj"s, "øj"s },
    { "眞"s, mc_攝::臻, "in"s, "in"s },
    { "臻"s, mc_攝::臻, "in"s, "un"s },
    { "文"s, mc_攝::臻, "yn"s, "yn"s },
    { "殷"s, mc_攝::臻, "in"s, "yn"s },
    { "元"s, mc_攝::山, "øn"s, "øn"s },
    { "魂"s, mc_攝::臻, "ʏn"s, "ʏn"s },
    { "痕"s, mc_攝::臻, "ən"s, "ən"s },
    { "寒"s, mc_攝::山, "ɑn"s, "ɐn"s },
    { "刪"s, mc_攝::山, "æn"s, "ɛn"s },
    { "山"s, mc_攝::山, "ɛn"s, "ɛn"s },
    { "先"s, mc_攝::山, "ɪn"s, "ɪn"s },
    { "仙"s, mc_攝::山, "en"s, "en"s },
    { "蕭"s, mc_攝::效, "ɪw"s, "ɪw"s },
    { "宵"s, mc_攝::效, "ew"s, "ew"s },
    { "肴"s, mc_攝::效, "ɛw"s, "ɛw"s },
    { "豪"s, mc_攝::效, "ɑw"s, "ɐw"s },
    { "歌A"s, mc_攝::果, "ɑ"s, "ɐ"s },
    { "歌B"s, mc_攝::果, "ɑ"s, "œ"s },
    { "麻A"s, mc_攝::假, "æ"s, "ɛ"s },
    { "麻B"s, mc_攝::假, "jæ"s, "jɛ"s },
    { "覃"s, mc_攝::咸, "ɔm"s, "ɔm"s },
    { "談"s, mc_攝::咸, "ɑm"s, "ɐm"s },
    { "陽"s, mc_攝::宕, "œŋ"s, "œŋ"s },
    { "唐"s, mc_攝::宕, "ɑŋ"s, "ɐŋ"s },
    { "庚A"s, mc_攝::梗, "æŋ"s, "ɛŋ"s },
    { "庚B"s, mc_攝::梗, "eŋ"s, "jɛŋ"s },
    { "耕"s, mc_攝::梗, "ɛŋ"s, "ɛŋ"s },
    { "清"s, mc_攝::梗, "eŋ"s, "eŋ"s },
    { "青"s, mc_攝::梗, "ɪŋ"s, "ɪŋ"s },
    { "尤"s, mc_攝::流, "y"s, "y"s },
    { "侯"s, mc_攝::流, "ʉ"s, "u"s },
    { "幽"s, mc_攝::流, "iw"s, "iw"s },
    { "侵"s, mc_攝::深, "im"s, "im"s },
    { "鹽"s, mc_攝::咸, "em"s, "em"s },
    { "添"s, mc_攝::咸, "ɪm"s, "ɪm"s },
    { "蒸"s, mc_攝::曾, "iŋ"s, "iŋ"s },
    { "登"s, mc_攝::曾, "oŋ"s, "oŋ"s },
    { "咸"s, mc_攝::咸, "ɛm"s, "ɛm"s },
    { "銜"s, mc_攝::咸, "æm"s, "ɛm"s },
    { "嚴"s, mc_攝::咸, "øm"s, "øm"s },
    { "凡"s, mc_攝::咸, "œm"s, "øm"s } };
struct mc_final {
    mc_韻部 韻部;
    uint8_t 等;
    uint8_t 合;
    uint8_t 去; };
struct mc_final_prelmc_outcome {
    std::string elsewhere;
    std::string m;
    std::optional<std::string> F; };
struct mc_final_datus {
    mc_final final;
    std::string baxter_sagart;
    mc_final_prelmc_outcome prelmc; };
static std::vector<mc_final_datus> const mc_final_data {
    { { mc_韻部::東A, 1, 0, 0 }, "uwng"s, { "ɤwŋ"s, "oŋ"s } },
    { { mc_韻部::東A, 1, 0, 1 }, "uwk"s, { "ɤwk"s, "ok"s } },
    { { mc_韻部::東B, 3, 0, 0 }, "juwng"s, { "ɯwŋ"s, "ɤwŋ"s, "ɤwŋ/uŋ competing"s } },
    { { mc_韻部::東B, 3, 0, 1 }, "juwk"s, { "ɯwk"s, "ɤwk"s, "ɤwk/uk competing"s } },
    { { mc_韻部::冬, 1, 1, 0 }, "owng"s, { "ɤwŋ"s, "oŋ"s } },
    { { mc_韻部::冬, 1, 1, 1 }, "owk"s, { "ɤwk"s, "ok"s } },
    { { mc_韻部::鍾, 3, 1, 0 }, "jowng"s, { "wɯɤwŋ"s, "wɯɤwŋ"s, "ɤwŋ"s } },
    { { mc_韻部::鍾, 3, 1, 1 }, "jowk"s, { "wɯɤwk"s, "wɯɤwk"s, "ɤwk"s } },
    { { mc_韻部::江, 2, 0, 0 }, "aewng"s, { "æwŋ"s, "æwŋ"s } },
    { { mc_韻部::江, 2, 0, 1 }, "aewk"s, { "æwk"s, "æwk"s } },
    { { mc_韻部::支, 3, 0, 0 }, "je"s, { "ɯj"s, "ɯj"s } },
    { { mc_韻部::支, 3, 1, 0 }, "jwe"s, { "wɯj"s, "wɯj"s } },
    { { mc_韻部::支, 6, 0, 0 }, "jie"s, { "ij"s, "ij"s } },
    { { mc_韻部::支, 6, 1, 0 }, "jwie"s, { "wij"s, "wij"s } },
    { { mc_韻部::脂, 3, 0, 0 }, "ij"s, { "ɯj"s, "ɯj"s } },
    { { mc_韻部::脂, 3, 1, 0 }, "wij"s, { "wɯj"s, "wɯj"s } },
    { { mc_韻部::脂, 6, 0, 0 }, "jij"s, { "ij"s, "ij"s } },
    { { mc_韻部::脂, 6, 1, 0 }, "jwij"s, { "wij"s, "wij"s } },
    { { mc_韻部::之, 3, 0, 0 }, "i"s, { "ɯj"s, "ɯj"s } },
    { { mc_韻部::微, 3, 0, 0 }, "j+j"s, { "ɯj"s, "ɯj"s, "ɤj"s } },
    { { mc_韻部::微, 3, 1, 0 }, "jw+j"s, { "wɯj"s, "wɯj"s } },
    { { mc_韻部::魚, 3, 0, 0 }, "jo"s, { "ɯɤ"s, "ɯɤ"s, "ɯɤ"s } },
    { { mc_韻部::虞, 3, 1, 0 }, "ju"s, { "u"s, "u"s, "u"s } },
    { { mc_韻部::模, 1, 1, 0 }, "u"s, { "o"s, "o"s } },
    { { mc_韻部::泰, 1, 0, 0 }, "aj"s, { "ɑj"s, "ɑj"s } },
    { { mc_韻部::泰, 1, 1, 0 }, "waj"s, { "wɑj"s, "wɑj"s } },
    { { mc_韻部::齊, 4, 0, 0 }, "ej"s, { "iej"s, "iej"s } },
    { { mc_韻部::齊, 4, 1, 0 }, "wej"s, { "wiej"s, "wiej"s } },
    { { mc_韻部::祭, 3, 0, 0 }, "jej"s, { "ej"s, "ej"s } },
    { { mc_韻部::祭, 3, 1, 0 }, "jwej"s, { "wej"s, "wej"s } },
    { { mc_韻部::祭, 6, 0, 0 }, "jiej"s, { "iej"s, "iej"s } },
    { { mc_韻部::祭, 6, 1, 0 }, "jwiej"s, { "wiej"s, "wiej"s } },
    { { mc_韻部::佳, 2, 0, 0 }, "ea"s, { "æ/æj dialectal mixture"s, "æ/æj dialectal mixture"s } },
    { { mc_韻部::佳, 2, 1, 0 }, "wea"s, { "wæ/wæj dialectal mixture"s, "wæ/wæj dialectal mixture"s } },
    { { mc_韻部::皆, 2, 0, 0 }, "eaj"s, { "æj"s, "æj"s } },
    { { mc_韻部::皆, 2, 1, 0 }, "weaj"s, { "wæj"s, "wæj"s } },
    { { mc_韻部::夬, 2, 0, 0 }, "aej"s, { "æj"s, "æj"s } },
    { { mc_韻部::夬, 2, 1, 0 }, "waej"s, { "wæj"s, "wæj"s } },
    { { mc_韻部::灰, 1, 1, 0 }, "woj"s, { "wɑj"s, "wɑj"s } },
    { { mc_韻部::咍, 1, 0, 0 }, "oj"s, { "ɑj"s, "ɑj"s } },
    { { mc_韻部::廢, 3, 0, 0 }, "joj"s, { "ej"s, "ej"s, "ej"s } },
    { { mc_韻部::廢, 3, 1, 0 }, "jwoj"s, { "wej"s, "wej"s } },
    { { mc_韻部::眞, 3, 0, 0 }, "in"s, { "ɯn"s, "ɯn"s } },
    { { mc_韻部::眞, 3, 0, 1 }, "it"s, { "ɯt"s, "ɯt"s } },
    { { mc_韻部::眞, 6, 0, 0 }, "jin"s, { "in"s, "in"s } },
    { { mc_韻部::眞, 6, 0, 1 }, "jit"s, { "it"s, "it"s } },
    { { mc_韻部::眞, 6, 1, 0 }, "jwin"s, { "win"s, "win"s } },
    { { mc_韻部::眞, 6, 1, 1 }, "jwit"s, { "wit"s, "wit"s } },
    { { mc_韻部::臻, 3, 1, 0 }, "win"s, { "wɯn"s, "wɯn"s } },
    { { mc_韻部::臻, 3, 1, 1 }, "wit"s, { "wɯt"s, "wɯt"s } },
    { { mc_韻部::文, 3, 1, 0 }, "jun"s, { "wɯn"s, "wɯn"s, "wɯn"s } },
    { { mc_韻部::文, 3, 1, 1 }, "jut"s, { "wɯt"s, "wɯt"s, "wɯt"s } },
    { { mc_韻部::殷, 3, 0, 0 }, "j+n"s, { "ɯn"s, "ɯn"s } },
    { { mc_韻部::殷, 3, 0, 1 }, "j+t"s, { "ɯt"s, "ɯt"s } },
    { { mc_韻部::元, 3, 0, 0 }, "jon"s, { "en"s, "en"s, "æn"s } },
    { { mc_韻部::元, 3, 0, 1 }, "jot"s, { "et"s, "et"s, "æt"s } },
    { { mc_韻部::元, 3, 1, 0 }, "jwon"s, { "wen"s, "wen"s } },
    { { mc_韻部::元, 3, 1, 1 }, "jwot"s, { "wet"s, "wet"s } },
    { { mc_韻部::魂, 1, 1, 0 }, "won"s, { "wɤn"s, "wɤn"s } },
    { { mc_韻部::魂, 1, 1, 1 }, "wot"s, { "wɤt"s, "wɤt"s } },
    { { mc_韻部::痕, 1, 0, 0 }, "on"s, { "ɤn"s, "ɤn"s } },
    { { mc_韻部::痕, 1, 0, 1 }, "ot"s, { "ɤt"s, "ɤt"s } },
    { { mc_韻部::寒, 1, 0, 0 }, "an"s, { "ɑn"s, "ɑn"s } },
    { { mc_韻部::寒, 1, 0, 1 }, "at"s, { "ɑt"s, "ɑt"s } },
    { { mc_韻部::寒, 1, 1, 0 }, "wan"s, { "wɑn"s, "wɑn"s } },
    { { mc_韻部::寒, 1, 1, 1 }, "wat"s, { "wɑt"s, "wɑt"s } },
    { { mc_韻部::刪, 2, 0, 0 }, "aen"s, { "æn"s, "æn"s } },
    { { mc_韻部::刪, 2, 0, 1 }, "aet"s, { "æt"s, "æt"s } },
    { { mc_韻部::刪, 2, 1, 0 }, "waen"s, { "wæn"s, "wæn"s } },
    { { mc_韻部::刪, 2, 1, 1 }, "waet"s, { "wæt"s, "wæt"s } },
    { { mc_韻部::山, 2, 0, 0 }, "ean"s, { "æn"s, "æn"s } },
    { { mc_韻部::山, 2, 0, 1 }, "eat"s, { "æt"s, "æt"s } },
    { { mc_韻部::山, 2, 1, 0 }, "wean"s, { "wæn"s, "wæn"s } },
    { { mc_韻部::山, 2, 1, 1 }, "weat"s, { "wæt"s, "wæt"s } },
    { { mc_韻部::先, 4, 0, 0 }, "en"s, { "ien"s, "ien"s } },
    { { mc_韻部::先, 4, 0, 1 }, "et"s, { "iet"s, "iet"s } },
    { { mc_韻部::先, 4, 1, 0 }, "wen"s, { "wien"s, "wien"s } },
    { { mc_韻部::先, 4, 1, 1 }, "wet"s, { "wiet"s, "wiet"s } },
    { { mc_韻部::仙, 6, 0, 0 }, "jien"s, { "ien"s, "ien"s } },
    { { mc_韻部::仙, 6, 0, 1 }, "jiet"s, { "iet"s, "iet"s } },
    { { mc_韻部::仙, 6, 1, 0 }, "jwien"s, { "wien"s, "wien"s } },
    { { mc_韻部::仙, 6, 1, 1 }, "jwiet"s, { "wiet"s, "wiet"s } },
    { { mc_韻部::仙, 3, 0, 0 }, "jen"s, { "en"s, "en"s } },
    { { mc_韻部::仙, 3, 0, 1 }, "jet"s, { "et"s, "et"s } },
    { { mc_韻部::仙, 3, 1, 0 }, "jwen"s, { "wen"s, "wen"s } },
    { { mc_韻部::仙, 3, 1, 1 }, "jwet"s, { "wet"s, "wet"s } },
    { { mc_韻部::蕭, 4, 0, 0 }, "ew"s, { "iew"s, "iew"s } },
    { { mc_韻部::宵, 3, 0, 0 }, "jew"s, { "ew"s, "ew"s } },
    { { mc_韻部::宵, 6, 1, 0 }, "jiew"s, { "iew"s, "iew"s } },
    { { mc_韻部::肴, 2, 0, 0 }, "aew"s, { "æw"s, "æw"s } },
    { { mc_韻部::豪, 1, 0, 0 }, "aw"s, { "ɑw"s, "ɑw"s } },
    { { mc_韻部::歌A, 1, 0, 0 }, "a"s, { "ɑ"s, "ɑ"s } },
    { { mc_韻部::歌A, 1, 1, 0 }, "wa"s, { "wɑ"s, "wɑ"s } },
    { { mc_韻部::歌B, 3, 1, 0 }, "jwa"s, { "wɯɑ"s, "wɯɑ"s } },
    { { mc_韻部::麻A, 2, 0, 0 }, "ae"s, { "æ"s, "æ"s } },
    { { mc_韻部::麻A, 2, 1, 0 }, "wae"s, { "wæ"s, "wæ"s } },
    { { mc_韻部::麻B, 3, 0, 0 }, "jae"s, { "iæ"s, "iæ"s } },
    { { mc_韻部::覃, 1, 0, 0 }, "om"s, { "ɑm"s, "ɑm"s } },
    { { mc_韻部::覃, 1, 0, 1 }, "op"s, { "ɑp"s, "ɑp"s } },
    { { mc_韻部::談, 1, 1, 0 }, "am"s, { "ɑm"s, "ɑm"s } },
    { { mc_韻部::談, 1, 1, 1 }, "ap"s, { "ɑp"s, "ɑp"s } },
    { { mc_韻部::陽, 3, 0, 0 }, "jang"s, { "ɯɑ̃"s, "ɯɑ̃"s, "ɑ̃"s } },
    { { mc_韻部::陽, 3, 0, 1 }, "jak"s, { "ɯɑk"s, "ɯɑk"s, "ɑk"s } },
    { { mc_韻部::陽, 3, 1, 0 }, "jwang"s, { "wɯɑ̃"s, "wɯɑ̃"s } },
    { { mc_韻部::陽, 3, 1, 1 }, "jwak"s, { "wɯɑk"s, "wɯɑk"s } },
    { { mc_韻部::唐, 1, 0, 0 }, "ang"s, { "ɑ̃"s, "ɑ̃"s } },
    { { mc_韻部::唐, 1, 0, 1 }, "ak"s, { "ɑk"s, "ɑk"s } },
    { { mc_韻部::唐, 1, 1, 0 }, "wang"s, { "wɑ̃"s, "wɑ̃"s } },
    { { mc_韻部::唐, 1, 1, 1 }, "wak"s, { "wɑk"s, "wɑk"s } },
    { { mc_韻部::庚A, 2, 0, 0 }, "aeng"s, { "æ̃j"s, "æ̃j"s } },
    { { mc_韻部::庚A, 2, 0, 1 }, "aek"s, { "æc"s, "æc"s } },
    { { mc_韻部::庚A, 2, 1, 0 }, "waeng"s, { "wæ̃j"s, "wæ̃j"s } },
    { { mc_韻部::庚A, 2, 1, 1 }, "waek"s, { "wæc"s, "wæc"s } },
    { { mc_韻部::庚B, 3, 0, 0 }, "jaeng"s, { "ẽj"s, "ẽj"s } },
    { { mc_韻部::庚B, 3, 0, 1 }, "jaek"s, { "ec"s, "ec"s } },
    { { mc_韻部::庚B, 3, 1, 0 }, "jwaeng"s, { "wẽj"s, "wẽj"s } },
    { { mc_韻部::庚B, 3, 1, 1 }, "jwaek"s, { "wec"s, "wec"s } },
    { { mc_韻部::耕, 2, 0, 0 }, "eang"s, { "æ̃j"s, "æ̃j"s } },
    { { mc_韻部::耕, 2, 0, 1 }, "eak"s, { "æc"s, "æc"s } },
    { { mc_韻部::耕, 2, 1, 0 }, "weang"s, { "wæ̃j"s, "wæ̃j"s } },
    { { mc_韻部::耕, 2, 1, 1 }, "weak"s, { "wæc"s, "wæc"s } },
    { { mc_韻部::清, 3, 0, 0 }, "jeng"s, { "ẽj"s, "ẽj"s } },
    { { mc_韻部::清, 3, 0, 1 }, "jek"s, { "ec"s, "ec"s } },
    { { mc_韻部::清, 3, 1, 0 }, "jweng"s, { "wẽj"s, "wẽj"s } },
    { { mc_韻部::清, 3, 1, 1 }, "jwek"s, { "wec"s, "wec"s } },
    { { mc_韻部::清, 6, 0, 0 }, "jieng"s, { "iẽj"s, "iẽj"s } },
    { { mc_韻部::清, 6, 0, 1 }, "jiek"s, { "iec"s, "iec"s } },
    { { mc_韻部::清, 6, 1, 0 }, "jwieng"s, { "wiẽj"s, "wiẽj"s } },
    { { mc_韻部::清, 6, 1, 1 }, "jwiek"s, { "wiec"s, "wiec"s } },
    { { mc_韻部::青, 4, 0, 0 }, "eng"s, { "iẽj"s, "iẽj"s } },
    { { mc_韻部::青, 4, 0, 1 }, "ek"s, { "iec"s, "iec"s } },
    { { mc_韻部::青, 4, 1, 0 }, "weng"s, { "wiẽj"s, "wiẽj"s } },
    { { mc_韻部::青, 4, 1, 1 }, "wek"s, { "wiec"s, "wiec"s } },
    { { mc_韻部::尤, 3, 0, 0 }, "juw"s, { "ɯw"s, "ɤw"s, "ɤw/u competing"s } },
    { { mc_韻部::尤, 6, 0, 0 }, "jiuw"s, { "iw"s, "iw"s, "iw"s } },
    { { mc_韻部::侯, 1, 0, 0 }, "uw"s, { "ɤw"s, "o"s } },
    { { mc_韻部::幽, 6, 0, 0 }, "jiw"s, { "iw"s, "iw"s } },
    { { mc_韻部::侵, 3, 1, 0 }, "im"s, { "ɯm"s, "ɯm"s } },
    { { mc_韻部::侵, 3, 1, 1 }, "ip"s, { "ɯp"s, "ɯp"s } },
    { { mc_韻部::侵, 6, 1, 0 }, "jim"s, { "im"s, "im"s } },
    { { mc_韻部::侵, 6, 1, 1 }, "jip"s, { "ip"s, "ip"s } },
    { { mc_韻部::鹽, 3, 0, 0 }, "jem"s, { "em"s, "em"s } },
    { { mc_韻部::鹽, 3, 0, 1 }, "jep"s, { "ep"s, "ep"s } },
    { { mc_韻部::鹽, 6, 1, 0 }, "jiem"s, { "iem"s, "iem"s } },
    { { mc_韻部::鹽, 6, 1, 1 }, "jiep"s, { "iep"s, "iep"s } },
    { { mc_韻部::添, 4, 0, 0 }, "em"s, { "iem"s, "iem"s } },
    { { mc_韻部::添, 4, 0, 1 }, "ep"s, { "iep"s, "iep"s } },
    { { mc_韻部::蒸, 3, 0, 0 }, "ing"s, { "ɯɤŋ"s, "ɯɤŋ"s } },
    { { mc_韻部::蒸, 3, 0, 1 }, "ik"s, { "ɯɤk"s, "ɯɤk"s } },
    { { mc_韻部::蒸, 3, 1, 0 }, "wing"s, { "wɯɤŋ"s, "wɯɤŋ"s } },
    { { mc_韻部::蒸, 3, 1, 1 }, "wik"s, { "wɯɤk"s, "wɯɤk"s } },
    { { mc_韻部::登, 1, 0, 0 }, "ong"s, { "ɤŋ"s, "ɤŋ"s } },
    { { mc_韻部::登, 1, 0, 1 }, "ok"s, { "ɤk"s, "ɤk"s } },
    { { mc_韻部::登, 1, 1, 0 }, "wong"s, { "wɤŋ"s, "wɤŋ"s } },
    { { mc_韻部::登, 1, 1, 1 }, "wok"s, { "wɤk"s, "wɤk"s } },
    { { mc_韻部::咸, 2, 0, 0 }, "eam"s, { "æm"s, "æn"s } },
    { { mc_韻部::咸, 2, 0, 1 }, "eap"s, { "æp"s, "æp"s } },
    { { mc_韻部::銜, 2, 1, 0 }, "aem"s, { "æm"s, "æn"s } },
    { { mc_韻部::銜, 2, 1, 1 }, "aep"s, { "æp"s, "æp"s } },
    { { mc_韻部::嚴, 3, 1, 0 }, "jaem"s, { "em"s, "em"s, "æm"s } },
    { { mc_韻部::嚴, 3, 1, 1 }, "jaep"s, { "ep"s, "ep"s, "æp"s } },
    { { mc_韻部::凡, 3, 1, 0 }, "jom"s, { "em"s, "em"s, "æm"s } },
    { { mc_韻部::凡, 3, 1, 1 }, "jop"s, { "ep"s, "ep"s, "æp"s } }, };
std::array<std::string, 4> 四聲_diacritic{""s, "\xcc\x81"s, "\xcc\x80"s, ""s};
struct baxter_sagart_oc_entry {
    std::string gloss;
    std::string oc_str;
    uint8_t mc_initial;
    uint8_t mc_final;
    uint8_t mc_四聲;
    std::string 字;
    template<class archive>
    void serialize(archive& ar) {
        ar(gloss);
        ar(oc_str);
        ar(mc_initial);
        ar(mc_final);
        ar(mc_四聲);
        ar(字); } };
std::string to_入聲(std::string fina) {
    using namespace std;
    if ("m"s == fina.substr(fina.size() + -"m"s.size(), "m"s.size())) {
        return fina.replace(fina.size() + -"m"s.size(), "m"s.size(), "p"s); }
    if ("n"s == fina.substr(fina.size() + -"n"s.size(), "n"s.size())) {
        return fina.replace(fina.size() + -"n"s.size(), "n"s.size(), "t"s); }
    if ("ŋ"s == fina.substr(fina.size() + -"ŋ"s.size(), "ŋ"s.size())) {
        return fina.replace(fina.size() + -"ŋ"s.size(), "ŋ"s.size(), "k"s); }
    return "???"s; }
std::string add_diacritic(std::string segmental, std::string diacritic) {
    std::regex vowel("ɔ|ɐ|œ|ɛ|o|ʏ|ə|ø|ɪ|e|u|ʉ|y|i");
    return std::regex_replace(segmental, vowel, "$0" + diacritic); }
std::string predict_鄴(uint8_t init, uint8_t fina, uint8_t 四聲) {
    using namespace std;
    string initial = mc_initial_data[init].鄴;
    bool has_medial_j = mc_final_data[fina].final.等 == 6;
    bool has_medial_w = mc_final_data[fina].final.合;
    string medial = has_medial_w ? has_medial_j ? "ɥ" : "w" : has_medial_j ? "j" : "";
    string rhyme = mc_韻部_data[(uint32_t)mc_final_data[fina].final.韻部].鄴;
    if (3 == 四聲) {
        rhyme = to_入聲(rhyme); }
    string tone = 四聲_diacritic[四聲];
    return add_diacritic(initial + medial + rhyme, tone); }
std::string predict_金陵(uint8_t init, uint8_t fina, uint8_t 四聲) {
    using namespace std;
    string initial = mc_initial_data[init].金陵.triggered && (string::npos != mc_韻部_data[(uint32_t)mc_final_data[fina].final.韻部].金陵.find("y"s) || string::npos != mc_韻部_data[(uint32_t)mc_final_data[fina].final.韻部].金陵.find("ø"s) || string::npos != mc_韻部_data[(uint32_t)mc_final_data[fina].final.韻部].金陵.find("œ"s)) ? *mc_initial_data[init].金陵.triggered : mc_initial_data[init].金陵.elsewhere;
    bool has_medial_j = mc_final_data[fina].final.等 == 6;
    bool has_medial_w = mc_final_data[fina].final.合;
    string medial = has_medial_w ? has_medial_j ? "ɥ" : "w" : has_medial_j ? "j" : "";
    string rhyme = mc_韻部_data[(uint32_t)mc_final_data[fina].final.韻部].金陵;
    if (3 == 四聲) {
        rhyme = to_入聲(rhyme); }
    string tone = 四聲_diacritic[四聲];
    return add_diacritic(initial + medial + rhyme, tone); }
std::string predict_prelmc(uint8_t init, uint8_t fina, uint8_t 四聲) {
    using namespace std;
    string initial = mc_initial_data[init].中唐長安.elsewhere;
    string final = mc_final_data[fina].prelmc.elsewhere;
    if (mc_initial_data[init].中唐長安.triggered && mc_final_data[fina].prelmc.F && !(init == 3 && (mc_final_data[fina].final.韻部 == mc_韻部::東B || mc_final_data[fina].final.韻部 == mc_韻部::尤))) {
        initial = *mc_initial_data[init].中唐長安.triggered;
        final = *mc_final_data[fina].prelmc.F; }
    if (initial == "mb"s)
        final = mc_final_data[fina].prelmc.m;
    return add_diacritic(initial + final, 四聲_diacritic[四聲]); }
