#pragma once

#include "value_statement.h"

namespace ast {

    class expression : public value_statement {
    public:
        inline expression(semantic_location loc, kind_e k = k_expr) noexcept : value_statement(loc, k)
        {}

        virtual ~expression() = default;
    };

    AST_DEFINITION(expression)

}
