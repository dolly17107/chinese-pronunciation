
#include <cinttypes>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <algorithm>
#include <magic_enum.hpp>
#include <js.h>
#include <emscripten/val.h>
#include <js/bind.hpp>
enum class 字母{ 不, 芳, 並, 明, 端, 透, 定, 泥, 知, 徹, 澄, 日, 見, 溪, 羣, 來, 疑, 精, 清, 從, 審, 穿, 禪, 照, 心, 邪, 曉, 匣, 喻, 影 };
std::unordered_map<std::string_view, 字母> const 字母_by_ipa{
    {"p", 字母::不}, {"pʰ", 字母::芳}, {"bʰ", 字母::並}, {"m", 字母::明},
    {"t", 字母::端}, {"tʰ", 字母::透}, {"dʰ", 字母::定}, {"n", 字母::泥},
    {"ţ", 字母::知}, {"ţʰ", 字母::徹}, {"ɖʰ", 字母::澄}, {"ɳ", 字母::泥},
    {"k", 字母::見}, {"kʰ", 字母::溪}, {"gʰ", 字母::羣}, {"ŋ", 字母::疑},
    {"ts", 字母::精}, {"tsʰ", 字母::清}, {"dzʰ", 字母::從}, {"s", 字母::心}, {"z", 字母::邪},
    {"ʧ", 字母::照}, {"ʧʰ", 字母::穿}, {"dʒʰ", 字母::禪}, {"ʃ", 字母::審}, {"dʐʰ", 字母::禪},
    {"tɕ", 字母::照}, {"tɕʰ", 字母::穿}, {"dʑʰ", 字母::禪}, {"ɕ", 字母::審}, {"ʑ", 字母::禪},
    {"ʔ", 字母::影}, {"x", 字母::曉}, {"ɣ", 字母::匣}, {"", 字母::喻}, {"j", 字母::喻},
    {"l", 字母::來}, {"nʑ", 字母::日}};
