#pragma once

#include <memory>

#include "../common.h"

namespace ast {

  template<class T>
  class ptr : public std::shared_ptr<T> {
  public:
    
    template<class...Args>
    static constexpr ptr<T> make(Args&&...args) noexcept {
      return std::make_shared<T>(std::forward<Args>(args)...);
    }

  };

  enum kind_e : uint32_t {
    k_decl,
    k_named_decl,

  };

}
