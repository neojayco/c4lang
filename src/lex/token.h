#pragma once

#include "common.h"

namespace lex {

    enum token_e {
        T_IDENTIFIER,
        T_SLASH,
        T_SINGLECOMMENT,
    };

    struct token_t {
        token_e kind = T_IDENTIFIER;
        size_t text_idx = string32::npos;
        symbol_location location;

        string32& getText() noexcept;
        const string32& getText() const noexcept;
        
        inline bool hasText() const noexcept {
            return text_idx != string32::npos;
        }
    };

    inline token_t create_token(const token_e kind, symbol_location location) noexcept {
        return { kind, string32::npos, location };
    }

    token_t create_token(const token_e kind, const string32& text, symbol_location location) noexcept;

    inline token_t create_identifier(const string32& text, const symbol_location& location) noexcept {
        return create_token(T_IDENTIFIER, text, location);
    }

    inline token_t create_slash(const symbol_location& location) noexcept {
        return create_token(T_SLASH, location);
    }

    inline token_t create_single_comment(const symbol_location& location) noexcept {
        return create_token(T_SLASH, location);
    }

}
