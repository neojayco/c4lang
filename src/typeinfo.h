#pragma once

namespace type {

    enum : unsigned {
        T_VOID  = 0,
        T_I1,                               // boolean-ish
        T_I8, T_U8,                         // byte
        T_I16, T_U16,                       // word
        T_I32, T_U32,                       // dword
        T_I64, T_U64,                       // qword
        T_I128, T_U128,                     // oword
        T_I256, T_U256,                     // xword
        T_F32, T_F64, T_F128, T_F256,       // ieee754
        T_PTR,                              // address
        T_CSTR,                             // ????smart alias for just ptr<u8>????
    };

    inline unsigned getDefaultIntegral() noexcept {
        return T_I32;
    }

    inline unsigned getDefaultIEEE754() noexcept {
        return T_F32;
    }

    inline bool isIntegral(const unsigned t) noexcept {
        return ((t >= T_I1) && (t <= T_U256)) || (t == T_PTR);
    }

    inline bool isIEEE754(const unsigned t) noexcept {
        return (t >= T_F32) && (t <= T_F256);
    }

    inline bool isSameTypeFamily(const unsigned t1, const unsigned t2) {
        if (isIntegral(t1) != isIntegral(t2)) {
            return false;
        }
        if (isIEEE754(t1) != isIEEE754(t2)) {
            return false;
        }
        if (t1 != t2) {
            // since they're probably should be cstr
            return false;
        }
        return true;
    }

    inline bool canCast(const unsigned t1, const unsigned t2) noexcept {
        // if t1 or t2 is nontype, return false
        if ((t1 == T_VOID) || (t2 == T_VOID)) {
            return false;
        }
        if (t1 == T_CSTR && t1 != t2) {
            return false;
        }
        // all other situations with primitive types should be pretty convertible in a simple way.
        return true;
    }

    inline bool canConvertUpper(const unsigned t) noexcept {
        // TODO: make a check for convert i.e: i32 -> i64 or i8 -> i16...
    }

}
