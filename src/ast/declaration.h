#pragma once

#include "statement.h"

namespace ast {

  class declaration : statement {
  public:
    inline declaration(std::initializer_list<symbol_location> symloc, kind_e k = k_decl) noexcept : statement(symloc, k)
    {}

    virtual ~declaration() = default;

    inline auto getChildStmt() const noexcept {
      return children.back();
    }

    inline auto addChildStmt(ptr<statement>&& stmt) noexcept {
      return children.emplace_back(std::move(stmt));
    }

  protected:
    std::vector<ptr<statement>> children = {};
  };

}
