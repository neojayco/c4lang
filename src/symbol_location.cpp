#include "symbol_location.h"

#include <cmath>
#include <sstream>

constexpr auto MAX_LINE_NUM_DIGITS = 5;

string32 symbol_location::getFormatText(const size_t symbol_len) const noexcept {
    std::wstringstream ss;
    long long numDigits = 0;

    if (line.index == 0) {
        numDigits = 1;
    }
    else {
        numDigits = floor(log10((line.index + 1)));
    }

    const size_t remainingZeros = std::max(0ll, MAX_LINE_NUM_DIGITS - numDigits);
    for (size_t i = 0; i < remainingZeros; ++i) {
        ss << L' ';
    }
    ss << std::to_wstring(line.index + 1) << L" | ";
    string32 offtext(MAX_LINE_NUM_DIGITS + 3 + offset, ' ');
    string32 marktext(symbol_len, L'^');
    ss << line.text << L'\n' << offtext << marktext;

    return ss.str();
}

static const size_t _calcLen(std::initializer_list<symbol_location> symlocs) noexcept {
    return symlocs.end()->offset - symlocs.begin()->offset;
}

semantic_location::semantic_location(std::initializer_list<symbol_location> symlocs)
    : symbol_location(symlocs.begin()->line.text, symlocs.begin()->line.index, symlocs.begin()->offset), semantic_len(_calcLen(symlocs))
{}

semantic_location::semantic_location(const symbol_location &symloc) : symbol_location(symloc), semantic_len(1)
{
}

string32 semantic_location::getFormatText() const noexcept {
  return symbol_location::getFormatText(semantic_len);
}
