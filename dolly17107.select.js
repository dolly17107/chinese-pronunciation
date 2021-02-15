export class Dolly17107Select extends HTMLElement {
    select(node) {
        this.querySelectorAll(":scope > [data-selected]").forEach(node => { node.removeAttribute("data-selected"); });
        node.dataset.selected = "";
        this.dispatchEvent(new CustomEvent("change")); }
    constructor() {
        super();
        this.tabIndex = 0;
        this.addEventListener("click", function(e) { if (e.target == this) { this.focus(); this.dataset.expanded = ""; } }); } }
export class Dolly17107Option extends HTMLElement {
    constructor() {
        super();
        this.addEventListener("click", function(e) { this.parentNode.select(this); this.parentNode.removeAttribute("data-expanded"); }); } }
customElements.define("dolly17107-select", Dolly17107Select);
customElements.define("dolly17107-option", Dolly17107Option);