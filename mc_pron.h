#include <cinttypes>
#include <array>
#include <optional>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <regex>
using namespace std::literals::string_literals;
struct lattice_1 {
    std::string elsewhere;
    std::optional<std::string> triggered;
    lattice_1(std::string value) { elsewhere = value; }
    lattice_1(std::string value, std::string value0) { elsewhere = value; triggered = value0; } };
enum class αβ {β, α, αβ};
struct mc_initial_datus {
    std::string name;
    std::string baxter_sagart;
    std::string sbgy;
    std::optional<αβ> αβ;
    lattice_1 金陵;
    std::string 鄴;
    lattice_1 中唐長安; };
enum class mc_initial {幫, 滂, 並, 明, 端, 透, 定, 泥, 來, 知, 徹, 澄, 娘, 精, 清, 從, 心, 邪, 莊, 初, 崇, 生, 俟, 章, 昌, 禪, 日, 書, 船, 以, 見, 溪, 群, 疑, 影, 曉, 匣, 云};
static std::vector<mc_initial_datus> const mc_initial_data = {
    { std::string("幫"), std::string("p"), std::string("p"), αβ::αβ,
        { std::string("p"), std::string("ɸ") }, std::string("p"), { std::string("p"), std::string("f") } },
    { std::string("滂"), std::string("ph"), std::string("pʰ"), αβ::αβ,
        { std::string("ph"), std::string("ɸh") }, std::string("ph"), { std::string("ph"), std::string("f") } },
    { std::string("並"), std::string("b"), std::string("bʰ"), αβ::αβ,
        { std::string("b"), std::string("β") }, std::string("b"), { std::string("b̤"), std::string("v̤") } },
    { std::string("明"), std::string("m"), std::string("m"), αβ::αβ,
        std::string("m"), std::string("m"), { std::string("mb"), std::string("w̃") } },
    { std::string("端"), std::string("t"), std::string("t"), std::nullopt, std::string("t"), std::string("t"), std::string("t") },
    { std::string("透"), std::string("th"), std::string("tʰ"), std::nullopt, std::string("th"), std::string("th"), std::string("th") },
    { std::string("定"), std::string("d"), std::string("dʰ"), std::nullopt, std::string("d"), std::string("d"), std::string("d̤") },
    { std::string("泥"), std::string("n"), std::string("n"), std::nullopt, std::string("n"), std::string("n"), std::string("nd") },
    { std::string("來"), std::string("l"), std::string("l"), αβ::β, std::string("l"), std::string("l"), std::string("l") },
    { std::string("知"), std::string("tr"), std::string("ţ"), αβ::β, std::string("t"), std::string("ʈ"), std::string("ʈ") },
    { std::string("徹"), std::string("trh"), std::string("ţʰ"), αβ::β, std::string("th"), std::string("ʈh"), std::string("ʈh") },
    { std::string("澄"), std::string("dr"), std::string("ɖʰ"), αβ::β, std::string("d"), std::string("ɖ"), std::string("ɖ̤") },
    { std::string("娘"), std::string("nr"), std::string("ɳ"), αβ::β, std::string("n"), std::string("ɳ"), std::string("ɳɖ") },
    { std::string("精"), std::string("ts"), std::string("ts"), αβ::α, std::string("tz"), std::string("tz"), std::string("tz") },
    { std::string("清"), std::string("tsh"), std::string("tsʰ"), αβ::α, std::string("ts"), std::string("ts"), std::string("ts") },
    { std::string("從"), std::string("dz"), std::string("dzʰ"), αβ::α, std::string("dz"), std::string("dz"), std::string("d̤z") },
    { std::string("心"), std::string("s"), std::string("s"), αβ::α, std::string("s"), std::string("s"), std::string("s") },
    { std::string("邪"), std::string("z"), std::string("z"), αβ::α, std::string("dz"), std::string("z"), std::string("z̤") },
    { std::string("莊"), std::string("tsr"), std::string("ʧ"), αβ::β, std::string("ʈʐ"), std::string("ʈʐ"), std::string("ʈʐ") },
    { std::string("初"), std::string("tsrh"), std::string("ʧʰ"), αβ::β, std::string("ʈʂ"), std::string("ʈʂ"), std::string("ʈʂ") },
    { std::string("崇"), std::string("dzr"), std::string("dʒʰ"), αβ::β, std::string("ɖʐ"), std::string("ɖʐ"), std::string("ɖ̤ʐ") },
    { std::string("生"), std::string("sr"), std::string("ʃ"), αβ::β, std::string("ʂ"), std::string("ʂ"), std::string("ʂ") },
    { std::string("俟"), std::string("zr"), std::string("dʐʰ"), αβ::β, std::string("ɖʐ"), std::string("ʐ"), std::string("ʐ") }, // merged with 崇 in 廣韻
    { std::string("章"), std::string("tsy"), std::string("tɕ"), αβ::α, std::string("cʑ"), std::string("cʑ"), std::string("cʑ") },
    { std::string("昌"), std::string("tsyh"), std::string("tɕʰ"), αβ::α, std::string("cɕ"), std::string("cɕ"), std::string("cɕ") },
    { std::string("禪"), std::string("dzy"), std::string("ʑ"), αβ::α, std::string("ɟʑ"), std::string("ɟʑ"), std::string("ɟ̤ʑ") },
    { std::string("日"), std::string("ny"), std::string("nʑ"), αβ::α, std::string("ɲ"), std::string("ɲ"), std::string("ɲɟʑ") },
    { std::string("書"), std::string("sy"), std::string("ɕ"), αβ::α, std::string("ɕ"), std::string("ɕ"), std::string("ɕ") },
    { std::string("船"), std::string("zy"), std::string("dʑʰ"), αβ::α, std::string("ɟʑ"), std::string("ʑ"), std::string("ʑ̤") },
    { std::string("以"), std::string("y"), std::string("j"), αβ::α, std::string("j"), std::string("j"), std::string("j") }, // written as 羊 in 陳以信's paper
    { std::string("見"), std::string("k"), std::string("k"), αβ::αβ, std::string("k"), std::string("k"), std::string("k") },
    { std::string("溪"), std::string("kh"), std::string("kʰ"), αβ::αβ, std::string("kh"), std::string("kh"), std::string("kh") },
    { std::string("群"), std::string("g"), std::string("gʰ"), αβ::αβ, std::string("g"), std::string("g"), std::string("g̤") },
    { std::string("疑"), std::string("ng"), std::string("ŋ"), αβ::αβ, std::string("ŋ"), std::string("ŋ"), std::string("ŋg") },
    { std::string("影"), std::string("'"), std::string("ʔ"), αβ::αβ, std::string("ʔ"), std::string("ʔ"), std::string("ʔ") },
    { std::string("曉"), std::string("x"), std::string("x"), αβ::αβ, std::string("h"), std::string("x"), std::string("x") },
    { std::string("匣"), std::string("h"), std::string("ɣ"), std::nullopt, std::string("ɦ"), std::string("ɣ"), std::string("ɣ̤") },
    { std::string("云"), std::string("hj"), std::string(""), αβ::β, std::string("ɦ"), std::string("w"), std::string("ɦ") } };
