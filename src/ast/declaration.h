#pragma once

#include "statement.h"

namespace ast {

  class declaration : public statement {
  public:
    inline declaration(semantic_location loc, kind_e k = k_decl) noexcept : statement(loc, k)
    {}

    virtual ~declaration() = default;
  };

  AST_DEFINITION(declaration)

}
