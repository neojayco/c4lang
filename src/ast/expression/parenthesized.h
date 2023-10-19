#pragma once

#include "../expression.h"

namespace ast {

    // (expr)
    class parenthesized_expression : public expression {
    public:

        inline parenthesized_expression(semantic_location loc, const ptr<expression>& expr) noexcept
            : expression(loc, k_expr), inner(expr)
        {}

        inline auto getExpr() const noexcept {
            return inner;
        }

    private:
        ptr<expression> inner = {};
    };

    AST_DEFINITION(parenthesized_expression)

}
