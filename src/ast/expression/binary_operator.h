#pragma once

#include "../expression.h"
#include "../operations.h"

namespace ast {

    class binary_operation : public expression {
    public:
        using opcode = binop_kind;

        inline binary_operation(const ptr<expression>& l, const ptr<expression>& r, opcode _opcode) noexcept 
            : expression(semantic_location({l->getLocation(), r->getLocation()}), k_binary_expr), lhs(std::move(l)), rhs(std::move(r)), op(_opcode)
        {}

        inline auto getOpcode() const noexcept {
            return op;
        }

        inline auto getLHS() const noexcept {
            return lhs;
        }

        inline auto getRHS() const noexcept {
            return rhs;
        }

    private:
        ptr<expression> lhs = {};
        ptr<expression> rhs = {};
        opcode op = {};
    };

    AST_DEFINITION(binary_operation)

}
