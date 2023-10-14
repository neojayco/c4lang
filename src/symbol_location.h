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

    string32 getFormatText(const size_t symbol_len) const noexcept;
};
