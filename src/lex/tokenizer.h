#pragma once

#include "token.h"

namespace lex {

    class tokenizer {
    public:

        inline tokenizer(const source_content& src_text) noexcept : source(src_text), i(0), line_idx(1)
        {}

        inline bool operator()(std::vector<token_t>& tokens) noexcept {
            return tokenize_main(tokens);
        }

    private:
        bool tokenize_main(std::vector<token_t>& tokens) noexcept;

        bool _process_text(std::vector<token_t>& tokens) noexcept;
        bool _process_singlinecomment(std::vector<token_t>& tokens) noexcept;

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
            return source.lines[line_idx];
        }

        inline const string32& current_line() const noexcept {
            return source.lines[line_idx];
        }

        inline void advance_line() noexcept {
            line_idx++;
            i = 0;
        }

        inline bool is_safe_line() const noexcept {
            return source.lines.size() > line_idx;
        }

        inline bool is(const string_view32& sv) const noexcept {
            for (auto i = 0ull; (!is_buffer_empty()) && i < sv.size(); ++i) {
                if (peek(i) != sv[i]) {
                    return false;
                }
            }
            return true;
        }

        symbol_location getLocation(const size_t start) const noexcept;

        source_content source = {};
        size_t line_idx = {};
        size_t i = {};
    };

}
