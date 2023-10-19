#include "operations.h"
#include "../lex/token_type.h"

namespace ast {

    static binop_kind _binopTable[] = {
        bk_none,
        bk_div,
        bk_none, bk_none, bk_none, 
        bk_none,
        bk_none, bk_none,
        bk_lt,
        bk_gt,
        bk_none, bk_none, bk_none, bk_none, bk_none,
        bk_sub,
        bk_none, bk_none,
        bk_add,
        bk_mod,
        bk_mul,
        bk_none,
    };

    binop_kind getBinop(unsigned tokenKind) noexcept {
        return _binopTable[tokenKind];
    }

}
