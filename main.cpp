#include <cinttypes>
#include <tuple>
#include <optional>
#include <array>
#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/optional.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/vector.hpp>
#include <magic_enum.hpp>
#include <buffer.h>
#include <filesystem.h>
#include <console_log.h>
#include <emscripten.h>
#include <emscripten/val.h>
#include <emscripten/bind.h>
#include <js.h>
#include <js/bind.hpp>
#include "mc_pron.h"
class utf8_iterator {
    std::string_view str;
    std::size_t index;
public:
    explicit utf8_iterator(std::string_view str) : str(str), index(0) { }
    std::string_view operator*() {
        if ((0b10000000 & str[index]) == 0b00000000) {
            return str.substr(index, 1); }
        else if ((0b11100000 & str[index]) == 0b11000000) {
            return str.substr(index, 2); }
        else if ((0b11110000 & str[index]) == 0b11100000) {
            return str.substr(index, 3); }
        else if ((0b11111000 & str[index]) == 0b11110000) {
            return str.substr(index, 4); }
        throw; }
    utf8_iterator& operator++() {
        if ((0b10000000 & str[index]) == 0b00000000) {
            index += 1; }
        else if ((0b11100000 & str[index]) == 0b11000000) {
            index += 2; }
        else if ((0b11110000 & str[index]) == 0b11100000) {
            index += 3; }
        else if ((0b11111000 & str[index]) == 0b11110000) {
            index += 4; }
        return *this; }
    bool valid() {
        return str.size() > index; }
    friend bool operator==(utf8_iterator a, utf8_iterator b) {
        return a.index == b.index; }
    friend bool operator!=(utf8_iterator a, utf8_iterator b) {
        return a.index != b.index; }
    friend std::string_view substr(utf8_iterator begin, utf8_iterator end) {
        return begin.str.substr(begin.index, -begin.index + end.index); } };
char32_t utf8_to_codepoint(std::string_view utf8) {
    char32_t codepoint = 0;
    if ((0b10000000 & utf8[0]) == 0b00000000) {
        codepoint |= static_cast<char32_t>(0b01111111 & utf8[0]) << 0; }
    else if ((0b11100000 & utf8[0]) == 0b11000000) {
        codepoint |= static_cast<char32_t>(0b00011111 & utf8[0]) << 6;
        codepoint |= static_cast<char32_t>(0b00111111 & utf8[1]) << 0; }
    else if ((0b11110000 & utf8[0]) == 0b11100000) {
        codepoint |= static_cast<char32_t>(0b00001111 & utf8[0]) << 12;
        codepoint |= static_cast<char32_t>(0b00111111 & utf8[1]) << 6;
        codepoint |= static_cast<char32_t>(0b00111111 & utf8[2]) << 0; }
    else if ((0b11111000 & utf8[0]) == 0b11110000) {
        codepoint |= static_cast<char32_t>(0b00000111 & utf8[0]) << 18;
        codepoint |= static_cast<char32_t>(0b00111111 & utf8[1]) << 12;
        codepoint |= static_cast<char32_t>(0b00111111 & utf8[2]) << 6;
        codepoint |= static_cast<char32_t>(0b00111111 & utf8[3]) << 0; }
    return codepoint; }
enum class dialect {周, 南朝金陵, 北朝鄴, 中唐長安};
dialect selected_dialect;
void get_selected_dialect() {
    std::string dialect_name = emscripten::val::global("document").call<emscripten::val>("querySelector", std::string("#dialect > [data-selected]"))["firstChild"]["data"].as<std::string>();
    auto dialect_names = magic_enum::enum_entries<dialect>();
    selected_dialect = std::get<0>(*std::find_if(dialect_names.begin(), dialect_names.end(), [dialect_name](auto entry) { return dialect_name == std::get<1>(entry); })); }
std::optional<chinese_dictionary> dict;
std::optional<std::unordered_multimap<std::string, morpheme_data>> oc_by_字;
std::optional<std::unordered_multimap<std::string, morpheme_data>> mc_by_字;
std::size_t predict_count(std::string character) {
    if (selected_dialect == dialect::周) {
        return oc_by_字->count(character); }
    if (selected_dialect == dialect::南朝金陵) {
        return mc_by_字->count(character); }
    if (selected_dialect == dialect::北朝鄴) {
        return mc_by_字->count(character); }
    if (selected_dialect == dialect::中唐長安) {
        return mc_by_字->count(character); }
    throw; }
