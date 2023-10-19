#pragma once

#include "declaration.h"

namespace ast {

  /**
   * any named declaration (variable, object, function...)
  */
  class named_declaration : public declaration {
  public:
    inline named_declaration(semantic_location loc, const string32& _name) noexcept : declaration(loc, k_named_decl), name(_name)
    {}

  private:
    string32 name = {};
  };

  AST_DEFINITION(named_declaration)

}
