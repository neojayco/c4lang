#pragma once

#include "common.h"
#include "../symbol_location.h"

namespace ast {

  class declaration {
  public:

    inline declaration(std::initializer_list<symbol_location> symloc, kind_e k) noexcept : kind(k), location(symloc) 
    {}

    virtual ~declaration() = default;

    constexpr kind_e getKind() const noexcept {
      return kind;
    }

    inline auto getLocation() const noexcept {
      return location;
    }

    inline auto getLocationText() const noexcept {
      return location.getFormatText();
    }

  private:
    kind_e kind = k_decl;
    semantic_location location;
  };

}