std::vector<std::tuple<std::string, std::string>> predict(std::string character) {
    if (selected_dialect == dialect::周) {
        std::vector<std::tuple<std::string, std::string>> pron_list;
        {
            auto er = oc_by_字->equal_range(character);
            std::transform(std::get<0>(er), std::get<1>(er), std::back_inserter(pron_list), [](auto entry_pair) {
                morpheme_data entry = std::get<1>(entry_pair);
                return std::make_tuple(std::get<std::string>(entry.form.phoneme), entry.meaning); }); }
        return pron_list; }
    if (selected_dialect == dialect::南朝金陵) {
        std::vector<std::tuple<std::string, std::string>> pron_list;
        {
            auto er = mc_by_字->equal_range(character);
            std::transform(std::get<0>(er), std::get<1>(er), std::back_inserter(pron_list), [](auto entry_pair) {
                morpheme_data entry = std::get<1>(entry_pair);
                return std::make_tuple(predict_金陵(std::get<mc_syllable>(entry.form.phoneme).initial, std::get<mc_syllable>(entry.form.phoneme).final, std::get<mc_syllable>(entry.form.phoneme).四聲), entry.meaning); }); }
        return pron_list; }
    if (selected_dialect == dialect::北朝鄴) {
        std::vector<std::tuple<std::string, std::string>> pron_list;
        {
            auto er = mc_by_字->equal_range(character);
            std::transform(std::get<0>(er), std::get<1>(er), std::back_inserter(pron_list), [](auto entry_pair) {
                morpheme_data entry = std::get<1>(entry_pair);
                return std::make_tuple(predict_鄴(std::get<mc_syllable>(entry.form.phoneme).initial, std::get<mc_syllable>(entry.form.phoneme).final, std::get<mc_syllable>(entry.form.phoneme).四聲), entry.meaning); }); }
        return pron_list; }
    if (selected_dialect == dialect::中唐長安) {
        std::vector<std::tuple<std::string, std::string>> pron_list;
        {
            auto er = mc_by_字->equal_range(character);
            std::transform(std::get<0>(er), std::get<1>(er), std::back_inserter(pron_list), [](auto entry_pair) {
                morpheme_data entry = std::get<1>(entry_pair);
                return std::make_tuple(predict_prelmc(std::get<mc_syllable>(entry.form.phoneme).initial, std::get<mc_syllable>(entry.form.phoneme).final, std::get<mc_syllable>(entry.form.phoneme).四聲), entry.meaning); }); }
        return pron_list; }
    throw; }
void select_phoneme(emscripten::val li) {
    emscripten::val text = create_text_node(li["firstChild"]["data"].as<std::string>());
    emscripten::val list = emscripten::val::global("document").call<emscripten::val>("createRange");
    list.call<void>("selectNodeContents", li["parentNode"]);
    list.call<void>("deleteContents");
    list.call<void>("insertNode", text); }
void list_phonemes(emscripten::val ruby) {
    std::string character = ruby["childNodes"][1]["firstChild"]["data"].as<std::string>();
    auto er = mc_by_字->equal_range(character);
    emscripten::val list = emscripten::val::global("document").call<emscripten::val>("createDocumentFragment");
    std::for_each(er.first, er.second, [list](std::pair<std::string, morpheme_data> const& entry_pair) {
        morpheme_data const& entry = std::get<1>(entry_pair);
        emscripten::val span = create_element("span");
        span.call<emscripten::val>("appendChild", create_text_node(predict_鄴(std::get<mc_syllable>(entry.form.phoneme).initial, std::get<mc_syllable>(entry.form.phoneme).final, std::get<mc_syllable>(entry.form.phoneme).四聲)));
        span.call<void>("addEventListener", std::string("click"), js::bind([](emscripten::val event) {
            select_phoneme(event["target"]); },
            std::placeholders::_1));
        span.set("tabIndex", 0);
        list.call<emscripten::val>("appendChild", span); });
    ruby["childNodes"][1]["firstChild"].call<void>("replaceWith", list); }
