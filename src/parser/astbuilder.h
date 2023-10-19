#pragma once

#include "../common.h"
#include "../ast/statement.h"
#include "../ast/expression.h"
#include "../lex/token.h"

namespace parser {

    class astbuilder {
    public:

        inline astbuilder(const lex::token_stream_t& tstream) noexcept : stream(tstream), idx()
        {}

        inline ast::ptr_statement operator()() noexcept {
            return parse_primary();
        }

    private:
        ast::ptr_statement parse_primary() noexcept;

        ast::ptr_expression parse_expression() noexcept;
        ast::ptr_expression parse_primary_expression() noexcept;
        ast::ptr_expression parse_binary_expression(unsigned prec = 0) noexcept;

        inline auto current() const noexcept {
            return stream[idx];
        }

        inline bool issafe() const noexcept {
            return idx < stream.size();
        }

        inline auto peek(size_t i) const noexcept {
            if (issafe() && (idx + i < stream.size())) {
                return std::optional<lex::token_t>(stream[idx + i]);
            }
            return std::optional<lex::token_t>();
        }

        inline auto isMatch(std::initializer_list<lex::token_e> kinds, size_t off = 0) const noexcept {
            const auto p = peek(off);
            if (p.has_value()) {
                for (auto& k : kinds) {
                    if (k == p->kind) {
                        return p;
                    }
                }
            }
            return std::optional<lex::token_t>();
        }

        inline auto advance() noexcept {
            const auto p = peek(1);
            ++idx;
            return p;
        }

        const lex::token_stream_t& stream;
        size_t idx = {};
    };

}
