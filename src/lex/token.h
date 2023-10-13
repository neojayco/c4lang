#pragma once

#include "common.h"

enum token_e {
    T_IDENTIFIER,
};

struct token_t {
    token_e kind = T_IDENTIFIER;
    size_t text_idx = string32::npos;

    string32& getText() noexcept;
    const string32& getText() const noexcept;
    
    inline bool hasText() const noexcept {
        return text_idx != string32::npos;
    }
};

inline token_t create_token(const token_e kind) noexcept {
    return { kind };
}

token_t create_token(const token_e kind, const string32& text) noexcept;