// { std::string("矣"), std::string("hj"), std::string(""), std::string("ɦ"), std::string("ʜ"), std::string("ɦ") }
enum class mc_攝 {
    通, 江, 止, 遇, 蟹, 臻, 山, 效, 果, 假, 宕, 梗, 流, 深, 咸, 曾 };
// 切韻韻部
enum class mc_韻部 {
    東A, 東B, 冬, 鍾, 江, 支, 脂, 之, 微, 魚, 虞, 模, 泰, 齊, 祭, 佳, 皆, 夬, 灰, 咍, 廢, 眞, 臻, 文, 殷, 元, 魂, 痕, 寒, 刪, 山, 先, 仙, 蕭, 宵, 肴, 豪, 歌A, 歌B, 麻A, 麻B, 覃, 談, 陽, 唐, 庚A, 庚B, 耕, 清, 青, 尤, 侯, 幽, 侵, 鹽, 添, 蒸, 登, 咸, 銜, 嚴, 凡 };
struct mc_韻部_datus {
    std::string name;
    mc_攝 攝;
    std::string 金陵;
    std::string 鄴;
    bool 開合; };
std::vector<mc_韻部_datus> mc_韻部_data{
    {"東A", mc_攝::通, "ʉŋ", "ʉŋ", 1},
    {"東B", mc_攝::通, "yŋ", "yŋ", 1},
    {"冬", mc_攝::通, "uŋ", "əŋ", 1},
    {"鍾", mc_攝::通, "øŋ", "øŋ", 1},
    {"江", mc_攝::江, "ɔŋ", "ɔŋ", 1},
    {"支", mc_攝::止, "e", "i", 0},
    {"脂", mc_攝::止, "i, yj", "i", 0},
    {"之", mc_攝::止, "i", "e", 1},
    {"微", mc_攝::止, "yj", "yj", 0},
    {"魚", mc_攝::遇, "œ", "ø", 1},
    {"虞", mc_攝::遇, "ø", "ø", 1},
    {"模", mc_攝::遇, "u", "ə", 1},
    {"泰", mc_攝::蟹, "ɑj", "ɐj", 0},
    {"齊", mc_攝::蟹, "ɐj", "ɪj", 0},
    {"祭", mc_攝::蟹, "ej", "ej", 0},
    {"佳", mc_攝::蟹, "ɛ", "ɛj", 0},
    {"皆", mc_攝::蟹, "ɑj", "ɛj", 0},
    {"夬", mc_攝::蟹, "æ", "ɛj", 0},
    {"灰", mc_攝::蟹, "ʏj", "ʏj", 1},
    {"咍", mc_攝::蟹, "əj", "əj", 1},
    {"廢", mc_攝::蟹, "øj", "øj", 0},
    {"眞", mc_攝::臻, "in", "in", 0},
    {"臻", mc_攝::臻, "in", "un", 1},
    {"文", mc_攝::臻, "yn", "yn", 1},
    {"殷", mc_攝::臻, "in", "yn", 1},
    {"元", mc_攝::山, "øn", "øn", 0},
    {"魂", mc_攝::臻, "ʏn", "ʏn", 1},
    {"痕", mc_攝::臻, "ən", "ən", 1},
    {"寒", mc_攝::山, "ɑn", "ɐn", 0},
    {"刪", mc_攝::山, "æn", "ɛn", 0},
    {"山", mc_攝::山, "ɛn", "ɛn", 0},
    {"先", mc_攝::山, "ɪn", "ɪn", 0},
    {"仙", mc_攝::山, "en", "en", 0},
    {"蕭", mc_攝::效, "ɪw", "ɪw", 1},
    {"宵", mc_攝::效, "ew", "ew", 1},
    {"肴", mc_攝::效, "ɛw", "ɛw", 1},
    {"豪", mc_攝::效, "ɑw", "ɐw", 1},
    {"歌A", mc_攝::果, "ɑ", "ɐ", 0},
    {"歌B", mc_攝::果, "ɑ", "œ", 0},
    {"麻A", mc_攝::假, "æ", "ɛ", 0},
    {"麻B", mc_攝::假, "jæ", "jɛ", 1},
    {"覃", mc_攝::咸, "ɔm", "ɔm", 1},
    {"談", mc_攝::咸, "ɑm", "ɐm", 1},
    {"陽", mc_攝::宕, "œŋ", "œŋ", 0},
    {"唐", mc_攝::宕, "ɑŋ", "ɐŋ", 0},
    {"庚A", mc_攝::梗, "æŋ", "ɛŋ", 0},
    {"庚B", mc_攝::梗, "eŋ", "jɛŋ", 0},
    {"耕", mc_攝::梗, "ɛŋ", "ɛŋ", 0},
    {"清", mc_攝::梗, "eŋ", "eŋ", 0},
    {"青", mc_攝::梗, "ɪŋ", "ɪŋ", 0},
    {"尤", mc_攝::流, "y", "y", 1},
    {"侯", mc_攝::流, "ʉ", "u", 1},
    {"幽", mc_攝::流, "iw", "iw", 1},
    {"侵", mc_攝::深, "im", "im", 1},
    {"鹽", mc_攝::咸, "em", "em", 1},
    {"添", mc_攝::咸, "ɪm", "ɪm", 1},
    {"蒸", mc_攝::曾, "iŋ", "iŋ", 0},
    {"登", mc_攝::曾, "oŋ", "oŋ", 0},
    {"咸", mc_攝::咸, "ɛm", "ɛm", 1},
    {"銜", mc_攝::咸, "æm", "ɛm", 1},
    {"嚴", mc_攝::咸, "øm", "øm", 1},
    {"凡", mc_攝::咸, "œm", "øm", 1} };
