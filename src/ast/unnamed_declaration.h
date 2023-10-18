#pragma once

#include "named_declaration.h"

namespace ast {

  /**
   * basically just a block of code with nested children.
  */
  class unnamed_declaration : named_declaration {
  public:
    inline unnamed_declaration(std::initializer_list<symbol_location> symloc) noexcept : named_declaration(symloc, getRandomName())
    {}
  private:
    static string32 getRandomName() noexcept;
  };

}
