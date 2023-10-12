#pragma once

#include "token.h"

class tokenizer {
public:

    constexpr tokenizer(const std::string_view& src_text) noexcept : text(src_text), i()
    {}

    inline bool operator()(std::vector<token_t>& tokens) noexcept {
        return tokenize_main(tokens);
    }

private:
    bool tokenize_main(std::vector<token_t>& tokens) noexcept;

    bool _process_text(std::vector<token_t>& tokens) noexcept;

    inline auto current() const noexcept {
        return text.at(i);
    }

    inline auto advance() const noexcept {
        return text.at(i++);
    }

    inline auto peek(size_t offset) const noexcept {
        if (offset + i >= text.size()) {
            return std::optional<char>();
        }
        return std::optional<char>(text.at(i + offset));
    }

    inline auto is_buffer_empty() const noexcept {
        return i >= text.size();
    }

    std::string_view text = {};
    size_t i = {};
};
