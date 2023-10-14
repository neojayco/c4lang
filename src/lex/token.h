#pragma once

#include "common.h"

namespace lex {

    enum token_e {
        T_IDENTIFIER,
        T_SLASH,
        T_SINGLECOMMENT,
        T_MULTICOMMENT_BEGIN,
        T_MULTICOMMENT_END,
        T_ASSIGN,
        T_CURLY_BEGIN,
        T_CURLY_END,
        T_LESS,
        T_GREATER,
        T_COMMA,
        T_NUMBER_LITERAL,
        T_PAREN_OPEN,
        T_PAREN_CLOSE,
        T_COLON,
        T_MINUS,
        T_QUESTION,
        T_DOT,
    };

    const string_view32 token_to_string_table[] = {
        L"(IDENTIFIER)",
        L"(SLASH)",
        L"(SINGLELINECOMMENT)",
        L"(MULTILINECOMMENTBEGIN)",
        L"(MULTILINECOMMENTEND)",
        L"(ASSIGN)",
        L"(CURLY_BEGIN)",
        L"(CURLY_END)",
        L"(LESS)",
        L"(GREATER)",
        L"(COMMA)",
        L"(NUMBER_LITERAL)",
        L"(PAREN_OPEN)",
        L"(PAREN_CLOSE)",
        L"(COLON)",
        L"(MINUS)",
        L"(QUESTION)",
        L"(DOT)",
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

    using token_stream_t = std::vector<token_t>;

    std::wostream& operator<<(std::wostream& os, const token_stream_t& stream);

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

    inline token_t create_single_comment(const string32& text, const symbol_location& location) noexcept {
        return create_token(T_SINGLECOMMENT, text, location);
    }

    inline token_t create_multi_comment_begin(const symbol_location& location) noexcept {
        return create_token(T_MULTICOMMENT_BEGIN, location);
    }

    inline token_t create_multi_comment_end(const symbol_location& location) noexcept {
        return create_token(T_MULTICOMMENT_END, location);
    }

    inline token_t create_assign(const symbol_location& location) noexcept {
        return create_token(T_ASSIGN, location);
    }

    inline token_t create_curly_begin(const symbol_location& location) noexcept {
        return create_token(T_CURLY_BEGIN, location);
    }

    inline token_t create_curly_end(const symbol_location& location) noexcept {
        return create_token(T_CURLY_END, location);
    }

    inline token_t create_less(const symbol_location& location) noexcept {
        return create_token(T_LESS, location);
    }

    inline token_t create_greater(const symbol_location& location) noexcept {
        return create_token(T_GREATER, location);
    }

    inline token_t create_comma(const symbol_location& location) noexcept {
        return create_token(T_COMMA, location);
    }

    inline token_t create_number_literal(const string32& text, const symbol_location& location) noexcept {
        return create_token(T_NUMBER_LITERAL, text, location);
    }

    inline token_t create_paren_open(const symbol_location& location) noexcept {
        return create_token(T_PAREN_OPEN, location);
    }

    inline token_t create_paren_close(const symbol_location& location) noexcept {
        return create_token(T_PAREN_CLOSE, location);
    }

    inline token_t create_colon(const symbol_location& location) noexcept {
        return create_token(T_COLON, location);
    }

    inline token_t create_minus(const symbol_location& location) noexcept {
        return create_token(T_MINUS, location);
    }

    inline token_t create_question(const symbol_location& location) noexcept {
        return create_token(T_QUESTION, location);
    }

    inline token_t create_dot(const symbol_location& location) noexcept {
        return create_token(T_DOT, location);
    }

}
