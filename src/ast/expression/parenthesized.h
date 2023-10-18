#pragma once

#include "../expression.h"

namespace ast {

    // (expr)
    class parenthesized_expression : public expression {
    public:

        inline parenthesized_expression(std::initializer_list<symbol_location> symloc, const ptr<expression>& expr) noexcept
            : expression(symloc, k_expr), inner(expr)
        {}

    private:
        ptr<expression> inner = {};
    };

}
