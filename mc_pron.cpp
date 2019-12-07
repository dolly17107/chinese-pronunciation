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
#include <cereal/types/vector.hpp>
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
void select_phoneme(std::unordered_multimap<std::string, baxter_sagart_oc_entry> const& bsoc_dictionary_by_字, emscripten::val li) {
    emscripten::val text = create_text_node(li["firstChild"]["data"].as<std::string>());
    emscripten::val list = emscripten::val::global("document").call<emscripten::val>("createRange");
    list.call<void>("selectNodeContents", li["parentNode"]);
    list.call<void>("deleteContents");
    list.call<void>("insertNode", text); }
void list_phonemes(std::unordered_multimap<std::string, baxter_sagart_oc_entry> const& bsoc_dictionary_by_字, emscripten::val ruby) {
    std::string character = ruby["firstChild"]["data"].as<std::string>();
    auto er = bsoc_dictionary_by_字.equal_range(character);
    emscripten::val list = emscripten::val::global("document").call<emscripten::val>("createDocumentFragment");
    std::for_each(er.first, er.second, [&bsoc_dictionary_by_字, list](std::pair<std::string, baxter_sagart_oc_entry> const& entry_pair) {
        baxter_sagart_oc_entry const& entry = std::get<1>(entry_pair);
        emscripten::val span = create_element("span");
        span.call<emscripten::val>("appendChild", create_text_node(predict_鄴(entry.mc_initial, entry.mc_final, entry.mc_四聲)));
        span.call<void>("addEventListener", std::string("click"), js::bind([&bsoc_dictionary_by_字](emscripten::val event) {
            select_phoneme(bsoc_dictionary_by_字, event["target"]); },
            std::placeholders::_1));
        span.set("tabIndex", 0);
        list.call<emscripten::val>("appendChild", span); });
    ruby["childNodes"][1]["firstChild"].call<void>("replaceWith", list); }
emscripten::val character_to_ruby(std::unordered_multimap<std::string, baxter_sagart_oc_entry> const& bsoc_dictionary_by_字, std::string character) {
    emscripten::val rb = create_element("grapheme-");
    rb.call<emscripten::val>("appendChild", create_text_node(character));
    baxter_sagart_oc_entry const& entry = std::get<1>(*std::get<0>(bsoc_dictionary_by_字.equal_range(character)));
    emscripten::val rt = create_element("phoneme-");
    rt.call<emscripten::val>("appendChild", create_text_node(predict_鄴(entry.mc_initial, entry.mc_final, entry.mc_四聲)));
    rt.call<void>("addEventListener", std::string("focus"), js::bind([&bsoc_dictionary_by_字](emscripten::val event) {
        list_phonemes(bsoc_dictionary_by_字, event["target"]["parentNode"]); },
        std::placeholders::_1));
    rt.call<void>("addEventListener", std::string("blur"), js::bind([&bsoc_dictionary_by_字](emscripten::val event) {
        select_phoneme(bsoc_dictionary_by_字, event["target"]["firstChild"]); },
        std::placeholders::_1));
    rt.set("tabIndex", 0);
    emscripten::val ruby = create_element("morpheme-");
    ruby.set("contentEditable", std::string("false"));
    ruby.call<emscripten::val>("appendChild", rb);
    ruby.call<emscripten::val>("appendChild", rt);
    return ruby; }
emscripten::val text_to_rubys(std::unordered_multimap<std::string, baxter_sagart_oc_entry> const& bsoc_dictionary_by_字, std::string text) {
    emscripten::val fragment = emscripten::val::global("document").call<emscripten::val>("createDocumentFragment");
    for (utf8_iterator iterator(text); iterator.valid(); ) {
        if (0 == bsoc_dictionary_by_字.count(std::string(*iterator))) {
            utf8_iterator begin = iterator;
            while (iterator.valid() && 0 == bsoc_dictionary_by_字.count(std::string(*iterator))) {
                ++iterator; }
            fragment.call<emscripten::val>("appendChild", create_text_node(std::string(substr(begin, iterator)))); }
        else {
            fragment.call<emscripten::val>("appendChild", character_to_ruby(bsoc_dictionary_by_字, std::string(*iterator)));
            ++iterator; } }
    return fragment; }
