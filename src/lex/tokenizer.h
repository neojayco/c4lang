#pragma once

#include "token.h"

class tokenizer {
public:

    inline tokenizer(const source_content& src_text) noexcept : source(src_text), i()
    {}

    inline bool operator()(std::vector<token_t>& tokens) noexcept {
        return tokenize_main(tokens);
    }

private:
    bool tokenize_main(std::vector<token_t>& tokens) noexcept;

    bool _process_text(std::vector<token_t>& tokens) noexcept;

    inline auto current() const noexcept {
        return current_line().at(i);
    }

    inline auto advance() noexcept {
        return current_line()[i++];
    }

    inline auto peek(size_t offset) const noexcept {
        if (offset + i >= current_line().size()) {
            return std::optional<int>();
        }
        return std::optional<int>(current_line().at(i + offset));
    }

    inline bool is_buffer_empty() const noexcept {
        return i >= current_line().size();
    }
    bool is_valid_name_start() const noexcept;

    friend bool __issafe(const tokenizer* p);

    inline string32& current_line() noexcept {
        return source.lines[line_num];
    }

    inline const string32& current_line() const noexcept {
        return source.lines[line_num];
    }

    inline void advance_line() noexcept {
        line_num++;
        i = 0;
    }

    inline bool is_safe_line() const noexcept {
        return source.lines.size() > line_num;
    }

    source_content source = {};
    size_t line_num = {};
    size_t i = {};
};
