#pragma once

#include "../expression.h"

namespace ast {

    class parenthesized_expression : public expression {
    public:


    private:
        ptr<expression> innerExpr
    };

}
