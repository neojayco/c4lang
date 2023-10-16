#pragma once

#include "named_declaration.h"

namespace ast {

  class unnamed_declaration : named_declaration {
  public:
    inline unnamed_declaration(std::initializer_list<symbol_location> symloc) noexcept : named_declaration(symloc, getRandomName())
    {}
  private:
    static string32 getRandomName() noexcept;
  };

}
