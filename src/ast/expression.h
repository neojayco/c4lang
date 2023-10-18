#pragma once

#include "value_statement.h"

namespace ast {

    class expression : public value_statement {
    public:
        inline expression(std::initializer_list<symbol_location> symloc, kind_e k = k_expr) noexcept : value_statement(symloc, k)
        {}

        virtual ~expression() = default;
    };

}
