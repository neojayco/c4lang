#pragma once

#include "token.h"

namespace lex {

    class tokenizer {
    public:

        inline tokenizer(const source_content& src_text) noexcept : source(src_text), i(0), line_idx(0)
        {}

        inline bool operator()(token_stream_t& tokens) noexcept {
            return tokenize_main(tokens);
        }

    private:
        bool tokenize_main(token_stream_t& tokens) noexcept;

        bool _process_text(token_stream_t& tokens) noexcept;
        bool _process_singlinecomment(token_stream_t& tokens) noexcept;
        bool _process_multilinecommentbegin(token_stream_t& tokens) noexcept;
        bool _process_multilinecommentend(token_stream_t& tokens) noexcept;
        bool _process_assign(token_stream_t& tokens) noexcept;
        bool _process_curly_begin(token_stream_t& tokens) noexcept;
        bool _process_curly_end(token_stream_t& tokens) noexcept;
        bool _process_less(token_stream_t& tokens) noexcept;
        bool _process_greater(token_stream_t& tokens) noexcept;
        bool _process_comma(token_stream_t& tokens) noexcept;
        bool _process_number_literal(token_stream_t& tokens) noexcept;
        bool _process_paren_open(token_stream_t& tokens) noexcept;
        bool _process_paren_close(token_stream_t& tokens) noexcept;
        bool _process_colon(token_stream_t& tokens) noexcept;
        bool _process_minus(token_stream_t& tokens) noexcept;
        bool _process_question(token_stream_t& tokens) noexcept;
        bool _process_dot(token_stream_t& tokens) noexcept;
        bool _process_plus(token_stream_t& tokens) noexcept;
        bool _process_percent(token_stream_t& tokens) noexcept;
        bool _process_star(token_stream_t& tokens) noexcept;
        bool _process_bang(token_stream_t& tokens) noexcept;

        inline auto current() const noexcept {
            return current_line().at(i);
        }

        inline bool is_spaced_line() const noexcept {
            const auto& line = current_line();
            constexpr string_view32 space_letters(L" \n\r\t");
            for (auto& c : line) {
                if (space_letters.find_first_of(c) != space_letters.npos) {
                    return false;
                }
            }
            return true;
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

        inline bool is_number_literal_start() const noexcept {
            return 
            (current() == L'-' || current() == L'+' || is_number_modifier() || iswdigit(current())) &&
                is_valid_number_literal_character();
        }

        inline bool is_number_modifier() const noexcept {
            return current() == L'x' ||
                current() == L'X' || current() == L'b' ||
                current() == L'B';
        }

        inline bool is_valid_number_literal_character() const noexcept {
            return is_number_modifier()
                ||
                iswdigit(current())
                ||
            (!is_buffer_empty() && (peek(1).has_value() && iswdigit(*peek(1))));
        }

        symbol_location getLocation(const size_t start) const noexcept;

        source_content source = {};
        size_t line_idx = {};
        size_t i = {};
    };

}
