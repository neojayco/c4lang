#pragma once

#include "statement.h"

namespace ast {

    class expression : public statement {
    public:
        inline expression(std::initializer_list<symbol_location> symloc, kind_e k = k_expr) noexcept : statement(symloc, k)
        {}

        virtual ~expression() = default;
    };

}
