#pragma once

#include "lex/common.h"

struct symbol_location {
    struct {
        const string32& text;
        const size_t index;
    } const line;
    const size_t offset;

    inline symbol_location(const string32& _line_text, const size_t _line_index, const size_t _offset) noexcept 
        : line{ _line_text, _line_index }, offset(_offset)
    {}

    inline symbol_location(const symbol_location&) = default;
    inline symbol_location& operator=(const symbol_location&) = delete;
    inline symbol_location(symbol_location&&) noexcept = default;
    inline symbol_location& operator=(symbol_location&&) noexcept = delete;

    string32 getFormatText(const size_t symbol_len) const noexcept;
};

struct semantic_location : symbol_location {
    const size_t semantic_len;

    inline semantic_location(const string32& _line_text, const size_t _line_index, const size_t _offset, const size_t _semlen)
        : symbol_location(_line_text, _line_index, _offset), semantic_len(_semlen)
    {}

    semantic_location(std::initializer_list<symbol_location> symlocs);

    string32 getFormatText() const noexcept;
};