struct mc_final {
    mc_韻部 韻部;
    uint8_t 等; // I II III IV (重紐 III) (重紐 IV)
    uint8_t 合;
    uint8_t 去; };
struct mc_final_prelmc_outcome {
    std::string elsewhere;
    std::string m;
    std::optional<std::string> F; };
struct mc_final_class {
    std::string 小韻;
    mc_final 韻圖;
    std::string baxter_sagart;
    std::string sbgy;
    mc_final_prelmc_outcome prelmc;
    std::optional<mc_final_prelmc_outcome> prelmc_α; };
// 切韻韻部 split by 等, 重紐, 呼, 入聲 (廣韻 split 真 to 真 and 諄, 寒 to 寒 and 桓, 歌 to 歌 and 戈) (Baxter is like 廣韻 but combines 真, 諄, and 臻 to -in)
static std::vector<mc_final_class> const mc_final_data{
    {"", { mc_韻部::東A, 1, 0, 0 }, "uwng", "uŋ", {"ɤwŋ", "oŋ"}},
    {"", { mc_韻部::東A, 1, 0, 1 }, "uwk", "uk", {"ɤwk", "ok"}},
    {"", { mc_韻部::東B, 3, 0, 0 }, "juwng", "ĭuŋ", {"ɯwŋ", "ɤwŋ", "ɤwŋ/uŋ competing"}},
    {"", { mc_韻部::東B, 3, 0, 1 }, "juwk", "ĭuk", {"ɯwk", "ɤwk", "ɤwk/uk competing"}},
    {"", { mc_韻部::冬, 1, 1, 0 }, "owng", "uoŋ", {"ɤwŋ", "oŋ"}},
    {"", { mc_韻部::冬, 1, 1, 1 }, "owk", "uok", {"ɤwk", "ok"}},
    {"", { mc_韻部::鍾, 3, 1, 0 }, "jowng", "ĭwoŋ", {"wɯɤwŋ", "wɯɤwŋ", "ɤwŋ"}},
    {"", { mc_韻部::鍾, 3, 1, 1 }, "jowk", "ĭwok", {"wɯɤwk", "wɯɤwk", "ɤwk"}},
    {"", { mc_韻部::江, 2, 0, 0 }, "aewng", "ɔŋ", {"æwŋ", "æwŋ"}},
    {"", { mc_韻部::江, 2, 0, 1 }, "aewk", "ɔk", {"æwk", "æwk"}},
    {"支移提兒離疵貲䌳斯差摛雌知馳釃厜眵齜齹紙是此豸徙酏邐躧爾侈弛紫舓㧗狔褫㨖寘詈豉積賜刺易漬智翅屣卶𧙁", { mc_韻部::支, 3, 0, 0 }, "je", "ĭe", {"ɯj", "ɯj"}, {{"ij", "ij"}}},
    {"爲鬌𡍮羸吹隨眭䪎痿劑衰腄䮔䔺髓絫蔿觜蘂捶揣𤢍䓈惢菙惴爲累縋吹睡䄲䅗娷瓗諉", { mc_韻部::支, 3, 1, 0 }, "jwe", "ĭwe", {"wɯj", "wɯj"}, {{"wij", "wij"}}},
    {"糜鈹陂竒犧㩻宜皮羈漪靡彼被技倚掎綺螘㱟𪖪帔賁髲寄芰議倚戲㞆", { mc_韻部::支, 5, 0, 0 }, "je", "ĭe", {"ɯj", "ɯj"}},
    {"嬀𪎮逶虧危毀委跪詭硊跪䞈餧僞毀", { mc_韻部::支, 5, 1, 0 }, "jwe", "ĭwe", {"wɯj", "wɯj"}},
    {"祇𤰞陴彌詑𤿎𢔌渳婢諀企枳避臂譬企縊馶", { mc_韻部::支, 6, 0, 0 }, "jie", "ĭe", {"ij", "ij"}},
    {"隓闚𩓸跬觖恚瞡孈", { mc_韻部::支, 6, 1, 0 }, "jwie", "ĭwe", {"wij", "wij"}},
    {"脂姨師咨鴟絺郪茨尼墀私尸棃胝旨視兕𡛷矢雉死履柅黹𡳭𧿲至嗜利膩𦤶緻杘二恣次四地肄示自痓屍", { mc_韻部::脂, 3, 0, 0 }, "ij", "i", {"ɯj", "ɯj"}, {{"ij", "ij"}}}, // FIXME: Is 地 α or β?
    {"追蕤衰惟㶟綏錐誰帷鎚推嶉洧水壘趡㠑蕊唯濢位遂醉邃類帥翠萃墜出遺轛㿷㽷", { mc_韻部::脂, 3, 1, 0 }, "wij", "wi", {"wɯj", "wɯj"}, {{"wij", "wij"}}},
    {"飢鬐眉悲邳丕狋美鄙几否嚭㰻跽郿祕濞備劓冀臮懿器齂", { mc_韻部::脂, 5, 0, 0 }, "ij", "i", {"ɯj", "ɯj"}},
    {"龜逵巋軌䣀巋匱媿喟豷", { mc_韻部::脂, 5, 1, 0 }, "wij", "wi", {"wɯj", "wɯj"}},
    {"𣬈伊紕咦匕牝屁棄寐鼻痹", { mc_韻部::脂, 6, 0, 0 }, "jij", "i", {"ij", "ij"}},
    {"葵倠揆癸䁤悸季䁤侐", { mc_韻部::脂, 6, 1, 0 }, "jwij", "wi", {"wij", "wij"}},
    {"", { mc_韻部::之, 3, 0, 0 }, "i", "ĭə", {"ɯj", "ɯj"}},
    {"", { mc_韻部::微, 3, 0, 0 }, "j+j", "ĭəi", {"ɯj", "ɯj", "ɤj"}},
    {"", { mc_韻部::微, 3, 1, 0 }, "jw+j", "ĭwəi", {"wɯj", "wɯj", "ɤj"}},
    {"", { mc_韻部::魚, 3, 0, 0 }, "jo", "ĭo", {"ɯɤ", "ɯɤ", "ɯɤ"}},
    {"", { mc_韻部::虞, 3, 1, 0 }, "ju", "ĭu", {"u", "u", "u"}},
    {"", { mc_韻部::模, 1, 1, 0 }, "u", "u", {"o", "o"}},
    {"", { mc_韻部::泰, 1, 0, 0 }, "aj", "ɑi", {"ɑj", "ɑj"}},
    {"", { mc_韻部::泰, 1, 1, 0 }, "waj", "uɑi", {"wɑj", "wɑj"}},
    {"", { mc_韻部::齊, 4, 0, 0 }, "ej", "iei", {"iej", "iej"}},
    {"", { mc_韻部::齊, 4, 1, 0 }, "wej", "iwei", {"wiej", "wiej"}},
    {"祭㡜掣制逝曳滯例丗㿃跇", { mc_韻部::祭, 3, 0, 0 }, "jej", "ĭɛi", {"ej", "ej"}, {{"iej", "iej"}}},
    {"歳衞芮贅𠻜毳銳綴稅㯔篲啜𨮱蕝", { mc_韻部::祭, 3, 1, 0 }, "jwej", "ĭwɛi", {"wej", "wej"}, {{"wiej", "wiej"}}},
    {"䋵憩猘偈㓷", { mc_韻部::祭, 5, 0, 0 }, "jej", "ĭɛi", {"ej", "ej"}},
    {"劌", { mc_韻部::祭, 5, 1, 0 }, "jwej", "ĭwɛi", {"wej", "wej"}},
    {"𡚁蔽袂藝潎", { mc_韻部::祭, 6, 0, 0 }, "jiej", "ĭɛi", {"iej", "iej"}},
    {"", { mc_韻部::祭, 6, 1, 0 }, "jwiej", "ĭwɛi", {"wiej", "wiej"}},
    {"", { mc_韻部::佳, 2, 0, 0 }, "ea", "ai", {"æ/æj dialectal mixture", "æ/æj dialectal mixture"}},
    {"", { mc_韻部::佳, 2, 1, 0 }, "wea", "wai", {"wæ/wæj dialectal mixture", "wæ/wæj dialectal mixture"}},
    {"", { mc_韻部::皆, 2, 0, 0 }, "eaj", "ɐi", {"æj", "æj"}},
    {"", { mc_韻部::皆, 2, 1, 0 }, "weaj", "wɐi", {"wæj", "wæj"}},
    {"", { mc_韻部::夬, 2, 0, 0 }, "aej", "æi", {"æj", "æj"}},
    {"", { mc_韻部::夬, 2, 1, 0 }, "waej", "wæi", {"wæj", "wæj"}},
    {"", { mc_韻部::灰, 1, 1, 0 }, "woj", "uɒi", {"wɑj", "wɑj"}},
    {"", { mc_韻部::咍, 1, 0, 0 }, "oj", "ɒi", {"ɑj", "ɑj"}},
    {"", { mc_韻部::廢, 3, 0, 0 }, "joj", "ĭɐi", {"ej", "ej", "ej"}},
    {"", { mc_韻部::廢, 3, 1, 0 }, "jwoj", "ĭwɐi", {"wej", "wej", "ej"}},
    // The Qièyùn has a single rhyme 真 Zhēn that the Guǎngyùn split into two rhymes, 真 Zhēn and 諄 Zhūn. The general pattern in the Guǎngyùn is that words with -in and grave-initial words with the division-III chóngniǔ final -win are included in 真 Zhēn, while acute-initial words in -win and division-IV chóngniǔ words in -jwin are placed in 諄 Zhūn
    {"眞𤣆新辰仁神親礥申㷠珍陳津瞋秦寅紉軫辴腎忍矤嶙紖盡㯸笉引濜屒震信刃𦙍遴敶愼眒賮晉鎭疢親", { mc_韻部::眞, 3, 0, 0 }, "in", "ĭĕn", {"ɯn", "ɯn"}, {{"in", "in"}}},
    {"質日實秩悉七暱逸抶栗窒疾失堲𠮟蛭", { mc_韻部::眞, 3, 0, 1 }, "it", "ĭĕt", {"ɯt", "ɯt"}, {{"it", "it"}}},
    {"筠殞諄椿䣩荀純犉脣淪屯逡遵春鷷勻旬準尹筍蝡蠢盾偆耣𣯍賰稕𡺲殉儁舜閠順", { mc_韻部::眞, 3, 1, 0 }, "win", "ĭuĕn" /*ĭwĕn for 筠殞*/, {"wɯn", "wɯn"}, {{"win", "win"}}},
    {"䫻率茁術崒聿卒卹律黜㤕术出焌𠭴", { mc_韻部::眞, 3, 1, 1 }, "wit", "ĭuĕt" /*ĭwĕt for 䫻*/, {"wɯt", "wɯt"}, {{"wit", "wit"}}},
    {"𥎊銀巾珉貧𪔗彬砏愍菣憖衅僅", { mc_韻部::眞, 5, 0, 0 }, "in", "ĭĕn", {"ɯn", "ɯn"}},
    {"姞密弼乙耴筆肸曁", { mc_韻部::眞, 5, 0, 1 }, "it", "ĭĕt", {"ɯt", "ɯt"}},
    {"麏囷贇窘", { mc_韻部::眞, 5, 1, 0 }, "win", "ĭwĕn", {"wɯn", "wɯn"}},
    {"䎉", { mc_韻部::眞, 5, 1, 1 }, "wit", "ĭwĕt", {"wɯt", "wɯt"}},
    {"因賔繽頻民𧼒緊牝釿泯螼脪儐印𣎵螼", { mc_韻部::眞, 6, 0, 0 }, "jin", "ĭĕn", {"in", "in"}},
    {"一匹吉詰欯蜜必邲", { mc_韻部::眞, 6, 0, 1 }, "jit", "ĭĕt", {"it", "it"}},
    {"均𦃢呁", { mc_韻部::眞, 6, 1, 0 }, "jwin", "ĭuĕn", {"win", "win"}},
    {"獝橘", { mc_韻部::眞, 6, 1, 1 }, "jwit", "ĭuĕt", {"wit", "wit"}},
    {"臻莘𦿒𧤛齔櫬", { mc_韻部::臻, 3, 0, 0 }, "in", "ĭen", {"ɯn", "ɯn"}, {{"in", "in"}}},
    {"㓼𪗨櫛瑟𪗨", { mc_韻部::臻, 3, 0, 1 }, "it", "ĭet", {"ɯt", "ɯt"}, {{"it", "it"}}},
    {"", { mc_韻部::文, 3, 1, 0 }, "jun", "ĭuən", {"wɯn", "wɯn", "ɤn"}},
    {"", { mc_韻部::文, 3, 1, 1 }, "jut", "ĭuət", {"wɯt", "wɯt", "ɤt"}},
    {"", { mc_韻部::殷, 3, 0, 0 }, "j+n", "ĭən", {"ɯn", "ɯn", "ɤn"}},
    {"", { mc_韻部::殷, 3, 0, 1 }, "j+t", "ĭət", {"ɯt", "ɯt", "ɤt"}},
    {"", { mc_韻部::元, 3, 0, 0 }, "jon", "ĭɐn", {"en", "en", "æn"}},
    {"", { mc_韻部::元, 3, 0, 1 }, "jot", "ĭɐt", {"et", "et", "æt"}},
    {"", { mc_韻部::元, 3, 1, 0 }, "jwon", "ĭwɐn", {"wen", "wen", "æn"}},
    {"", { mc_韻部::元, 3, 1, 1 }, "jwot", "ĭwɐt", {"wet", "wet", "æt"}},
    {"", { mc_韻部::魂, 1, 1, 0 }, "won", "uən", {"wɤn", "wɤn"}},
    {"", { mc_韻部::魂, 1, 1, 1 }, "wot", "uət", {"wɤt", "wɤt"}},
    {"", { mc_韻部::痕, 1, 0, 0 }, "on", "ən", {"ɤn", "ɤn"}},
    {"", { mc_韻部::痕, 1, 0, 1 }, "ot", "ət", {"ɤt", "ɤt"}},
    {"", { mc_韻部::寒, 1, 0, 0 }, "an", "ɑn", {"ɑn", "ɑn"}},
    {"", { mc_韻部::寒, 1, 0, 1 }, "at", "ɑt", {"ɑt", "ɑt"}},
    {"", { mc_韻部::寒, 1, 1, 0 }, "wan", "uɑn", {"wɑn", "wɑn"}},
    {"", { mc_韻部::寒, 1, 1, 1 }, "wat", "uɑt", {"wɑt", "wɑt"}},
    {"", { mc_韻部::刪, 2, 0, 0 }, "aen", "an", {"æn", "æn"}},
    {"", { mc_韻部::刪, 2, 0, 1 }, "aet", "at", {"æt", "æt"}},
    {"", { mc_韻部::刪, 2, 1, 0 }, "waen", "wan", {"wæn", "wæn"}},
    {"", { mc_韻部::刪, 2, 1, 1 }, "waet", "wat", {"wæt", "wæt"}},
    {"", { mc_韻部::山, 2, 0, 0 }, "ean", "æn", {"æn", "æn"}},
    {"", { mc_韻部::山, 2, 0, 1 }, "eat", "æt", {"æt", "æt"}},
    {"", { mc_韻部::山, 2, 1, 0 }, "wean", "wæn", {"wæn", "wæn"}},
    {"", { mc_韻部::山, 2, 1, 1 }, "weat", "wæt", {"wæt", "wæt"}},
    {"", { mc_韻部::先, 4, 0, 0 }, "en", "ien", {"ien", "ien"}},
    {"", { mc_韻部::先, 4, 0, 1 }, "et", "iet", {"iet", "iet"}},
    {"", { mc_韻部::先, 4, 1, 0 }, "wen", "iwen", {"wien", "wien"}},
    {"", { mc_韻部::先, 4, 1, 1 }, "wet", "iwet", {"wiet", "wiet"}},
    {"仙錢遷煎然延𩜾邅潺羶脠鋋纏連㳄漹燀獮演踐展𦗢趁淺闡善翦蹨𦆀輦搌㒄邅棧線戰繕𩥇箭硟扇賤羨輾衍邅𤹨", { mc_韻部::仙, 3, 0, 0 }, "jen", "ĭɛn", {"en", "en"}, {{"ien", "ien"}}},
    {"薛列哲熱晢舌折轍設蠽榝屮㔍掣抴𨵊", { mc_韻部::仙, 3, 0, 1 }, "jet", "ĭɛt", {"et", "et"}, {{"iet", "iet"}}},
    {"全宣鐫堧穿沿旋船詮專遄貟恮栓猭椽攣𡰝臇雋兖臠轉輭舛膞篆剸選撰瑗釧掾𤲬戀猭𨏉縓㳬選䉵孨傳𢮨囀剸", { mc_韻部::仙, 3, 1, 0 }, "jwen", "ĭwɛn", {"wen", "wen"}, {{"wien", "wien"}}},
    {"絕蕝雪𤿫恱𤑔說拙歠輟劣㕞呐茁膬啜㿱", { mc_韻部::仙, 3, 1, 1 }, "jwet", "ĭwɛt", {"wet", "wet"}, {{"wiet", "wiet"}}},
    {"乾愆焉蹇齴件辯辡免鴘㫃彦變卞", { mc_韻部::仙, 5, 0, 0 }, "jen", "ĭɛn", {"en", "en"}},
    {"傑孼朅別䇷𡤼焆娎", { mc_韻部::仙, 5, 0, 1 }, "jet", "ĭɛt", {"et", "et"}},
    {"權弮嬽勬卷圈眷倦𥛁", { mc_韻部::仙, 5, 1, 0 }, "jwen", "ĭwɛn", {"wen", "wen"}},
    {"噦𥄎蹶", { mc_韻部::仙, 5, 1, 1 }, "jwet", "ĭwɛt", {"wet", "wet"}},
    {"甄嘕篇便緜鞭遣緬褊楩譴面躽騗便", { mc_韻部::仙, 6, 0, 0 }, "jien", "ĭɛn", {"ien", "ien"}},
    {"滅鷩瞥", { mc_韻部::仙, 6, 0, 1 }, "jiet", "ĭɛt", {"iet", "iet"}},
    {"翾姢蜎蠉絹", { mc_韻部::仙, 6, 1, 0 }, "jwien", "ĭwɛn", {"wien", "wien"}},
    {"缺妜", { mc_韻部::仙, 6, 1, 1 }, "jwiet", "ĭwɛt", {"wiet", "wiet"}},
    {"", { mc_韻部::蕭, 4, 0, 0 }, "ew", "ieu", {"iew", "iew"}},
    {"宵超朝⿱日黽樵焦饒燒遥韶昭鴞鍫怊燎小肈沼巐少擾𪍑紹鷕悄𠟿繚𥬇照燿召邵噍陗𤊽醮少脁饒", { mc_韻部::宵, 3, 0, 0 }, "jew", "ĭɛu", {"ew", "ew"}, {{"iew", "iew"}}},
    {"嚻驕鑣苗喬妖趫夭矯表藨𨲭麃嶠趬𧇠廟裱", { mc_韻部::宵, 5, 0, 0 }, "jew", "ĭɛu", {"ew", "ew"}},
    {"飊瓢蜱要蹻𤐫翹摽縹眇褾闄要剽妙驃翹", { mc_韻部::宵, 6, 0, 0 }, "jiew", "ĭɛu", {"iew", "iew"}},
    {"", { mc_韻部::肴, 2, 0, 0 }, "aew", "au", {"æw", "æw"}},
    {"", { mc_韻部::豪, 1, 0, 0 }, "aw", "ɑu", {"ɑw", "ɑw"}},
    {"", { mc_韻部::歌A, 1, 0, 0 }, "a", "ɑ", {"ɑ", "ɑ"}},
    {"", { mc_韻部::歌A, 1, 1, 0 }, "wa", "uɑ", {"wɑ", "wɑ"}},
    {"", { mc_韻部::歌B, 3, 0, 0 }, "ja", "ĭɑ", {"ɯɑ", "ɯɑ"}},
    {"", { mc_韻部::歌B, 3, 1, 0 }, "jwa", "ĭuɑ", {"wɯɑ", "wɯɑ"}},
    {"", { mc_韻部::麻A, 2, 0, 0 }, "ae", "a", {"æ", "æ"}},
    {"", { mc_韻部::麻A, 2, 1, 0 }, "wae", "wa", {"wæ", "wæ"}},
    {"", { mc_韻部::麻B, 3, 0, 0 }, "jae", "ĭa", {"iæ", "iæ"}},
    {"", { mc_韻部::覃, 1, 0, 0 }, "om", "ɒm", {"ɑm", "ɑm"}},
    {"", { mc_韻部::覃, 1, 0, 1 }, "op", "ɒp", {"ɑp", "ɑp"}},
    {"", { mc_韻部::談, 1, 1, 0 }, "am", "ɑm", {"ɑm", "ɑm"}},
    {"", { mc_韻部::談, 1, 1, 1 }, "ap", "ɑp", {"ɑp", "ɑp"}},
    {"", { mc_韻部::陽, 3, 0, 0 }, "jang", "ĭaŋ", {"ɯɑ̃", "ɯɑ̃", "ɑ̃"}},
    {"", { mc_韻部::陽, 3, 0, 1 }, "jak", "ĭak", {"ɯɑk", "ɯɑk", "ɑk"}},
    {"", { mc_韻部::陽, 3, 1, 0 }, "jwang", "ĭwaŋ", {"wɯɑ̃", "wɯɑ̃", "ɑ̃"}},
    {"", { mc_韻部::陽, 3, 1, 1 }, "jwak", "ĭwak", {"wɯɑk", "wɯɑk", "ɑk"}},
    {"", { mc_韻部::唐, 1, 0, 0 }, "ang", "ɑŋ", {"ɑ̃", "ɑ̃"}},
    {"", { mc_韻部::唐, 1, 0, 1 }, "ak", "ɑk", {"ɑk", "ɑk"}},
    {"", { mc_韻部::唐, 1, 1, 0 }, "wang", "uɑŋ", {"wɑ̃", "wɑ̃"}},
    {"", { mc_韻部::唐, 1, 1, 1 }, "wak", "uɑk", {"wɑk", "wɑk"}},
    {"", { mc_韻部::庚A, 2, 0, 0 }, "aeng", "ɐŋ", {"æ̃j", "æ̃j"}},
    {"", { mc_韻部::庚A, 2, 0, 1 }, "aek", "ɐk", {"æc", "æc"}},
    {"", { mc_韻部::庚A, 2, 1, 0 }, "waeng", "wɐŋ", {"wæ̃j", "wæ̃j"}},
    {"", { mc_韻部::庚A, 2, 1, 1 }, "waek", "wɐk", {"wæc", "wæc"}},
    {"", { mc_韻部::庚B, 3, 0, 0 }, "jaeng", "ĭɐŋ", {"ẽj", "ẽj"}},
    {"", { mc_韻部::庚B, 3, 0, 1 }, "jaek", "ĭɐk", {"ec", "ec"}},
    {"", { mc_韻部::庚B, 3, 1, 0 }, "jwaeng", "ĭwɐŋ", {"wẽj", "wẽj"}},
    {"", { mc_韻部::庚B, 3, 1, 1 }, "jwaek", "ĭwɐk", {"wec", "wec"}},
    {"", { mc_韻部::耕, 2, 0, 0 }, "eang", "æŋ", {"æ̃j", "æ̃j"}},
    {"", { mc_韻部::耕, 2, 0, 1 }, "eak", "æk", {"æc", "æc"}},
    {"", { mc_韻部::耕, 2, 1, 0 }, "weang", "wæŋ", {"wæ̃j", "wæ̃j"}},
    {"", { mc_韻部::耕, 2, 1, 1 }, "weak", "wæk", {"wæc", "wæc"}},
    {"淸情精盈貞檉成呈聲征跉𩛿靜整逞郢領丼請省徎倩政聖鄭遉性令淨盛精", { mc_韻部::清, 3, 0, 0 }, "jeng", "ĭɛŋ", {"ẽj", "ẽj"}},
    {"昔積繹釋尺石隻擲皵席籍麝𪐏彳", { mc_韻部::清, 3, 0, 1 }, "jek", "ĭɛk", {"ec", "ec"}},
    {"營騂潁", { mc_韻部::清, 3, 1, 0 }, "jweng", "ĭwɛŋ", {"wẽj", "wẽj"}},
    {"役𦳮𥄎", { mc_韻部::清, 3, 1, 1 }, "jwek", "ĭwɛk", {"wec", "wec"}},
    {"嬰輕名并頸痙頸餅廮眳勁聘摒偋詺輕𣢝", { mc_韻部::清, 6, 0, 0 }, "jieng", "ĭɛŋ", {"iẽj", "iẽj"}},
    {"益擗辟僻", { mc_韻部::清, 6, 0, 1 }, "jiek", "ĭɛk", {"iec", "iec"}},
    {"傾縈瓊𧵣頃夐", { mc_韻部::清, 6, 1, 0 }, "jwieng", "ĭwɛŋ", {"wiẽj", "wiẽj"}},
    {"瞁", { mc_韻部::清, 6, 1, 1 }, "jwiek", "ĭwɛk", {"wiec", "wiec"}}, // 碧 is 清 重紐三等
    {"", { mc_韻部::青, 4, 0, 0 }, "eng", "ieŋ", {"iẽj", "iẽj"}},
    {"", { mc_韻部::青, 4, 0, 1 }, "ek", "iek", {"iec", "iec"}},
    {"", { mc_韻部::青, 4, 1, 0 }, "weng", "iweŋ", {"wiẽj", "wiẽj"}},
    {"", { mc_韻部::青, 4, 1, 1 }, "wek", "iwek", {"wiec", "wiec"}},
    {"", { mc_韻部::尤, 3, 0, 0 }, "juw", "ĭəu", {"ɯw", "ɤw", "ɤw/u competing"}, {{"iw", "iw", "iw"}}},
    {"", { mc_韻部::侯, 1, 0, 0 }, "uw", "əu", {"ɤw", "o"}},
    {"", { mc_韻部::幽, 6, 0, 0 }, "jiw", "iəu", {"iw", "iw"}},
    {"侵尋林琛斟沈碪諶任深淫心祲𩷒䛘森岑兂嵾𧡪寑朕廩罧踸䤐荏枕沈葚甚瀋墋拰蕈㾕戡潭𩒣沁浸妊鴆枕賃滲闖譖讖揕臨甚䫴深", { mc_韻部::侵, 3, 1, 0 }, "im", "ĭĕm", {"ɯm", "ɯm"}, {{"im", "im"}}},
    {"緝十執習集入溼㗱蟄縶立𩎕歰戢湁煜熠孨霵㞚卙", { mc_韻部::侵, 3, 1, 1 }, "ip", "ĭĕp", {"ɯp", "ɯp"}, {{"ip", "ip"}}},
    {"琴欽吟歆金音噤錦僸稟㱃品𩖄廞𦧈禁䕃吟", { mc_韻部::侵, 5, 1, 0 }, "im", "ĭĕm", {"ɯm", "ɯm"}},
    {"及急岌泣吸邑𩾳鵖", { mc_韻部::侵, 5, 1, 1 }, "ip", "ĭĕp", {"ɯp", "ɯp"}},
    {"愔坅", { mc_韻部::侵, 6, 1, 0 }, "jim", "ĭĕm", {"im", "im"}},
    {"揖", { mc_韻部::侵, 6, 1, 1 }, "jip", "ĭĕp", {"ip", "ip"}},
    {"鹽廉銛籤詹棎苫䪜𩓾黏炎霑覘尖潛燅襳㶣琰斂颭冉陝諂漸憸𩟗剡豔贍染閃𡄑壍殮覘䠨潛占", { mc_韻部::鹽, 3, 0, 0 }, "jem", "ĭɛm", {"em", "em"}, {{"iem", "iem"}}},
    {"葉接攝涉獵捷䐑聶謵讘讋妾鍤輒曄萐", { mc_韻部::鹽, 3, 0, 1 }, "jep", "ĭɛp", {"ep", "ep"}, {{"iep", "iep"}}},
    {"砭淹𢜩𪙊箝險貶𩑳顩儉檢奄窆驗𢜰", { mc_韻部::鹽, 5, 0, 0 }, "jem", "ĭɛm", {"em", "em"}},
    {"𢽱衱𦀖", { mc_韻部::鹽, 5, 0, 1 }, "jep", "ĭɛp", {"ep", "ep"}},
    {"懕鍼黶脥厭", { mc_韻部::鹽, 6, 1, 0 }, "jiem", "ĭɛm", {"iem", "iem"}},
    {"𤷾魘", { mc_韻部::鹽, 6, 1, 1 }, "jiep", "ĭɛp", {"iep", "iep"}},
    {"", { mc_韻部::添, 4, 0, 0 }, "em", "iem", {"iem", "iem"}},
    {"", { mc_韻部::添, 4, 0, 1 }, "ep", "iep", {"iep", "iep"}},
    {"", { mc_韻部::蒸, 3, 0, 0 }, "ing", "ĭəŋ", {"ɯɤŋ", "ɯɤŋ"}},
    {"", { mc_韻部::蒸, 3, 0, 1 }, "ik", "ĭək", {"ɯɤk", "ɯɤk"}},
    {"", { mc_韻部::蒸, 3, 1, 0 }, "wing", "ĭwəŋ", {"wɯɤŋ", "wɯɤŋ"}},
    {"", { mc_韻部::蒸, 3, 1, 1 }, "wik", "ĭwək", {"wɯɤk", "wɯɤk"}},
    {"", { mc_韻部::登, 1, 0, 0 }, "ong", "əŋ", {"ɤŋ", "ɤŋ"}},
    {"", { mc_韻部::登, 1, 0, 1 }, "ok", "ək", {"ɤk", "ɤk"}},
    {"", { mc_韻部::登, 1, 1, 0 }, "wong", "uəŋ", {"wɤŋ", "wɤŋ"}},
    {"", { mc_韻部::登, 1, 1, 1 }, "wok", "uək", {"wɤk", "wɤk"}},
    {"", { mc_韻部::咸, 2, 0, 0 }, "eam", "ɐm", {"æm", "æm"}},
    {"", { mc_韻部::咸, 2, 0, 1 }, "eap", "ɐp", {"æp", "æp"}},
    {"", { mc_韻部::銜, 2, 1, 0 }, "aem", "am", {"æm", "æm"}},
    {"", { mc_韻部::銜, 2, 1, 1 }, "aep", "ap", {"æp", "æp"}},
    {"", { mc_韻部::嚴, 3, 1, 0 }, "jaem", "ĭɐm", {"em", "em", "æm"}},
    {"", { mc_韻部::嚴, 3, 1, 1 }, "jaep", "ĭɐp", {"ep", "ep", "æp"}},
    {"", { mc_韻部::凡, 3, 1, 0 }, "jom", "ĭwɐm", {"em", "em", "æm"}},
    {"", { mc_韻部::凡, 3, 1, 1 }, "jop", "ĭwɐp", {"ep", "ep", "æp"}}};