emscripten::val character_to_ruby(std::string character) {
    emscripten::val rb = create_element("grapheme-");
    rb.call<emscripten::val>("appendChild", create_text_node(character));
    emscripten::val rt = create_element("phoneme-");
    rt.call<emscripten::val>("appendChild", create_text_node(std::get<0>(predict(character)[0])));
    rt.call<void>("addEventListener", std::string("focus"), js::bind([](emscripten::val event) {
        emscripten::val::global("console").call<void>("log", event);list_phonemes(event["target"]["parentNode"]);  },
        std::placeholders::_1));
    rt.call<void>("addEventListener", std::string("blur"), js::bind([](emscripten::val event) {
        select_phoneme(event["target"]["firstChild"]); },
        std::placeholders::_1));
    rt.set("tabIndex", 0);
    emscripten::val ruby = create_element("morpheme-");
    ruby.set("contentEditable", std::string("false"));
    ruby.call<emscripten::val>("appendChild", rb);
    ruby.call<emscripten::val>("appendChild", rt);
    return ruby; }
emscripten::val text_to_rubys(std::string text) {
    emscripten::val fragment = emscripten::val::global("document").call<emscripten::val>("createDocumentFragment");
    for (utf8_iterator iterator(text); iterator.valid(); ) {
        if (0 == predict_count(std::string(*iterator))) {
            utf8_iterator begin = iterator;
            while (iterator.valid() && 0 == predict_count(std::string(*iterator))) {
                ++iterator; }
            fragment.call<emscripten::val>("appendChild", create_text_node(std::string(substr(begin, iterator)))); }
        else {
            fragment.call<emscripten::val>("appendChild", character_to_ruby(std::string(*iterator)));
            ++iterator; } }
    return fragment; }
void rubyize_text(emscripten::val text) {
    std::string str = text["data"].as<std::string>();
    utf8_iterator alphanumeric_start(str);
    while (alphanumeric_start.valid() && 0 == predict_count(std::string(*alphanumeric_start))) {
        ++alphanumeric_start; }
    if (alphanumeric_start.valid()) {
        text.call<void>("replaceWith", text_to_rubys(str)); } }
void replace_ranges_with_fragment(emscripten::val fragment, emscripten::val ranges) {
        emscripten::val range = ranges[0];
        emscripten::val dynamic_range = emscripten::val::global("document").call<emscripten::val>("createRange");
        dynamic_range.call<void>("setStart", range["startContainer"], range["startOffset"]);
        dynamic_range.call<void>("setEnd", range["endContainer"], range["endOffset"]);
        emscripten::val selection_range = emscripten::val::global("document").call<emscripten::val>("getSelection").call<emscripten::val>("getRangeAt", 0);
        if (0 == dynamic_range.call<int16_t>("compareBoundaryPoints", emscripten::val::global("Range")["START_TO_START"], selection_range) &&
            0 == dynamic_range.call<int16_t>("compareBoundaryPoints", emscripten::val::global("Range")["END_TO_END"], selection_range)) {
                dynamic_range = selection_range; }
        dynamic_range.call<void>("deleteContents");
        dynamic_range.call<emscripten::val>("insertNode", fragment);
        dynamic_range.call<void>("collapse"); }
void onbeforeinput(emscripten::val event) {
    std::string input_type = event["inputType"].as<std::string>();
    console_log(input_type);
    if (std::string("insertText") == input_type || std::string("insertFromComposition") == input_type) {
        std::string text = event["data"].as<std::string>();
        emscripten::val ruby = text_to_rubys(text);
        replace_ranges_with_fragment(ruby, event.call<emscripten::val>("getTargetRanges"));
        event.call<void>("preventDefault"); } }
