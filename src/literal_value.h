#pragma once

#include "common.h"
#include "typeinfo.h"

class literal_value {
public:

    literal_value() noexcept = default;
    constexpr explicit literal_value(bool v) noexcept : type(type::T_I1) {
        store(v);
    }
    constexpr explicit literal_value(signed char v) noexcept : type(type::T_I8) {
        store(v);
    }
    constexpr explicit literal_value(unsigned char v) noexcept : type(type::T_U8) {
        store(v);
    }
    constexpr explicit literal_value(signed short v) noexcept : type(type::T_I16) {
        store(v);
    }
    constexpr explicit literal_value(unsigned short v) noexcept : type(type::T_U16) {
        store(v);
    }
    constexpr explicit literal_value(signed int v) noexcept : type(type::T_I32) {
        store(v);
    }
    constexpr explicit literal_value(unsigned int v) noexcept : type(type::T_U32) {
        store(v);
    }
    constexpr explicit literal_value(signed long long v) noexcept : type(type::T_I64) {
        store(v);
    }
    constexpr explicit literal_value(unsigned long long v) noexcept : type(type::T_U64) {
        store(v);
    }
    constexpr explicit literal_value(float v) noexcept : type(type::T_F32) {
        store(v);
    }
    constexpr explicit literal_value(double v) noexcept : type(type::T_F64) {
        store(v);
    }

    constexpr bool isOfType(const unsigned t) const noexcept {
        return type == t;
    }

    inline auto getI1() const noexcept {
        return load<bool>();
    }
    inline auto getI8() const noexcept {
        return load<signed char>();
    }
    inline auto getU8() const noexcept {
        return load<unsigned char>();
    }
    inline auto getI16() const noexcept {
        return load<signed short>();
    }
    inline auto getU16() const noexcept {
        return load<unsigned short>();
    }
    inline auto getI32() const noexcept {
        return load<signed int>();
    }
    inline auto getU32() const noexcept {
        return load<unsigned int>();
    }
    inline auto getI64() const noexcept {
        return load<signed long long>();
    }
    inline auto getU64() const noexcept {
        return load<unsigned long long>();
    }
    inline auto getF32() const noexcept {
        return load<float>();
    }
    inline auto getF64() const noexcept {
        return load<double>();
    }

private:
    template<class T>
    inline void store(T&& v) noexcept {
        (*(T*)(storage)) = std::move(v);
    }
    template<class T>
    inline T load() const noexcept {
        return *(T*)storage;
    }

    char storage[sizeof(void*)] = {};
    unsigned type = type::T_VOID;
};
