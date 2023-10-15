#include "post_lex.h"

namespace pass::lex {

  std::unordered_map<string32, ::lex::token_e> keyword_cstr_to_enum = {
    { L"i1",    ::lex::TK_I1 },
    { L"i8",    ::lex::TK_I8 },
    { L"u8",    ::lex::TK_U8 },
    { L"i16",   ::lex::TK_I16 },
    { L"u16",   ::lex::TK_U16 },
    { L"i32",   ::lex::TK_I32 },
    { L"u32",   ::lex::TK_U32 },
    { L"i64",   ::lex::TK_I64 },
    { L"u64",   ::lex::TK_U64 },
    { L"i128",  ::lex::TK_I128 },
    { L"u128",  ::lex::TK_U128 },
    { L"i256",  ::lex::TK_I256 },
    { L"u256",  ::lex::TK_U256 },
    { L"f32",   ::lex::TK_F32 },
    { L"f64",   ::lex::TK_F64 },
    { L"f128",  ::lex::TK_F128 },
    { L"f256",  ::lex::TK_F256 },
    { L"ptr",   ::lex::TK_PTR },
    { L"cstr",  ::lex::TK_CSTR },
    { L"return",::lex::TK_RETURN },
  };

  std::unordered_map<::lex::token_e, string32> keyword_enum_to_cstr = {
    { ::lex::TK_I1,   L"i1" },
    { ::lex::TK_I8,   L"i8" },
    { ::lex::TK_U8,   L"u8" },
    { ::lex::TK_I16,  L"i16" },
    { ::lex::TK_U16,  L"u16" },
    { ::lex::TK_I32,  L"i32" },
    { ::lex::TK_U32,  L"u32" },
    { ::lex::TK_I64,  L"i64" },
    { ::lex::TK_U64,  L"u64" },
    { ::lex::TK_I128, L"i128" },
    { ::lex::TK_U128, L"u128" },
    { ::lex::TK_I256, L"i256" },
    { ::lex::TK_U256, L"u256" },
    { ::lex::TK_F32,  L"f32" },
    { ::lex::TK_F64,  L"f64" },
    { ::lex::TK_F128, L"f128" },
    { ::lex::TK_F256, L"f256" },
    { ::lex::TK_PTR,  L"ptr" },
    { ::lex::TK_CSTR, L"cstr" },
    { ::lex::TK_RETURN, L"return" },
  };

  void resolve_keywords(::lex::token_stream_t& inout) noexcept {
    for (auto& token : inout) {
      if (token.hasText()) {
        const auto it = keyword_cstr_to_enum.find(token.getText());
        if (it != keyword_cstr_to_enum.end()) {
          token.kind = it->second;
        }
      }
    }
  }

}
