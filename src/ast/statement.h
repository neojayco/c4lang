#pragma once

#include "common.h"
#include "../symbol_location.h"

namespace ast {

    class statement {
    public:
        inline statement(std::initializer_list<symbol_location> symloc, kind_e k) noexcept : kind(k), location(symloc) 
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

    protected:
        std::vector<ptr<statement>> children = {};

    private:
        kind_e kind = k_decl;
        semantic_location location;
    };

}
