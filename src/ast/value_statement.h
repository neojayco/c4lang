#pragma once

#include "statement.h"

namespace ast {

    class value_statement : public statement {
    public:
        inline value_statement(semantic_location loc, kind_e k = k_value_stmt) noexcept : statement(loc, k)
        {}
    private:
        
    };

    AST_DEFINITION(value_statement)

}
