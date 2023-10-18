#pragma once

#include "common.h"

namespace lex {

    enum token_e {
        T_IDENTIFIER,           // a-zA-Z_0-9a-zA-z
        T_SLASH,                // /
        T_SINGLECOMMENT,        // //
        T_MULTICOMMENT_BEGIN,   // /*
        T_MULTICOMMENT_END,     // */
        T_ASSIGN,               // =
        T_CURLY_BEGIN,          // {
        T_CURLY_END,            // }
        T_LESS,                 // <
        T_GREATER,              // >
        T_COMMA,                // ,
        T_NUMBER_LITERAL,       // 0-9
        T_PAREN_OPEN,           // (
        T_PAREN_CLOSE,          // )
        T_COLON,                // :
        T_MINUS,                // -
        T_QUESTION,             // ?
        T_DOT,                  // .
        T_PLUS,                 // +
        T_PERCENT,              // %
        T_STAR,                 // *
        T_BANG,                 // !
        
        // token-keywords
        // primitive types:
        TK_VOID,                            // no type
        TK_I1,                              // boolean-ish
        TK_I8, TK_U8,                       // byte
        TK_I16, TK_U16,                     // word
        TK_I32, TK_U32,                     // dword
        TK_I64, TK_U64,                     // qword
        TK_I128, TK_U128,                   // oword
        TK_I256, TK_U256,                   // xword
        TK_F32, TK_F64, TK_F128, TK_F256,   // ieee754
        TK_PTR,                             // address
        TK_CSTR,                            // smart alias for just ptr<u8>
        // real keywords:
        TK_RETURN,  // return
        TK_IF,      // if
        TK_ELSE,    // else
        TK_ELIF,    // elif
        TK_MATCH,   // match
        TK_LOOP,    // loop/loop if
        TK_CALL,    // call
        TK_EQ,      // ==
        TK_NEQ,     // !=

        __TOKEN_TYPE_LAST
    };

    const string_view32 token_to_string_table[] = {
        L"(IDENTIFIER)",
        L"(SLASH)",
        L"(SINGLELINECOMMENT)",
        L"(MULTILINECOMMENTBEGIN)",
        L"(MULTILINECOMMENTEND)",
        L"(ASSIGN)",
        L"(CURLY_BEGIN)",
        L"(CURLY_END)",
        L"(LESS)",
        L"(GREATER)",
        L"(COMMA)",
        L"(NUMBER_LITERAL)",
        L"(PAREN_OPEN)",
        L"(PAREN_CLOSE)",
        L"(COLON)",
        L"(MINUS)",
        L"(QUESTION)",
        L"(DOT)",
        L"(PLUS)",
        L"(PERCENT)",
        L"(STAR)",
        L"(BANG)",

        L"(VOID)",
        L"(I1)",
        L"(I8)",
        L"(U8)",
        L"(I16)",
        L"(U16)",
        L"(I32)",
        L"(U32)",
        L"(I64)",
        L"(U64)",
        L"(I128)",
        L"(U128)",
        L"(I256)",
        L"(U256)",
        L"(F32)",
        L"(F64)",
        L"(F128)",
        L"(F256)",
        L"(PTR)",
        L"(CSTR)",

        L"(RETURN)",
        L"(IF)",
        L"(ELSE)",
        L"(ELIF)",
        L"(MATCH)",
        L"(LOOP)",
        L"(CALL)",
        L"(EQ)",
        L"(NEQ)",
    };

    static_assert(__TOKEN_TYPE_LAST == std::size(token_to_string_table), "Describe every token type!");

}