enum class 攝{通江, 止蟹, 臻山, Ｘ假, 宕梗, 流效, 深咸, 曾};
enum class 呼{開 = 0, 合_gliding = 1, 合_mono = 2};
enum class 轉等{內一, _1, 內三, 內四, 外一, 外二, 外三, 外四};
using 轉等_distribution = 轉等(*)(std::string_view, std::string_view);
namespace 轉等_distributions {
    轉等_distribution 內一 = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::內一}, {"pʰ", 轉等::內一}, {"bʰ", 轉等::內一}, {"m", 轉等::內一},
            {"t", 轉等::內一}, {"tʰ", 轉等::內一}, {"dʰ", 轉等::內一}, {"n", 轉等::內一},
            {"k", 轉等::內一}, {"kʰ", 轉等::內一}, {"ŋ", 轉等::內一},
            {"ts", 轉等::內一}, {"tsʰ", 轉等::內一}, {"dzʰ", 轉等::內一}, {"s", 轉等::內一},
            {"ʔ", 轉等::內一}, {"x", 轉等::內一}, {"ɣ", 轉等::內一},
            {"l", 轉等::內一}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 內三 = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::內三}, {"pʰ", 轉等::內三}, {"bʰ", 轉等::內三}, {"m", 轉等::內三},
            {"k", 轉等::內三}, {"kʰ", 轉等::內三}, {"gʰ", 轉等::內三}, {"ŋ", 轉等::內三},
            {"ʔ", 轉等::內三}, {"x", 轉等::內三}, {"", 轉等::內三}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 內四 = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::內四}, {"pʰ", 轉等::內四}, {"bʰ", 轉等::內四}, {"m", 轉等::內四},
            {"t", 轉等::內四}, {"tʰ", 轉等::內四}, {"dʰ", 轉等::內四}, {"n", 轉等::內四},
            {"k", 轉等::內四}, {"kʰ", 轉等::內四}, {"ŋ", 轉等::內四},
            {"ts", 轉等::內四}, {"tsʰ", 轉等::內四}, {"dzʰ", 轉等::內四}, {"s", 轉等::內四},
            {"ʔ", 轉等::內四}, {"x", 轉等::內四}, {"ɣ", 轉等::內四},
            {"l", 轉等::內四}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 外一 = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::外一}, {"pʰ", 轉等::外一}, {"bʰ", 轉等::外一}, {"m", 轉等::外一},
            {"t", 轉等::外一}, {"tʰ", 轉等::外一}, {"dʰ", 轉等::外一}, {"n", 轉等::外一},
            {"k", 轉等::外一}, {"kʰ", 轉等::外一}, {"ŋ", 轉等::外一},
            {"ts", 轉等::外一}, {"tsʰ", 轉等::外一}, {"dzʰ", 轉等::外一}, {"s", 轉等::外一},
            {"ʔ", 轉等::外一}, {"x", 轉等::外一}, {"ɣ", 轉等::外一},
            {"l", 轉等::外一}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 外二 = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::外二}, {"pʰ", 轉等::外二}, {"bʰ", 轉等::外二}, {"m", 轉等::外二},
            {"ţ", 轉等::外二}, {"ţʰ", 轉等::外二}, {"ɖʰ", 轉等::外二}, {"ɳ", 轉等::外二},
            {"k", 轉等::外二}, {"kʰ", 轉等::外二}, {"ŋ", 轉等::外二},
            {"ʧ", 轉等::外二}, {"ʧʰ", 轉等::外二}, {"dʒʰ", 轉等::外二}, {"ʃ", 轉等::外二},
            {"ʔ", 轉等::外一}, {"x", 轉等::外一}, {"ɣ", 轉等::外一},
            {"l", 轉等::外一}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 外三 = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::外三}, {"pʰ", 轉等::外三}, {"bʰ", 轉等::外三}, {"m", 轉等::外三},
            {"k", 轉等::外三}, {"kʰ", 轉等::外三}, {"gʰ", 轉等::外三}, {"ŋ", 轉等::外三},
            {"ʔ", 轉等::外三}, {"x", 轉等::外三}, {"", 轉等::外三}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 外四 = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::外四}, {"pʰ", 轉等::外四}, {"bʰ", 轉等::外四}, {"m", 轉等::外四},
            {"t", 轉等::外四}, {"tʰ", 轉等::外四}, {"dʰ", 轉等::外四}, {"n", 轉等::外四},
            {"k", 轉等::外四}, {"kʰ", 轉等::外四}, {"ŋ", 轉等::外四},
            {"ts", 轉等::外四}, {"tsʰ", 轉等::外四}, {"dzʰ", 轉等::外四}, {"s", 轉等::外四},
            {"ʔ", 轉等::外四}, {"x", 轉等::外四}, {"ɣ", 轉等::外四},
            {"l", 轉等::外四}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 內α = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::內四}, {"pʰ", 轉等::內四}, {"bʰ", 轉等::內四}, {"m", 轉等::內四},
            {"k", 轉等::內四}, {"kʰ", 轉等::內四}, {"gʰ", 轉等::內四}, {"ŋ", 轉等::內四},
            {"ts", 轉等::內四}, {"tsʰ", 轉等::內四}, {"dzʰ", 轉等::內四}, {"s", 轉等::內四}, {"z", 轉等::內四},
            {"tɕ", 轉等::內三}, {"tɕʰ", 轉等::內三}, {"dʑʰ", 轉等::內三}, {"ɕ", 轉等::內三}, {"ʑ", 轉等::內三},
            {"ʔ", 轉等::內四}, {"x", 轉等::內四}, {"j", 轉等::內四},
            {"nʑ", 轉等::內三}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 內β = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::內三}, {"pʰ", 轉等::內三}, {"bʰ", 轉等::內三}, {"m", 轉等::內三},
            {"ţ", 轉等::內三}, {"ţʰ", 轉等::內三}, {"ɖʰ", 轉等::內三}, {"ɳ", 轉等::內三},
            {"k", 轉等::內三}, {"kʰ", 轉等::內三}, {"gʰ", 轉等::內三}, {"ŋ", 轉等::內三},
            {"ʧ", 轉等::內一}, {"ʧʰ", 轉等::內一}, {"dʒʰ", 轉等::內一}, {"ʃ", 轉等::內一},
            {"ʔ", 轉等::內三}, {"x", 轉等::內三}, {"", 轉等::內三},
            {"l", 轉等::內三}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 內β_plus = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::內三}, {"pʰ", 轉等::內三}, {"bʰ", 轉等::內三}, {"m", 轉等::內三},
            {"ţ", 轉等::內三}, {"ţʰ", 轉等::內三}, {"ɖʰ", 轉等::內三}, {"ɳ", 轉等::內三},
            {"k", 轉等::內三}, {"kʰ", 轉等::內三}, {"gʰ", 轉等::內三}, {"ŋ", 轉等::內三},
            {"ts", 轉等::內三}, {"tsʰ", 轉等::內三}, {"dzʰ", 轉等::內三}, {"s", 轉等::內三}, {"z", 轉等::內三},
            {"ʧ", 轉等::內一}, {"ʧʰ", 轉等::內一}, {"dʒʰ", 轉等::內一}, {"ʃ", 轉等::內一}, {"dʐʰ", 轉等::內一},
            {"tɕ", 轉等::內三}, {"tɕʰ", 轉等::內三}, {"dʑʰ", 轉等::內三}, {"ɕ", 轉等::內三}, {"ʑ", 轉等::內三},
            {"ʔ", 轉等::內三}, {"x", 轉等::內三}, {"", 轉等::內三}, {"j", 轉等::內三},
            {"l", 轉等::內三}, {"nʑ", 轉等::內三}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 內αβ = [](std::string_view ipa_initial, std::string_view 小韻) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"ţ", 轉等::內三}, {"ţʰ", 轉等::內三}, {"ɖʰ", 轉等::內三}, {"ɳ", 轉等::內三},
            {"ts", 轉等::內四}, {"tsʰ", 轉等::內四}, {"dzʰ", 轉等::內四}, {"s", 轉等::內四}, {"z", 轉等::內四},
            {"ʧ", 轉等::內一}, {"ʧʰ", 轉等::內一}, {"dʒʰ", 轉等::內一}, {"ʃ", 轉等::內一}, {"dʐʰ", 轉等::內一},
            {"tɕ", 轉等::內三}, {"tɕʰ", 轉等::內三}, {"dʑʰ", 轉等::內三}, {"ɕ", 轉等::內三}, {"ʑ", 轉等::內三},
            {"", 轉等::內三}, {"j", 轉等::內四},
            {"l", 轉等::內三}, {"nʑ", 轉等::內三}}[ipa_initial].value_or([小韻]() {
                std::vector<std::tuple<std::string_view, 轉等>> table = {
                    {"祇 𤰞 陴 彌 詑 𤿎 𢔌 渳 婢 諀 企 枳 避 臂 譬 企 縊 馶", 轉等::內四},
                    {"隓 闚 𩓸 跬 觖 恚 瞡 孈", 轉等::內四},
                    {"糜 鈹 陂 竒 犧 㩻 宜 皮 羈 漪 靡 彼 被 技 倚 掎 綺 螘 㱟 𪖪 帔 賁 髲 寄 芰 議 倚 戲 㞆", 轉等::內三},
                    {"嬀 𪎮 逶 虧 危 毀 委 跪 詭 硊 跪 䞈 餧 僞 毀", 轉等::內三},
                    {"𣬈 伊 紕 咦 匕 牝 屁 棄 寐 鼻 痹", 轉等::內四},
                    {"葵 倠 揆 癸 䁤 悸 季 䁤 侐", 轉等::內四},
                    {"飢 鬐 眉 悲 邳 丕 狋 美 鄙 几 否 嚭 㰻 跽 郿 祕 濞 備 劓 冀 臮 懿 器 齂", 轉等::內三},
                    {"龜 逵 巋 軌 䣀 巋 匱 媿 喟 豷", 轉等::內三},
                    {"因 賔 繽 頻 民 𧼒 緊 牝 釿 泯 螼 脪 儐 印 𣎵 螼", 轉等::內四},
                    {"𥎊 銀 巾 珉 貧 𪔗 彬 砏 愍 菣 憗 衅 僅", 轉等::內三},
                    {"麏 囷 贇 窘", 轉等::內三},
                    {"一 匹 吉 詰 欯 蜜 必 邲", 轉等::內四},
                    {"姞 密 弼 乙 耴 筆 肸 曁", 轉等::內三},
                    {"䎉", 轉等::內三},
                    {"均 𦃢 呁", 轉等::內四},
                    {"獝 橘", 轉等::內四},
                    {"愔 坅", 轉等::內四},
                    {"琴 欽 吟 歆 金 音 噤 錦 僸 稟 㱃 品 𩖄 廞 𦧈 禁 蔭 吟", 轉等::內三},
                    {"揖", 轉等::內四},
                    {"及 急 岌 泣 吸 邑 𩾳 鵖", 轉等::內三},
                    {"恘䬌", 轉等::內四},
                    {"憂牛丘鳩不休𧚍浮謀", 轉等::內三}};
                std::vector<轉等> matches;
                std::for_each(table.begin(), table.end(), [小韻, &matches](std::tuple<std::string_view, 轉等> entry) {
                    if (std::string_view::npos != std::get<0>(entry).find(小韻)) {
                        matches.push_back(std::get<1>(entry)); } });
                if (1 == matches.size()) {
                    return matches[0]; }
                return 轉等::_1; }()); };
    轉等_distribution 外α = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::外四}, {"pʰ", 轉等::外四}, {"bʰ", 轉等::外四}, {"m", 轉等::外四},
            {"k", 轉等::外四}, {"kʰ", 轉等::外四}, {"gʰ", 轉等::外四}, {"ŋ", 轉等::外四},
            {"ts", 轉等::外四}, {"tsʰ", 轉等::外四}, {"dzʰ", 轉等::外四}, {"s", 轉等::外四}, {"z", 轉等::外四},
            {"tɕ", 轉等::外三}, {"tɕʰ", 轉等::外三}, {"dʑʰ", 轉等::外三}, {"ɕ", 轉等::外三}, {"ʑ", 轉等::外三},
            {"ʔ", 轉等::外四}, {"x", 轉等::外四}, {"j", 轉等::外四},
            {"nʑ", 轉等::外三}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 外β = [](std::string_view ipa_initial, std::string_view) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"p", 轉等::外三}, {"pʰ", 轉等::外三}, {"bʰ", 轉等::外三}, {"m", 轉等::外三},
            {"ţ", 轉等::外三}, {"ţʰ", 轉等::外三}, {"ɖʰ", 轉等::外三}, {"ɳ", 轉等::外三},
            {"k", 轉等::外三}, {"kʰ", 轉等::外三}, {"gʰ", 轉等::外三}, {"ŋ", 轉等::外三},
            {"ʧ", 轉等::外二}, {"ʧʰ", 轉等::外二}, {"dʒʰ", 轉等::外二}, {"ʃ", 轉等::外二},
            {"ʔ", 轉等::外三}, {"x", 轉等::外三}, {"", 轉等::外三},
            {"l", 轉等::外三}}[ipa_initial].value_or(轉等::_1); };
    轉等_distribution 外αβ = [](std::string_view ipa_initial, std::string_view 小韻) {
        return std::unordered_map<std::string_view, std::optional<轉等>>{
            {"ţ", 轉等::外三}, {"ţʰ", 轉等::外三}, {"ɖʰ", 轉等::外三}, {"ɳ", 轉等::外三},
            {"ts", 轉等::外四}, {"tsʰ", 轉等::外四}, {"dzʰ", 轉等::外四}, {"s", 轉等::外四}, {"z", 轉等::外四},
            {"ʧ", 轉等::外二}, {"ʧʰ", 轉等::外二}, {"dʒʰ", 轉等::外二}, {"ʃ", 轉等::外二}, {"dʐʰ", 轉等::外二},
            {"tɕ", 轉等::外三}, {"tɕʰ", 轉等::外三}, {"dʑʰ", 轉等::外三}, {"ɕ", 轉等::外三}, {"ʑ", 轉等::外三},
            {"", 轉等::外三}, {"j", 轉等::外四},
            {"l", 轉等::外三}, {"nʑ", 轉等::外三}}[ipa_initial].value_or([小韻]() {
                std::vector<std::tuple<std::string_view, 轉等>> table = {
                    {"𡚁 蔽 袂 藝 潎", 轉等::外四},
                    {"", 轉等::外四},
                    {"䋵 憩 猘 偈 㓷", 轉等::外三},
                    {"劌", 轉等::外三},
                    {"甄 嘕 篇 便 緜 鞭 遣 緬 褊 楩 譴 面 躽 騗 便", 轉等::外四},
                    {"翾 娟 蜎 蠉 絹", 轉等::外四},
                    {"乾 愆 焉 蹇 齴 件 辯 辡 免 鴘 㫃 彥 變 卞", 轉等::外三},
                    {"權 弮 嬽 勬 卷 圈 眷 倦 𥛁", 轉等::外三},
                    {"滅 鷩 瞥", 轉等::外四},
                    {"缺 妜", 轉等::外四},
                    {"傑 孼 朅 别 䇷 孑 焆 娎", 轉等::外三},
                    {"噦 𥄎 蹶", 轉等::外三},
                    {"飊 瓢 蜱 要 蹻 爂 翹 摽 縹 眇 褾 闄 要 剽 妙 驃 翹", 轉等::外四},
                    {"嚻 驕 鑣 苗 喬 妖 趫 夭 矯 表 藨 𨲭 麃 嶠 趬 𧇠 廟 裱", 轉等::外三},
                    {"嬰 輕 名 并 頸 痙 頸 餅 廮 眳 勁 聘 摒 偋 詺 輕 𣢝", 轉等::外四},
                    {"傾 縈 瓊 𧵣 頃 敻", 轉等::外四},
                    {"益 擗 辟 僻", 轉等::外四},
                    {"瞁", 轉等::外四},
                    {"懕 鍼 黶 脥 厭", 轉等::外四},
                    {"砭 淹 𢜩 𪙊 箝 險 貶 𩑳 顩 儉 檢 奄 窆 驗 𢜰", 轉等::外三},
                    {"𤷾 魘", 轉等::外四},
                    {"𢽱 衱 𦀖", 轉等::外三}};
                std::vector<轉等> matches;
                std::for_each(table.begin(), table.end(), [小韻, &matches](std::tuple<std::string_view, 轉等> entry) {
                    if (std::string_view::npos != std::get<0>(entry).find(小韻)) {
                        matches.push_back(std::get<1>(entry)); } });
                if (1 == matches.size()) {
                    return matches[0]; }
                return 轉等::_1; }()); }; }
