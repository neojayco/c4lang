#include "symbol_location.h"

#include <cmath>
#include <sstream>

constexpr auto MAX_LINE_NUM_DIGITS = 5;

string32 symbol_location::getFormatText(const size_t symbol_len) const noexcept {
    std::wstringstream ss;
    
    const long long numDigits = floor(log10(line.index) + 1);
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

