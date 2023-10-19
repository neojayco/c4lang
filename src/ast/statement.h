#pragma once

#include "common.h"
#include "../symbol_location.h"

namespace ast {

    class statement {
    public:
        inline statement(semantic_location loc, kind_e k = k_stmt) noexcept : kind(k), location(loc) 
        {}

        virtual ~statement() = default;

        constexpr kind_e getKind() const noexcept {
            return kind;
        }

        inline auto isOfKind(const kind_e k) const noexcept {
            return kind == k;
        }

        inline auto getLocation() const noexcept {
            return location;
        }

        inline auto getLocationText() const noexcept {
            return location.getFormatText();
        }


        inline auto getChildStmt() const noexcept {
            return children.back();
        }

        inline auto addChildStmt(ptr<statement>&& stmt) noexcept {
            return children.emplace_back(std::move(stmt));
        }

        inline auto begin() noexcept {
            return children.begin();
        }
        inline auto begin() const noexcept {
            return children.begin();
        }
        inline auto end() noexcept {
            return children.end();
        }
        inline auto end() const noexcept {
            return children.end();
        }

    protected:
        std::vector<ptr<statement>> children = {};

    private:
        kind_e kind = k_decl;
        semantic_location location;
    };

    AST_DEFINITION(statement)

}