struct 呼轉等攝入 {
    呼 呼;
    轉等_distribution 轉等;
    攝 攝;
    bool 入; };
std::unordered_map<std::string_view, 呼轉等攝入> const 呼轉等攝入_by_ipa{
    {"uŋ", {呼::開, 轉等_distributions::內一, 攝::通江, 0}},
    {"uk", {呼::開, 轉等_distributions::內一, 攝::通江, 1}},
    {"ĭuŋ", {呼::開, 轉等_distributions::內β_plus, 攝::通江, 0}},
    {"ĭuk", {呼::開, 轉等_distributions::內β_plus, 攝::通江, 1}},
    {"uoŋ", {呼::合_mono, 轉等_distributions::內一, 攝::通江, 0}},
    {"uok", {呼::合_mono, 轉等_distributions::內一, 攝::通江, 1}},
    {"ĭwoŋ", {呼::合_mono, 轉等_distributions::內β_plus, 攝::通江, 0}},
    {"ĭwok", {呼::合_mono, 轉等_distributions::內β_plus, 攝::通江, 1}},
    {"ɔŋ", {呼::開, 轉等_distributions::外二, 攝::通江, 0}},
    {"ɔk", {呼::開, 轉等_distributions::外二, 攝::通江, 1}},
    {"ĭe", {呼::開, 轉等_distributions::內αβ, 攝::止蟹, 0}},
    {"i", {呼::開, 轉等_distributions::內αβ, 攝::止蟹, 0}},
    {"ĭə", {呼::開, 轉等_distributions::內αβ, 攝::止蟹, 0}},
    {"ĭəi", {呼::開, 轉等_distributions::內三, 攝::止蟹, 0}},
    {"ĭwe", {呼::合_gliding, 轉等_distributions::內αβ, 攝::止蟹, 0}},
    {"wi", {呼::合_gliding, 轉等_distributions::內αβ, 攝::止蟹, 0}},
    {"ĭwəi", {呼::合_gliding, 轉等_distributions::內三, 攝::止蟹, 0}},
    {"ɒi", {呼::開, 轉等_distributions::外一, 攝::止蟹, 0}},
    {"ɑi", {呼::開, 轉等_distributions::外一, 攝::止蟹, 0}},
    {"ɐi", {呼::開, 轉等_distributions::外二, 攝::止蟹, 0}},
    {"æi", {呼::開, 轉等_distributions::外二, 攝::止蟹, 0}},
    {"ai", {呼::開, 轉等_distributions::外二, 攝::止蟹, 0}},
    {"ĭɛi", {呼::開, 轉等_distributions::外αβ, 攝::止蟹, 0}},
    {"ĭɐi", {呼::開, 轉等_distributions::外三, 攝::止蟹, 0}},
    {"iei", {呼::開, 轉等_distributions::外四, 攝::止蟹, 0}},
    {"uɒi", {呼::合_gliding, 轉等_distributions::外一, 攝::止蟹, 0}},
    {"uɑi", {呼::合_gliding, 轉等_distributions::外一, 攝::止蟹, 0}},
    {"wɐi", {呼::合_gliding, 轉等_distributions::外二, 攝::止蟹, 0}},
    {"wæi", {呼::合_gliding, 轉等_distributions::外二, 攝::止蟹, 0}},
    {"wai", {呼::合_gliding, 轉等_distributions::外二, 攝::止蟹, 0}},
    {"ĭwɛi", {呼::合_gliding, 轉等_distributions::外αβ, 攝::止蟹, 0}},
    {"ĭwɐi", {呼::合_gliding, 轉等_distributions::外三, 攝::止蟹, 0}},
    {"iwei", {呼::合_gliding, 轉等_distributions::外四, 攝::止蟹, 0}},
    {"ən", {呼::開, 轉等_distributions::內一, 攝::臻山, 0}},
    {"ət", {呼::開, 轉等_distributions::內一, 攝::臻山, 1}},
    {"ĭĕn", {呼::開, 轉等_distributions::內αβ, 攝::臻山, 0}},
    {"ĭĕt", {呼::開, 轉等_distributions::內αβ, 攝::臻山, 1}},
    {"ĭen", {呼::開, 轉等_distributions::內αβ, 攝::臻山, 0}},
    {"ĭet", {呼::開, 轉等_distributions::內αβ, 攝::臻山, 1}},
    {"ĭən", {呼::開, 轉等_distributions::內三, 攝::臻山, 0}},
    {"ĭət", {呼::開, 轉等_distributions::內三, 攝::臻山, 1}},
    {"uən", {呼::合_gliding, 轉等_distributions::內一, 攝::臻山, 0}},
    {"uət", {呼::合_gliding, 轉等_distributions::內一, 攝::臻山, 1}},
    {"ĭwĕn", {呼::合_gliding, 轉等_distributions::內αβ, 攝::臻山, 0}},
    {"ĭwĕt", {呼::合_gliding, 轉等_distributions::內αβ, 攝::臻山, 1}},
    {"ĭuĕn", {呼::合_gliding, 轉等_distributions::內αβ, 攝::臻山, 0}},
    {"ĭuĕt", {呼::合_gliding, 轉等_distributions::內αβ, 攝::臻山, 1}},
    {"ĭuən", {呼::合_gliding, 轉等_distributions::內三, 攝::臻山, 0}},
    {"ĭuət", {呼::合_gliding, 轉等_distributions::內三, 攝::臻山, 1}},
    {"ɑn", {呼::開, 轉等_distributions::外一, 攝::臻山, 0}},
    {"ɑt", {呼::開, 轉等_distributions::外一, 攝::臻山, 1}},
    {"an", {呼::開, 轉等_distributions::外二, 攝::臻山, 0}},
    {"at", {呼::開, 轉等_distributions::外二, 攝::臻山, 1}},
    {"æn", {呼::開, 轉等_distributions::外二, 攝::臻山, 0}},
    {"æt", {呼::開, 轉等_distributions::外二, 攝::臻山, 1}},
    {"ĭɐn", {呼::開, 轉等_distributions::外三, 攝::臻山, 0}},
    {"ĭɐt", {呼::開, 轉等_distributions::外三, 攝::臻山, 1}},
    {"ĭɛn", {呼::開, 轉等_distributions::外αβ, 攝::臻山, 0}},
    {"ĭɛt", {呼::開, 轉等_distributions::外αβ, 攝::臻山, 1}},
    {"ien", {呼::開, 轉等_distributions::外四, 攝::臻山, 0}},
    {"iet", {呼::開, 轉等_distributions::外四, 攝::臻山, 1}},
    {"uɑn", {呼::合_gliding, 轉等_distributions::外一, 攝::臻山, 0}},
    {"uɑt", {呼::合_gliding, 轉等_distributions::外一, 攝::臻山, 1}},
    {"wan", {呼::合_gliding, 轉等_distributions::外二, 攝::臻山, 0}},
    {"wat", {呼::合_gliding, 轉等_distributions::外二, 攝::臻山, 1}},
    {"wæn", {呼::合_gliding, 轉等_distributions::外二, 攝::臻山, 0}},
    {"wæt", {呼::合_gliding, 轉等_distributions::外二, 攝::臻山, 1}},
    {"ĭwɐn", {呼::合_gliding, 轉等_distributions::外三, 攝::臻山, 0}},
    {"ĭwɐt", {呼::合_gliding, 轉等_distributions::外三, 攝::臻山, 1}},
    {"ĭwɛn", {呼::合_gliding, 轉等_distributions::外αβ, 攝::臻山, 0}},
    {"ĭwɛt", {呼::合_gliding, 轉等_distributions::外αβ, 攝::臻山, 1}},
    {"iwen", {呼::合_gliding, 轉等_distributions::外四, 攝::臻山, 0}},
    {"iwet", {呼::合_gliding, 轉等_distributions::外四, 攝::臻山, 1}},
    {"ɑ", {呼::開, 轉等_distributions::內一, 攝::Ｘ假, 0}},
    {"ĭo", {呼::開, 轉等_distributions::內β_plus, 攝::Ｘ假, 0}},
    {"ĭɑ", {呼::開, 轉等_distributions::內三, 攝::Ｘ假, 0}},
    {"uɑ", {呼::合_gliding, 轉等_distributions::內一, 攝::Ｘ假, 0}},
    {"ĭuɑ", {呼::合_gliding, 轉等_distributions::內三, 攝::Ｘ假, 0}},
    {"u", {呼::合_mono, 轉等_distributions::內一, 攝::Ｘ假, 0}},
    {"ĭu", {呼::合_mono, 轉等_distributions::內β_plus, 攝::Ｘ假, 0}},
    {"a", {呼::開, 轉等_distributions::外二, 攝::Ｘ假, 0}},
    {"ĭa", {呼::開, 轉等_distributions::外α, 攝::Ｘ假, 0}},
    {"wa", {呼::合_gliding, 轉等_distributions::外二, 攝::Ｘ假, 0}},
    {"ɑŋ", {呼::開, 轉等_distributions::內一, 攝::宕梗, 0}},
    {"ɑk", {呼::開, 轉等_distributions::內一, 攝::宕梗, 1}},
    {"ĭaŋ", {呼::開, 轉等_distributions::內β_plus, 攝::宕梗, 0}},
    {"ĭak", {呼::開, 轉等_distributions::內β_plus, 攝::宕梗, 1}},
    {"uɑŋ", {呼::合_gliding, 轉等_distributions::內一, 攝::宕梗, 0}},
    {"uɑk", {呼::合_gliding, 轉等_distributions::內一, 攝::宕梗, 1}},
    {"ĭwaŋ", {呼::合_gliding, 轉等_distributions::內β_plus, 攝::宕梗, 0}},
    {"ĭwak", {呼::合_gliding, 轉等_distributions::內β_plus, 攝::宕梗, 1}},
    {"ɐŋ", {呼::開, 轉等_distributions::外二, 攝::宕梗, 0}},
    {"ɐk", {呼::開, 轉等_distributions::外二, 攝::宕梗, 1}},
    {"æŋ", {呼::開, 轉等_distributions::外二, 攝::宕梗, 0}},
    {"æk", {呼::開, 轉等_distributions::外二, 攝::宕梗, 1}},
    {"ĭɐŋ", {呼::開, 轉等_distributions::外β, 攝::宕梗, 0}},
    {"ĭɐk", {呼::開, 轉等_distributions::外β, 攝::宕梗, 1}},
    {"ĭɛŋ", {呼::開, 轉等_distributions::外αβ, 攝::宕梗, 0}},
    {"ĭɛk", {呼::開, 轉等_distributions::外αβ, 攝::宕梗, 1}},
    {"ieŋ", {呼::開, 轉等_distributions::外四, 攝::宕梗, 0}},
    {"iek", {呼::開, 轉等_distributions::外四, 攝::宕梗, 1}},
    {"wɐŋ", {呼::合_gliding, 轉等_distributions::外二, 攝::宕梗, 0}},
    {"wɐk", {呼::合_gliding, 轉等_distributions::外二, 攝::宕梗, 1}},
    {"wæŋ", {呼::合_gliding, 轉等_distributions::外二, 攝::宕梗, 0}},
    {"wæk", {呼::合_gliding, 轉等_distributions::外二, 攝::宕梗, 1}},
    {"ĭwɐŋ", {呼::合_gliding, 轉等_distributions::外β, 攝::宕梗, 0}},
    {"ĭwɐk", {呼::合_gliding, 轉等_distributions::外β, 攝::宕梗, 1}},
    {"ĭwɛŋ", {呼::合_gliding, 轉等_distributions::外αβ, 攝::宕梗, 0}},
    {"ĭwɛŋ", {呼::合_gliding, 轉等_distributions::外αβ, 攝::宕梗, 0}},
    {"iweŋ", {呼::合_gliding, 轉等_distributions::外四, 攝::宕梗, 0}},
    {"iwek", {呼::合_gliding, 轉等_distributions::外四, 攝::宕梗, 1}},
    {"əu", {呼::開, 轉等_distributions::內一, 攝::流效, 0}},
    {"ĭəu", {呼::開, 轉等_distributions::內αβ, 攝::流效, 0}},
    {"iəu", {呼::開, 轉等_distributions::內α, 攝::流效, 0}},
    {"ɑu", {呼::開, 轉等_distributions::外一, 攝::流效, 0}},
    {"au", {呼::開, 轉等_distributions::外二, 攝::流效, 0}},
    {"ĭɛu", {呼::開, 轉等_distributions::外αβ, 攝::流效, 0}},
    {"ieu", {呼::開, 轉等_distributions::外四, 攝::流效, 0}},
    {"ĭĕm", {呼::開, 轉等_distributions::內αβ, 攝::深咸, 0}},
    {"ĭĕp", {呼::開, 轉等_distributions::內αβ, 攝::深咸, 1}},
    {"ɒm", {呼::開, 轉等_distributions::外一, 攝::深咸, 0}},
    {"ɒp", {呼::開, 轉等_distributions::外一, 攝::深咸, 1}},
    {"ɑm", {呼::開, 轉等_distributions::外一, 攝::深咸, 0}},
    {"ɑp", {呼::開, 轉等_distributions::外一, 攝::深咸, 1}},
    {"ɐm", {呼::開, 轉等_distributions::外二, 攝::深咸, 0}},
    {"ɐp", {呼::開, 轉等_distributions::外二, 攝::深咸, 1}},
    {"am", {呼::開, 轉等_distributions::外二, 攝::深咸, 0}},
    {"ap", {呼::開, 轉等_distributions::外二, 攝::深咸, 1}},
    {"ĭɛm", {呼::開, 轉等_distributions::外αβ, 攝::深咸, 0}},
    {"ĭɛp", {呼::開, 轉等_distributions::外αβ, 攝::深咸, 1}},
    {"ĭɐm", {呼::開, 轉等_distributions::外三, 攝::深咸, 0}},
    {"ĭɐp", {呼::開, 轉等_distributions::外三, 攝::深咸, 1}},
    {"ĭwɐm", {呼::開, 轉等_distributions::外三, 攝::深咸, 0}},
    {"ĭwɐp", {呼::開, 轉等_distributions::外三, 攝::深咸, 1}},
    {"iem", {呼::開, 轉等_distributions::外四, 攝::深咸, 0}},
    {"iep", {呼::開, 轉等_distributions::外四, 攝::深咸, 1}},
    {"əŋ", {呼::開, 轉等_distributions::內一, 攝::曾, 0}},
    {"ək", {呼::開, 轉等_distributions::內一, 攝::曾, 1}},
    {"ĭəŋ", {呼::開, 轉等_distributions::內β_plus, 攝::曾, 0}},
    {"ĭək", {呼::開, 轉等_distributions::內β_plus, 攝::曾, 1}},
    {"uəŋ", {呼::合_gliding, 轉等_distributions::內一, 攝::曾, 0}},
    {"uək", {呼::合_gliding, 轉等_distributions::內一, 攝::曾, 1}},
    {"ĭwəŋ", {呼::合_gliding, 轉等_distributions::內β_plus, 攝::曾, 0}},
    {"ĭwək", {呼::合_gliding, 轉等_distributions::內β_plus, 攝::曾, 1}}};
