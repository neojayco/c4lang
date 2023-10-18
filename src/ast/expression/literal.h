#pragma once

#include "../expression.h"
#include "../../literal_value.h"

namespace ast {

    class literal_expression : public expression {
    public:

        template<class T>
        inline literal_expression(const symbol_location& symloc, T v) noexcept : expression({symloc}, k_literal_expr), value(v)
        {}

        inline auto& getValue() const noexcept {
            return value;
        }

    private:
        literal_value value = {};
    };

}