int main() {
    /*emscripten::val const string_allocator_val = js::bind([](emscripten::val length) {
        sbgy = std::string(length.as<uint32_t>(), 0);
        return emscripten::val(reinterpret_cast<uintptr_t>(sbgy->data())); },
        std::placeholders::_1);
    R"js(
        let string_allocator = requireHandle($0);
        fetch("https://raw.githubusercontent.com/cjkvi/cjkvi-dict/master/sbgy.xml").then(function(response) {
            return response.arrayBuffer(); }).then(function(arrayBuffer) {
            let charArray = new Uint8Array(arrayBuffer);
            let stringData = string_allocator(charArray.length);
            (new Uint8Array(buffer, stringData, charArray.length)).set(charArray); }); )js"_js_asm(
        reinterpret_cast<uint32_t const&>(string_allocator_val));*/
    dict = deserialize<chinese_dictionary>(file_to_string("dictionary"));
    oc_by_字 = std::make_optional<std::unordered_multimap<std::string, morpheme_data>>();
    for (morpheme_data const& entry : dict->old_chinese) {
        oc_by_字->insert(make_pair(entry.form.grapheme, entry)); }
    mc_by_字 = std::make_optional<std::unordered_multimap<std::string, morpheme_data>>();
    for (morpheme_data const& entry : dict->middle_chinese) {
        mc_by_字->insert(make_pair(entry.form.grapheme, entry)); }
    emscripten::val const rubyize_text_val = js::bind(rubyize_text, std::placeholders::_1);
    emscripten::val const get_selected_dialect_val = js::bind(get_selected_dialect);
    R"js(
        const get_selected_dialect = requireHandle($1);
        get_selected_dialect();
        const rubyize_text = requireHandle($0);
        const rubyize = function(rubyizer) {
            Array.from(rubyizer.childNodes).forEach(function(node) {
                if (node instanceof Text) {
                    rubyize_text(node); } }); };
        Array.from(document.getElementsByTagName("rubyizer-")).forEach(function(rubyizer) {
            rubyize(rubyizer);
            rubyizer.addEventListener("input", function(event) {
                if (!event.isComposing) {
                    rubyize(event.currentTarget); } });
            rubyizer.addEventListener("compositionend", function(event) {
                rubyize(event.currentTarget); }); });
        const clear_all_annotation = function() {
            Array.from(document.querySelectorAll("rubyizer- > morpheme-")).forEach(function(morpheme) {
                const grapheme = morpheme.querySelector("grapheme-").firstChild.data;
                morpheme.replaceWith(document.createTextNode(grapheme)); }); }
        const reset_all_rubyizer = function() {
            clear_all_annotation();
            Array.from(document.getElementsByTagName("rubyizer-")).forEach(function(rubyizer) {
                rubyize(rubyizer); }); }
        document.getElementById("dialect").addEventListener("change", function() {
            get_selected_dialect();
            reset_all_rubyizer(); }); )js"_js_asm(
        reinterpret_cast<uint32_t const&>(rubyize_text_val),
        reinterpret_cast<uint32_t const&>(get_selected_dialect_val));
    R"js(
        const select = function(node, selection) {
            if (node instanceof Element && selection.containsNode(node)) {
                if (!node.classList.contains("selection")) {
                    node.classList.add("selection"); } }
            node.childNodes.forEach(function(node) {
                if (selection.containsNode(node, true)) {
                    select(node, selection); } }); };
        document.addEventListener("selectionchange", function(event) {
            const selection = event.currentTarget.getSelection();
            Array.from(event.currentTarget.getElementsByClassName("selection")).forEach(function(element) {
                if (!selection.containsNode(element)) {
                    element.classList.remove("selection"); } });
            if (0 != selection.rangeCount) {
                select(selection.getRangeAt(0).commonAncestorContainer, selection); } });
        const caretPositionFromPoint = function(viewport, x, y) {
            let position = viewport.document.caretRangeFromPoint(x, y);
            let atom = null;
            let node = position.endContainer;
            for (; node; node = node.parentNode) {
                if (node instanceof Element && "morpheme-" == node.tagName.toLowerCase()) {
                    atom = node; } }
            if (atom) {
                const rect = atom.getBoundingClientRect();
                if (-rect.x + x <= 0.5 * rect.width) {
                    position.setStartBefore(atom);
                    position.setEndBefore(atom); }
                else {
                    position.setStartAfter(atom);
                    position.setEndAfter(atom); } }
            return position; };
        document.addEventListener("pointerdown", function(event) {
            const start = caretPositionFromPoint(event.view, event.clientX, event.clientY);
            const moveHandler = function(event) {
                let end = caretPositionFromPoint(event.view, event.clientX, event.clientY);
                event.currentTarget.getSelection().setBaseAndExtent(start.endContainer, start.endOffset, end.endContainer, end.endOffset); };
            moveHandler(event);
            event.currentTarget.addEventListener("pointermove", moveHandler);
            const upHandler = function(event) {
                event.currentTarget.removeEventListener("pointermove", moveHandler);
                event.currentTarget.removeEventListener("pointerup", upHandler);
                event.currentTarget.removeEventListener("pointerleave", upHandler); };
            event.currentTarget.addEventListener("pointerup", upHandler);
            event.currentTarget.addEventListener("pointerleave", upHandler);
            event.preventDefault();
            event.stopPropagation(); }); )js"_js_asm();
    R"js(
        document.getElementsByTagName("spinner-")[0].remove(); )js"_js_asm(); }