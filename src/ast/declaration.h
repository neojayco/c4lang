#pragma once

#include "statement.h"

namespace ast {

  class declaration : public statement {
  public:
    inline declaration(std::initializer_list<symbol_location> symloc, kind_e k = k_decl) noexcept : statement(symloc, k)
    {}

    virtual ~declaration() = default;
  };

}
