#include "token.h"

std::vector<string32> _lex_text_table = {};

string32& token_t::getText() noexcept {
    return _lex_text_table[text_idx];
}
const string32& token_t::getText() const noexcept {
    return _lex_text_table[text_idx];
}

token_t create_token(const token_e kind, const string32& text) noexcept {
    const auto i = _lex_text_table.size();
    _lex_text_table.emplace_back(text);
    return { kind, i };
}