struct 四聲_class {
    std::string baxter_sagart;
    std::array<std::string, 2> sbgy;
    std::string diacritic; };
std::array<四聲_class, 4> 四聲_classes = {{
    {"", {"˥˩", "˩"}, ""},
    {"X", {"˥", "˥"}, "\xcc\x81"},
    {"H", {"˩˥", "˩˥"}, "\xcc\x80"},
    {"", {"", ""}, ""}}};
struct mc_syllable {
    uint8_t initial;
    uint8_t final;
    uint8_t 四聲;
    template<class archive>
    void serialize(archive& ar) {
        ar(initial);
        ar(final);
        ar(四聲); } };
struct baxter_sagart_oc_entry {
    std::string oc_str;
    mc_syllable mc_pron;
    std::string 字;
    std::string gloss;
    template<class archive>
    void serialize(archive& ar) {
        ar(oc_str);
        ar(mc_pron);
        ar(字);
        ar(gloss); } };
struct sbgy_entry {
    mc_syllable mc_pron;
    std::string 字;
    std::string gloss;
    template<class archive>
    void serialize(archive& ar) {
        ar(mc_pron);
        ar(字);
        ar(gloss); } };
/*struct dictionary_entry {
    std::string gloss;
    std::variant<std::tuple<std::string, mc_syllable>, mc_syllable> pron;
    std::string character;
    template<class archive>
    void serialize(archive& ar) {
        ar(gloss);
        ar(pron);
        ar(character); } };*/
