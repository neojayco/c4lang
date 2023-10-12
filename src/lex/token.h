#pragma once

#include <string>
#include <string_view>
#include <optional>
#include <vector>

enum token_e {
    T_IDENTIFIER,
};

struct token_t {
    token_e kind = T_IDENTIFIER;
    size_t text_idx = std::string::npos;

    std::string& getText() noexcept;
    const std::string& getText() const noexcept;
    
    inline bool hasText() const noexcept {
        return text_idx != std::string::npos;
    }
};

inline token_t create_token(const token_e kind) noexcept {
    return { kind };
}

token_t create_token(const token_e kind, const std::string& text) noexcept;