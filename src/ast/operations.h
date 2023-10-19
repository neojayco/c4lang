#pragma once

#include "../common.h"

namespace ast {

    enum binop_kind : unsigned {
        bk_none,
        bk_add_assign,  // +=
        bk_sub_assign,  // -=
        bk_mul_assign,  // *=
        bk_div_assign,  // /=
        bk_lor,         // logical OR (||)
        bk_land,        // logical AND (&&)
        bk_or,          // bitwise OR (|)
        bk_xor,         // bitwise XOR (^)
        bk_and,         // bitwise AND (&)
        bk_eq,          // equals (==)
        bk_neq,         // not equals (!=)
        bk_ge,          // greater equals (>=)
        bk_le,          // less equals (<=)
        bk_gt,          // greater than (>)
        bk_lt,          // less than (<)
        bk_add,         // +
        bk_sub,         // -
        bk_mod,         // %
        bk_div,         // /
        bk_mul,         // *
    };

    binop_kind getBinop(unsigned tokenKind) noexcept;

}