std::string to_入聲(std::string fina) {
    using namespace std;
    if (std::string("m") == fina.substr(fina.size() + -std::string("m").size(), std::string("m").size())) {
        return fina.replace(fina.size() + -std::string("m").size(), std::string("m").size(), std::string("p")); }
    if (std::string("n") == fina.substr(fina.size() + -std::string("n").size(), std::string("n").size())) {
        return fina.replace(fina.size() + -std::string("n").size(), std::string("n").size(), std::string("t")); }
    if (std::string("ŋ") == fina.substr(fina.size() + -std::string("ŋ").size(), std::string("ŋ").size())) {
        return fina.replace(fina.size() + -std::string("ŋ").size(), std::string("ŋ").size(), std::string("k")); }
    return "???"; }
std::string add_diacritic(std::string segmental, std::string diacritic) {
    std::vector<std::string> vowels = {"æ̃", "æ", "ɑ̃", "ɑ", "ɛ", "ɐ", "œ", "ɔ", "ẽ", "e", "ɪ", "ə", "ɤ", "ø", "ʏ", "o", "i", "ɯ", "y", "ʉ", "u"};
    for (std::size_t i = 0; i < vowels.size(); i++) {
        std::size_t pos = segmental.find(vowels[i]);
        if (pos != std::string::npos) {
            segmental.insert(pos + vowels[i].size(), diacritic);
            return segmental; } }
    return "????"; }