/*std::unordered_map<呼轉等攝去, > const pre_lmc_by_coordinate{
    {{呼::開, 轉等_distributions::內一, 攝::通江}, {"ɤwŋ", "oŋ"}},
    {{呼::開, 轉等_distributions::內一, 攝::通江}, {"ɤwk", "ok"}},
    {{呼::開, 轉等_distributions::內β_plus, 攝::通江}, {"ɯwŋ", "ɤwŋ", "ɤwŋ/uŋ competing"}},
    {{呼::開, 轉等_distributions::內β_plus, 攝::通江}, {"ɯwk", "ɤwk", "ɤwk/uk competing"}},
    {{呼::合_mono, 轉等_distributions::內一, 攝::通江}, {"ɤwŋ", "oŋ"}},
    {{呼::合_mono, 轉等_distributions::內一, 攝::通江}, {"ɤwk", "ok"}},
    {{呼::合_mono, 轉等_distributions::內β_plus, 攝::通江}, {"wɯɤwŋ", "wɯɤwŋ", "ɤwŋ"}},
    {{呼::合_mono, 轉等_distributions::內β_plus, 攝::通江}, {"wɯɤwk", "wɯɤwk", "ɤwk"}},
    {{呼::開, 轉等_distributions::外二, 攝::通江}, {"æwŋ", "æwŋ"}},
    {{呼::開, 轉等_distributions::外二, 攝::通江}, {"æwk", "æwk"}},
    {{呼::開, 轉等_distributions::內β, 攝::止蟹}, {"ɯj", "ɯj"}}, // conflict
    {{呼::開, 轉等_distributions::內α, 攝::止蟹}, {"ij", "ij"}},
    {{呼::開, 轉等_distributions::內三, 攝::止蟹}, {"ɯj", "ɯj", "ɤj"}}, // conflict
    {{呼::合_gliding, 轉等_distributions::內β, 攝::止蟹}, {"wɯj", "wɯj"}}, // conflict
    {{呼::合_gliding, 轉等_distributions::內α, 攝::止蟹}, {"wij", "wij"}},
    {{呼::合_gliding, 轉等_distributions::內三, 攝::止蟹}, {"wɯj", "wɯj"}}, // conflict
    {{呼::開, 轉等_distributions::外一, 攝::止蟹}, {"ɑj", "ɑj"}},
    {{呼::開, 轉等_distributions::外二, 攝::止蟹}, {"æj", "æj"}}, // conflict
    {{呼::開, 轉等_distributions::外二, 攝::止蟹}, {"æ/æj dialectal mixture", "æ/æj dialectal mixture"}}, // conflict
    {{呼::開, 轉等_distributions::外β, 攝::止蟹}, {"ej", "ej"}},
    {{呼::開, 轉等_distributions::外α, 攝::止蟹}, {"iej", "iej"}}, // repeat
    {{呼::開, 轉等_distributions::外四, 攝::止蟹}, {"iej", "iej"}}, // repeat
    {{呼::合_gliding, 轉等_distributions::外一, 攝::止蟹}, {"wɑj", "wɑj"}},
    {{呼::合_gliding, 轉等_distributions::外二, 攝::止蟹}, {"wæj", "wæj"}}, // conflict
    {{呼::合_gliding, 轉等_distributions::外二, 攝::止蟹}, {"wæ/wæj dialectal mixture", "wæ/wæj dialectal mixture"}}, // conflict
    {{呼::合_gliding, 轉等_distributions::外β, 攝::止蟹}, {"wej", "wej"}},
    {{呼::合_gliding, 轉等_distributions::外α, 攝::止蟹}, {"wiej", "wiej"}}, // repeat
    {{呼::合_gliding, 轉等_distributions::外四, 攝::止蟹}, {"wiej", "wiej"}}, // repeat
    {{呼::開, 轉等_distributions::內一, 攝::臻山}, {"ɤn", "ɤn"}},
    {{呼::開, 轉等_distributions::內一, 攝::臻山}, {"ɤt", "ɤt"}},
    {{呼::開, 轉等_distributions::內β, 攝::臻山}, {"ɯn", "ɯn"}},
    {{呼::開, 轉等_distributions::內β, 攝::臻山}, {"ɯt", "ɯt"}},
    {{呼::開, 轉等_distributions::內α, 攝::臻山}, {"in", "in"}},
    {{呼::開, 轉等_distributions::內α, 攝::臻山}, {"it", "it"}},
    {{呼::合_gliding, 轉等_distributions::內一, 攝::臻山}, {"wɤn", "wɤn"}},
    {{呼::合_gliding, 轉等_distributions::內一, 攝::臻山}, {"wɤt", "wɤt"}},
    {{呼::合_gliding, 轉等_distributions::內β, 攝::臻山}, {"wɯn", "wɯn"}},
    {{呼::合_gliding, 轉等_distributions::內β, 攝::臻山}, {"wɯt", "wɯt"}},
    {{呼::合_gliding, 轉等_distributions::內α, 攝::臻山}, {"win", "win"}},
    {{呼::合_gliding, 轉等_distributions::內α, 攝::臻山}, {"wit", "wit"}},
    {{呼::開, 轉等_distributions::外一, 攝::臻山}, {"ɑn", "ɑn"}},
    {{呼::開, 轉等_distributions::外一, 攝::臻山}, {"ɑt", "ɑt"}},
    {{呼::開, 轉等_distributions::外二, 攝::臻山}, {"æn", "æn"}},
    {{呼::開, 轉等_distributions::外二, 攝::臻山}, {"æt", "æt"}},
    {{呼::開, 轉等_distributions::外三, 攝::臻山}, {"en", "en", "æn"}},
    {{呼::開, 轉等_distributions::外三, 攝::臻山}, {"et", "et", "æt"}},
    {{呼::開, 轉等_distributions::外β, 攝::臻山}, {"en", "en"}},
    {{呼::開, 轉等_distributions::外β, 攝::臻山}, {"et", "et"}},
    {{呼::開, 轉等_distributions::外α, 攝::臻山}, {"ien", "ien"}},
    {{呼::開, 轉等_distributions::外α, 攝::臻山}, {"iet", "iet"}},
    {{呼::開, 轉等_distributions::外四, 攝::臻山}, {"ien", "ien"}},
    {{呼::開, 轉等_distributions::外四, 攝::臻山}, {"iet", "iet"}},
    {{呼::合_gliding, 轉等_distributions::外一, 攝::臻山}, {"wɑn", "wɑn"}},
    {{呼::合_gliding, 轉等_distributions::外一, 攝::臻山}, {"wɑt", "wɑt"}},
    {{呼::合_gliding, 轉等_distributions::外二, 攝::臻山}, {"wæn", "wæn"}},
    {{呼::合_gliding, 轉等_distributions::外二, 攝::臻山}, {"wæt", "wæt"}},
    {{呼::合_gliding, 轉等_distributions::外三, 攝::臻山}, {"wen", "wen"}},
    {{呼::合_gliding, 轉等_distributions::外三, 攝::臻山}, {"wet", "wet"}},
    {{呼::合_gliding, 轉等_distributions::外β, 攝::臻山}, {"wen", "wen"}},
    {{呼::合_gliding, 轉等_distributions::外β, 攝::臻山}, {"wet", "wet"}},
    {{呼::合_gliding, 轉等_distributions::外α, 攝::臻山}, {"wien", "wien"}},
    {{呼::合_gliding, 轉等_distributions::外α, 攝::臻山}, {"wiet", "wiet"}},
    {{呼::合_gliding, 轉等_distributions::外四, 攝::臻山}, {"wien", "wien"}},
    {{呼::合_gliding, 轉等_distributions::外四, 攝::臻山}, {"wiet", "wiet"}},
    {{呼::開, 轉等_distributions::內一, 攝::Ｘ假}, {"ɑ", "ɑ"}},
    {{呼::開, 轉等_distributions::內β_plus, 攝::Ｘ假}, {"ɯɤ", "ɯɤ", "ɯɤ"}},
    {{呼::開, 轉等_distributions::內三, 攝::Ｘ假}, {"ɯɑ", "ɯɑ"}},
    {{呼::合_gliding, 轉等_distributions::內一, 攝::Ｘ假}, {"wɑ", "wɑ"}},
    {{呼::合_gliding, 轉等_distributions::內三, 攝::Ｘ假}, {"wɯɑ", "wɯɑ"}},
    {{呼::合_mono, 轉等_distributions::內一, 攝::Ｘ假}, {"o", "o"}},
    {{呼::合_mono, 轉等_distributions::內β_plus, 攝::Ｘ假}, {"u", "u", "u"}},
    {{呼::開, 轉等_distributions::外二, 攝::Ｘ假}, {"æ", "æ"}},
    {{呼::開, 轉等_distributions::外α, 攝::Ｘ假}, {"iæ", "iæ"}},
    {{呼::合_gliding, 轉等_distributions::外二, 攝::Ｘ假}, {"wæ", "wæ"}},
    {{呼::開, 轉等_distributions::內一, 攝::宕梗}, {"ɑ̃", "ɑ̃"}},
    {{呼::開, 轉等_distributions::內一, 攝::宕梗}, {"ɑk", "ɑk"}},
    {{呼::開, 轉等_distributions::內β_plus, 攝::宕梗}, {"ɯɑ̃", "ɯɑ̃", "ɑ̃"}},
    {{呼::開, 轉等_distributions::內β_plus, 攝::宕梗}, {"ɯɑk", "ɯɑk", "ɑk"}},
    {{呼::合_gliding, 轉等_distributions::內一, 攝::宕梗}, {"wɑ̃", "wɑ̃"}},
    {{呼::合_gliding, 轉等_distributions::內一, 攝::宕梗}, {"wɑk", "wɑk"}},
    {{呼::合_gliding, 轉等_distributions::內β_plus, 攝::宕梗}, {"wɯɑ̃", "wɯɑ̃"}},
    {{呼::合_gliding, 轉等_distributions::內β_plus, 攝::宕梗}, {"wɯɑk", "wɯɑk"}},
    {{呼::開, 轉等_distributions::外二, 攝::宕梗}, {"æ̃j", "æ̃j"}},
    {{呼::開, 轉等_distributions::外二, 攝::宕梗}, {"æc", "æc"}},
    {{呼::開, 轉等_distributions::外二, 攝::宕梗}, {"æ̃j", "æ̃j"}},
    {{呼::開, 轉等_distributions::外二, 攝::宕梗}, {"æc", "æc"}},
    {{呼::開, 轉等_distributions::外β, 攝::宕梗}, {"ẽj", "ẽj"}},
    {{呼::開, 轉等_distributions::外β, 攝::宕梗}, {"ec", "ec"}},
    {{呼::開, 轉等_distributions::外β, 攝::宕梗}, {"ẽj", "ẽj"}},
    {{呼::開, 轉等_distributions::外β, 攝::宕梗}, {"ec", "ec"}},
    {{呼::開, 轉等_distributions::外α, 攝::宕梗}, {"iẽj", "iẽj"}},
    {{呼::開, 轉等_distributions::外α, 攝::宕梗}, {"iec", "iec"}},
    {{呼::開, 轉等_distributions::外四, 攝::宕梗}, {"iẽj", "iẽj"}},
    {{呼::開, 轉等_distributions::外四, 攝::宕梗}, {"iec", "iec"}},
    {{呼::合_gliding, 轉等_distributions::外二, 攝::宕梗}, {"wæ̃j", "wæ̃j"}},
    {{呼::合_gliding, 轉等_distributions::外二, 攝::宕梗}, {"wæc", "wæc"}},
    {{呼::合_gliding, 轉等_distributions::外二, 攝::宕梗}, {"wæ̃j", "wæ̃j"}},
    {{呼::合_gliding, 轉等_distributions::外二, 攝::宕梗}, {"wæc", "wæc"}},
    {{呼::合_gliding, 轉等_distributions::外β, 攝::宕梗}, {"wẽj", "wẽj"}},
    {{呼::合_gliding, 轉等_distributions::外β, 攝::宕梗}, {"wec", "wec"}},
    {{呼::合_gliding, 轉等_distributions::外β, 攝::宕梗}, {"wẽj", "wẽj"}},
    {{呼::合_gliding, 轉等_distributions::外β, 攝::宕梗}, {"wec", "wec"}},
    {{呼::合_gliding, 轉等_distributions::外α, 攝::宕梗}, {"wiẽj", "wiẽj"}},
    {{呼::合_gliding, 轉等_distributions::外α, 攝::宕梗}, {"wiec", "wiec"}},
    {{呼::合_gliding, 轉等_distributions::外四, 攝::宕梗}, {"wiẽj", "wiẽj"}},
    {{呼::合_gliding, 轉等_distributions::外四, 攝::宕梗}, {"wiec", "wiec"}},
    {{呼::開, 轉等_distributions::內一, 攝::流效}, {"ɤw", "o"}},
    {{呼::開, 轉等_distributions::內β, 攝::流效}, {"ɯw", "ɤw", "ɤw/u competing"}},
    {{呼::開, 轉等_distributions::內α, 攝::流效}, {"iw", "iw", "iw"}},
    {{呼::開, 轉等_distributions::內α, 攝::流效}, {"iw", "iw"}},
    {{呼::開, 轉等_distributions::外一, 攝::流效}, {"ɑw", "ɑw"}},
    {{呼::開, 轉等_distributions::外二, 攝::流效}, {"æw", "æw"}},
    {{呼::開, 轉等_distributions::外β, 攝::流效}, {"ew", "ew"}},
    {{呼::開, 轉等_distributions::外α, 攝::流效}, {"iew", "iew"}},
    {{呼::開, 轉等_distributions::外四, 攝::流效}, {"iew", "iew"}},
    {{呼::開, 轉等_distributions::內β, 攝::深咸}, {"ɯm", "ɯm"}},
    {{呼::開, 轉等_distributions::內β, 攝::深咸}, {"ɯp", "ɯp"}},
    {{呼::開, 轉等_distributions::內α, 攝::深咸}, {"im", "im"}},
    {{呼::開, 轉等_distributions::內α, 攝::深咸}, {"ip", "ip"}},
    {{呼::開, 轉等_distributions::外一, 攝::深咸}, {"ɑm", "ɑm"}},
    {{呼::開, 轉等_distributions::外一, 攝::深咸}, {"ɑp", "ɑp"}},
    {{呼::開, 轉等_distributions::外一, 攝::深咸}, {"ɑm", "ɑm"}},
    {{呼::開, 轉等_distributions::外一, 攝::深咸}, {"ɑp", "ɑp"}},
    {{呼::開, 轉等_distributions::外二, 攝::深咸}, {"æm", "æn"}},
    {{呼::開, 轉等_distributions::外二, 攝::深咸}, {"æp", "æp"}},
    {{呼::開, 轉等_distributions::外二, 攝::深咸}, {"æm", "æn"}},
    {{呼::開, 轉等_distributions::外二, 攝::深咸}, {"æp", "æp"}},
    {{呼::開, 轉等_distributions::外β, 攝::深咸}, {"em", "em"}},
    {{呼::開, 轉等_distributions::外β, 攝::深咸}, {"ep", "ep"}},
    {{呼::開, 轉等_distributions::外α, 攝::深咸}, {"iem", "iem"}},
    {{呼::開, 轉等_distributions::外α, 攝::深咸}, {"iep", "iep"}},
    {{呼::開, 轉等_distributions::外三, 攝::深咸}, {"em", "em", "æm"}},
    {{呼::開, 轉等_distributions::外三, 攝::深咸}, {"ep", "ep", "æp"}},
    {{呼::開, 轉等_distributions::外三, 攝::深咸}, {"em", "em", "æm"}},
    {{呼::開, 轉等_distributions::外三, 攝::深咸}, {"ep", "ep", "æp"}},
    {{呼::開, 轉等_distributions::外四, 攝::深咸}, {"iem", "iem"}},
    {{呼::開, 轉等_distributions::外四, 攝::深咸}, {"iep", "iep"}},
    {{呼::開, 轉等_distributions::內一, 攝::曾}, {"ɤŋ", "ɤŋ"}},
    {{呼::開, 轉等_distributions::內一, 攝::曾}, {"ɤk", "ɤk"}},
    {{呼::開, 轉等_distributions::內β_plus, 攝::曾}, {"ɯɤŋ", "ɯɤŋ"}},
    {{呼::開, 轉等_distributions::內β_plus, 攝::曾}, {"ɯɤk", "ɯɤk"}},
    {{呼::合_gliding, 轉等_distributions::內一, 攝::曾}, {"wɤŋ", "wɤŋ"}},
    {{呼::合_gliding, 轉等_distributions::內一, 攝::曾}, {"wɤk", "wɤk"}},
    {{呼::合_gliding, 轉等_distributions::內β_plus, 攝::曾}, {"wɯɤŋ", "wɯɤŋ"}},
    {{呼::合_gliding, 轉等_distributions::內β_plus, 攝::曾}, {"wɯɤk", "wɯɤk"}}};*/
