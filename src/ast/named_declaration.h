#pragma once

#include "declaration.h"

namespace ast {

  class named_declaration : public declaration {
  public:
    inline named_declaration(std::initializer_list<symbol_location> symloc, const string32& _name) noexcept : declaration(symloc, k_named_decl), name(_name)
    {}
  private:
    string32 name = {};
  };

}
