#pragma once

#include <memory>

#include "../common.h"

/*
  fast simple example of code and parts of it:
  
  code:
  
    name_of_obj = {
      name_of_fn() i32 = {
        name_of_var const i32 = 69420
        return name_of_var
      }
    }

  parts:

  name_of_obj, name_of_fn, name_of_var - is a declaration of a statement
  69420 - is an expression, which is truly a statement... rite?
  return - is a statement, name_of_var is an expression? which means that expressions is also a statements!

       statement 
           |
        /    \ 
       /      \ 
      /        \ 
expression  declaration

*/

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

    k_expr,           // k_expr - a base for every holy expression.
    k_math_expr,      // k_math_expr - a math-only expressions since they're can be evaluated at compile-time.
    k_literal_expr,   // k_literal_expr - a known value (e.g: 2, 1.23, etc...)
    k_binary_expr,    // k_binary_expr - a binary expression (a + b, x * y, etc...)
    k_unary_expr,     // k_unary_expr - an unary expression (-a, +b, !c, !!d...)
  };

}