enum class 四聲{平, 上, 去, 入};
std::unordered_map<std::string_view, 四聲> 四聲_by_ipa{
    {"˥˩", 四聲::平}, {"˩", 四聲::平},
    {"˥", 四聲::上},
    {"˩˥", 四聲::去},
    {"", 四聲::入}};
struct 字母呼轉等攝四聲 {
    字母 字母;
    呼 呼;
    轉等 轉等;
    攝 攝;
    四聲 四聲; };
字母呼轉等攝四聲 to_字母呼轉等攝四聲(std::string_view ipa, std::string_view 小韻) {
    std::vector<字母呼轉等攝四聲> 字母呼轉等攝四聲s;
    for (uint32_t i = 0; i <= ipa.size(); i++) {
        for (uint32_t j = i; j <= ipa.size(); j++) {
            std::array<std::string_view, 3> ipa_parts = {ipa.substr(0, i), ipa.substr(i, -i + j), ipa.substr(j, -j + ipa.size())};
            if (字母_by_ipa.count(ipa_parts[0]) && 呼轉等攝入_by_ipa.count(ipa_parts[1]) && 四聲_by_ipa.count(ipa_parts[2])) {
                字母呼轉等攝四聲s.push_back({
                    字母_by_ipa.at(ipa_parts[0]),
                    呼轉等攝入_by_ipa.at(ipa_parts[1]).呼,
                    呼轉等攝入_by_ipa.at(ipa_parts[1]).轉等(ipa_parts[0], 小韻),
                    呼轉等攝入_by_ipa.at(ipa_parts[1]).攝,
                    四聲_by_ipa.at(ipa_parts[2])}); } } }
    if (1 == 字母呼轉等攝四聲s.size()) {
        return 字母呼轉等攝四聲s[0]; }
    else { 
        R"js(
            console.log($0 + " matches!"); )js"_js_asm(字母呼轉等攝四聲s.size());
        return {}; } }
