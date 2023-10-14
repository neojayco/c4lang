#include "tokenizer.h"
#include <ctype.h>

namespace lex {

    static bool __issafe(const tokenizer* pTok) {
        return pTok->is_buffer_empty() == false;
    }

    #define issafe() __issafe(this)

    static bool isEmoji(int value, int &count)
    {
        if ((value >= 0xd800 && value <= 0xdbff))
        {
            count = 2;
            return true;
        }
        else if ((0x2100 <= value && value <= 0x27ff && value != 0x263b)
            || (0x2b05 <= value && value <= 0x2b07)
            || (0x2934 <= value && value <= 0x2935)
            || (0x3297 <= value && value <= 0x3299)
            || value == 0xa9 || value == 0xae || value == 0x303d || value == 0x3030
            || value == 0x2b55 || value == 0x2b1c || value == 0x2b1b || value == 0x2b50
            || value == 0x231a)
        {
            count = 1;
            return true;
        }
        return false;
    }

    symbol_location tokenizer::getLocation(const size_t start) const noexcept {
        return { current_line(), line_idx, start };
    }

    bool tokenizer::is_valid_name_start() const noexcept {
        int t;
        return (iswalpha(current()) || isalpha(current()) || current() == L'_' || isEmoji(current(), t));
    }

    bool tokenizer::tokenize_main(std::vector<token_t>& tokens) noexcept {

        while (is_safe_line()) {

            while (issafe()) {
                // don't allow any whitespace since they're not really usable in c4
                while (issafe() && iswspace(current())) {
                    advance();
                }
                // go process characters
                if (issafe() && is_valid_name_start()) {
                    if (!_process_text(tokens)) {
                        return false;
                    }
                }
                else if (issafe() && is(L"//")) {
                    // process comments
                    if (!_process_singlinecomment(tokens)) {
                        return false;
                    }
                }
                else {
                    std::wcerr << "error: unrecognized character at line: \n" << getLocation(i).getFormatText(1);
                    return false;
                }
            }

            advance_line();
        }

        return true;
    }

    bool tokenizer::_process_text(std::vector<token_t>& tokens) noexcept {
        const auto start = i;

        while (issafe() && (is_valid_name_start() || isdigit(current()))) {
            advance();
        }

        const auto len = i - start;
        const auto _text = current_line().substr(start, len);
        tokens.push_back(create_identifier({_text.data(), _text.size()}, getLocation(start)));

        return true;
    }

    bool tokenizer::_process_singlinecomment(std::vector<token_t> &tokens) noexcept {

        const auto start = i;

        while (issafe()) {
            advance();
        }

        const auto len = i - start;
        const auto _commented = current_line().substr(start, len);
        tokens.push_back(create_single_comment(_commented, getLocation(start)));

        return true;
    }
}