std::string predict_鄴(uint8_t init, uint8_t fina, uint8_t 四聲) {
    using namespace std;
    string initial = mc_initial_data[init].鄴;
    bool has_medial_j = mc_final_data[fina].韻圖.等 == 6;
    bool has_medial_w = !mc_韻部_data[(uint32_t)mc_final_data[fina].韻圖.韻部].開合 && mc_final_data[fina].韻圖.合;
    string medial = has_medial_w ? has_medial_j ? "ɥ" : "w" : has_medial_j ? "j" : "";
    string rhyme = mc_韻部_data[(uint32_t)mc_final_data[fina].韻圖.韻部].鄴;
    if (3 == 四聲) {
        rhyme = to_入聲(rhyme); }
    string tone = 四聲_classes[四聲].diacritic;
    return add_diacritic(initial + medial + rhyme, tone); }
std::string predict_金陵(uint8_t init, uint8_t fina, uint8_t 四聲) {
    using namespace std;
    string initial = mc_initial_data[init].金陵.triggered && (string::npos != mc_韻部_data[(uint32_t)mc_final_data[fina].韻圖.韻部].金陵.find("y") || string::npos != mc_韻部_data[(uint32_t)mc_final_data[fina].韻圖.韻部].金陵.find("ø") || string::npos != mc_韻部_data[(uint32_t)mc_final_data[fina].韻圖.韻部].金陵.find("œ")) ? *mc_initial_data[init].金陵.triggered : mc_initial_data[init].金陵.elsewhere;
    bool has_medial_j = mc_final_data[fina].韻圖.等 == 6;
    bool has_medial_w = mc_final_data[fina].韻圖.合;
    string medial = has_medial_w ? has_medial_j ? "ɥ" : "w" : has_medial_j ? "j" : "";
    string rhyme = mc_韻部_data[(uint32_t)mc_final_data[fina].韻圖.韻部].金陵;
    if (3 == 四聲) {
        rhyme = to_入聲(rhyme); }
    string tone = 四聲_classes[四聲].diacritic;
    return add_diacritic(initial + medial + rhyme, tone); }
std::string predict_prelmc(uint8_t init, uint8_t fina, uint8_t 四聲) {
    using namespace std;
    bool α = mc_final_data[fina].prelmc_α && mc_initial_data[init].αβ == αβ::α;
    string initial = mc_initial_data[init].中唐長安.elsewhere;
    string final = α ? mc_final_data[fina].prelmc_α->elsewhere : mc_final_data[fina].prelmc.elsewhere;
    if (mc_initial_data[init].中唐長安.triggered && mc_final_data[fina].prelmc.F && !(init == 3 && (mc_final_data[fina].韻圖.韻部 == mc_韻部::東B || mc_final_data[fina].韻圖.韻部 == mc_韻部::尤))) {
        initial = *mc_initial_data[init].中唐長安.triggered;
        final = α ? *mc_final_data[fina].prelmc_α->F : *mc_final_data[fina].prelmc.F; }
    if (initial == "mb")
        final = α ? mc_final_data[fina].prelmc_α->m : mc_final_data[fina].prelmc.m;
    return add_diacritic(initial + final, 四聲_classes[四聲].diacritic); }