struct 小韻 {
    std::string ipa;
    std::string character;
    std::string 反切; };
int main() {
    //std::unordered_map<字母呼轉等攝四聲, 小韻> rt;
    R"js(
        originalTextContent = function(element) {
            let string = "";
            element.childNodes.forEach(function(text) {
                if (text instanceof Text) {
                    string += text.data; }
                else if (text instanceof Element) {
                    if ("original_text" == text.tagName) {
                        string += text.childNodes[0].data; }
                    else {
                        string += originalTextContent(text); } } });
            return string; }; )js"_js_asm();
    emscripten::val receiver = js::bind([/*&rt*/](emscripten::val voice_part) {
        小韻 小韻;
        小韻.ipa = emscripten::val::take_ownership(reinterpret_cast<emscripten::internal::EM_VAL>(R"js( return __emval_register(requireHandle($0).attributes.getNamedItem("ipa").value); )js"_js_asm_int(reinterpret_cast<uint32_t&>(voice_part)))).as<std::string>();
        小韻.character = emscripten::val::take_ownership(reinterpret_cast<emscripten::internal::EM_VAL>(R"js(
            const word_head = requireHandle($0).getElementsByTagName("word_head")[0];
            return __emval_register(/\s+/.test(word_head.childNode[0].data) ? word_head.childNode[1].childNode[0].data : word_head.childNode[0].data); )js"_js_asm_int(reinterpret_cast<uint32_t&>(voice_part)))).as<std::string>();
        小韻.反切 = emscripten::val::take_ownership(reinterpret_cast<emscripten::internal::EM_VAL>(R"js( return __emval_register(originalTextContent(requireHandle($0).querySelector("fanqie")).replace(/\s/g, "")); )js"_js_asm_int(reinterpret_cast<uint32_t&>(voice_part)))).as<std::string>();
        字母呼轉等攝四聲 gg = to_字母呼轉等攝四聲(小韻.ipa, 小韻.character);
        std::string output = 小韻.character + " " + 小韻.反切 + " " + 小韻.ipa + " " + std::string(magic_enum::enum_name(gg.字母)) + std::string(magic_enum::enum_name(gg.呼)) + std::string(magic_enum::enum_name(gg.轉等)) + std::string(magic_enum::enum_name(gg.攝)) + std::string(magic_enum::enum_name(gg.四聲));
        R"js( console.log(UTF8ToString($0)); )js"_js_asm(reinterpret_cast<int>(output.c_str()));
        /*rt.push_back(std::make_tuple(gg, 小韻));*/ }, std::placeholders::_1);
    R"js(
        let receiver = requireHandle($0);
        fetch("https://raw.githubusercontent.com/cjkvi/cjkvi-dict/master/sbgy.xml").then(function(response) {
            return response.text(); }).then(function(sbgy_xml) {
            let sbgy = (new DOMParser()).parseFromString(sbgy_xml, "application/xml");
            sbgy.querySelectorAll("book > volume > rhyme > voice_part").forEach(function(voice_part) {
                receiver(voice_part); }); }); )js"_js_asm(reinterpret_cast<uint32_t&>(receiver)); }