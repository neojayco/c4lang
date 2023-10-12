#include "token.h"

std::vector<std::string> _lex_text_table = {};

std::string& token_t::getText() noexcept {
    return _lex_text_table[text_idx];
}
const std::string& token_t::getText() const noexcept {
    return _lex_text_table[text_idx];
}

token_t create_token(const token_e kind, const std::string& text) noexcept {
    const auto i = _lex_text_table.size();
    _lex_text_table.emplace_back(text);
    return { kind, i };
}
