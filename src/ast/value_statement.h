#pragma once

#include "statement.h"

namespace ast {

    class value_statement : public statement {
    public:
        inline value_statement(std::initializer_list<symbol_location> symloc, kind_e k = k_value_stmt) noexcept : statement(symloc, k)
        {}
    private:
        
    };

}
