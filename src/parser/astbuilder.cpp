#include "astbuilder.h"

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
        // TODO: implement parsing...
    }

}