void rubyize(std::unordered_multimap<std::string, baxter_sagart_oc_entry> const& bsoc_dictionary_by_字, emscripten::val text) {
    std::string str = text["data"].as<std::string>();
    utf8_iterator alphanumeric_start(str);
    while (alphanumeric_start.valid() && 0 == bsoc_dictionary_by_字.count(std::string(*alphanumeric_start))) {
        ++alphanumeric_start; }
    if (alphanumeric_start.valid()) {
        text.call<void>("replaceWith", text_to_rubys(bsoc_dictionary_by_字, str)); } }
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
void onbeforeinput(std::unordered_multimap<std::string, baxter_sagart_oc_entry> const& bsoc_dictionary_by_字, emscripten::val event) {
    std::string input_type = event["inputType"].as<std::string>();
    console_log(input_type);
    if (std::string("insertText") == input_type || std::string("insertFromComposition") == input_type) {
        std::string text = event["data"].as<std::string>();
        emscripten::val ruby = text_to_rubys(bsoc_dictionary_by_字, text);
        replace_ranges_with_fragment(ruby, event.call<emscripten::val>("getTargetRanges"));
        event.call<void>("preventDefault"); } }
void oninput(std::unordered_multimap<std::string, baxter_sagart_oc_entry> const& bsoc_dictionary_by_字, emscripten::val event) {
    if (!event["isComposing"]) {
        console_log("updating...");
        emscripten::val target = event["target"];
        emscripten::val::global("Array").call<emscripten::val>("from", target["childNodes"]).call<void>("forEach", js::bind([&bsoc_dictionary_by_字](emscripten::val node, emscripten::val index, emscripten::val list) {
            if (node.instanceof(emscripten::val::global("Text"))) {
                rubyize(bsoc_dictionary_by_字, node); } },
            std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)); } }
int main() {
    std::vector<baxter_sagart_oc_entry> bsoc_dictionary = deserialize<std::vector<baxter_sagart_oc_entry>>(file_to_string("BaxterSagartOC2015-10-13"));
    std::unordered_multimap<std::string, baxter_sagart_oc_entry> bsoc_dictionary_by_字;
    for (baxter_sagart_oc_entry const& entry : bsoc_dictionary) {
        bsoc_dictionary_by_字.insert(make_pair(entry.字, entry)); }
    emscripten::val style = create_element("style");
    style.set("innerHTML", file_to_string("main.css"));
    emscripten::val::global("document")["head"].call<emscripten::val>("appendChild", style);
    emscripten::val::global("document")["body"].set("innerHTML", file_to_string("main.html"));
    get_element_by_id("pronunciation").call<void>("addEventListener", std::string("input"), js::bind(oninput, bsoc_dictionary_by_字, std::placeholders::_1));
    get_element_by_id("pronunciation").call<void>("addEventListener", std::string("compositionend"), js::bind(oninput, bsoc_dictionary_by_字, std::placeholders::_1));
    R"js(
        let target = document.getElementById("pronunciation");
        target.addEventListener("pointerdown", function(event) {
            let start = target.ownerDocument.caretRangeFromPoint(event.clientX, event.clientY);
            let atom = null;
            let node = start.endContainer;
            for (; node && target != node; node = node.parentNode) {
                if (node instanceof HTMLElement && !node.isContentEditable) {
                    atom = node; } }
            if (target == node) {
                console.log("positioning...");
                if (atom) {
                    start.setStartBefore(atom);
                    start.setEndBefore(atom); }
                target.onpointermove = function(event) {
                    let end = target.ownerDocument.caretRangeFromPoint(event.clientX, event.clientY);
                    let atom = null;
                    let node = end.endContainer;
                    for (; node && target != node; node = node.parentNode) {
                        if (node instanceof HTMLElement && !node.isContentEditable) {
                            atom = node; } }
                    if (target == node) {
                        console.log("selecting...");
                        if (atom) {
                            end.setStartBefore(atom);
                            end.setEndBefore(atom); }
                        target.ownerDocument.getSelection().setBaseAndExtent(start.endContainer, start.endOffset, end.endContainer, end.endOffset); } };
                event.preventDefault();
                event.stopPropagation(); } });
        target.addEventListener("pointerup", function(event) {
            target.onpointermove = null; }); )js"_js_asm();
    R"js(
        document.addEventListener("selectionchange", function(event) {
            Array.from(event.currentTarget.getElementsByClassName("selection")).forEach(function(element) {
                element.classList.remove("selection"); });
            let selection = event.currentTarget.getSelection();
            if (0 != selection.rangeCount) {
                Array.from(event.currentTarget.getElementsByTagName("*")).forEach(function(element) {
                    if (selection.containsNode(element)) {
                        element.classList.add("selection"); } }); } }); )js"_js_asm(); }