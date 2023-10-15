#pragma once

#include "../lex/tokenizer.h"

namespace pass::lex {

  extern std::unordered_map<string32, ::lex::token_e> keyword_cstr_to_enum;
  extern std::unordered_map<::lex::token_e, string32> keyword_enum_to_cstr;

  void resolve_keywords(::lex::token_stream_t& inout) noexcept;

}
