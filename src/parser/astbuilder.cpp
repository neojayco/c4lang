#include "astbuilder.h"
#include "../ast/operations.h"
#include "../ast/expression/binary_operator.h"

namespace parser {

    ast::ptr_statement astbuilder::parse_primary() noexcept {
        const auto ftoken = peek(0);
        if (ftoken) {
            auto elderStmt = ast::ptr_statement::make(ftoken->location);

            while (issafe()) {

                // TODO: parse different statements here...
                switch (ftoken->kind) {
                    case lex::T_NUMBER_LITERAL: elderStmt->addChildStmt(parse_expression()); break;
                    default: {
                        std::wcerr << "failed to parse statement: \n" << ftoken->location.getFormatText(ftoken->hasText() ? ftoken->getText().size() : 1);
                        return nullptr;
                    } break;
                }
            }

            return elderStmt;
        }
        return nullptr;
    }

    ast::ptr_expression astbuilder::parse_expression() noexcept {
        return parse_binary_expression();
    }

    ast::ptr_expression astbuilder::parse_primary_expression() noexcept {
        
    }

    ast::ptr_expression astbuilder::parse_binary_expression(unsigned prec) noexcept {
        ast::ptr_expression left = nullptr;
        // TODO: unary check
        if (false) {

        }
        else {
            left = parse_primary_expression();
        }
        for (;;) {
            const auto binopKindPrec = ast::getBinop(current().kind);
            if (binopKindPrec == 0 || binopKindPrec < prec) {
                break;
            }
            advance(); // go to next expression
            const auto right = parse_binary_expression(binopKindPrec);
            left = ast::bina
        }
    }
}
