#include "token.h"

#include <algorithm>

namespace lex {

    namespace {
        std::vector<string32> _lex_text_table = {};
        constexpr auto MAX_TYPE_STR_LEN = 30ll;
    }
    
    string32& token_t::getText() noexcept {
        return _lex_text_table[text_idx];
    }
    const string32& token_t::getText() const noexcept {
        return _lex_text_table[text_idx];
    }

    std::wostream &operator<<(std::wostream &os, const token_stream_t &stream) {
        for (const auto token : stream) {
            const auto& type_cstr = token_to_string_table[(int)token.kind];
            const auto remaining_space = std::max(0ll, MAX_TYPE_STR_LEN - (int64_t)type_cstr.size());
            os << type_cstr;
            if (token.hasText()) {
                const string32 spaces(remaining_space, L' ');
                os << spaces << token.getText();
            }
            os << L'\n';
        }
        return os;
    }

    token_t create_token(const token_e kind, const string32 &text, symbol_location location) noexcept
    {
        const auto i = _lex_text_table.size();
        _lex_text_table.emplace_back(text);
        return { kind, i, location };
    }
}
