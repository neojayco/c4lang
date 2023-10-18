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
    k_stmt,           // k_stmt - a basic block
    k_value_stmt,     // k_value_stmt - a statement that holds some value

    k_decl,           // k_decl - a first declaration statement
    k_named_decl,     // k_named_decl - a declaration with name

    k_expr,           // k_expr - a base for every holy expression.
    k_literal_expr,   // k_literal_expr - a known value (e.g: 2, 1.23, etc...)
    k_binary_expr,    // k_binary_expr - a binary expression (a + b, x * y, etc...)
    k_unary_expr,     // k_unary_expr - an unary expression (-a, +b, !c, !!d...)
  };

}
