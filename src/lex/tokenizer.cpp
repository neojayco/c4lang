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

    bool tokenizer::tokenize_main(token_stream_t& tokens) noexcept {

        while (is_safe_line()) {

            if (!is_spaced_line()) {

                while (issafe()) {
                    // don't allow any whitespace since they're not really usable in c4
                    while (issafe() && iswspace(current())) {
                        advance();
                    }
                    // go process characters
                    if (is_number_literal_start()) {
                        if (!_process_number_literal(tokens)) {
                            return false;
                        }
                    }
                    else if (is_valid_name_start()) {
                        if (!_process_text(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"//")) {
                        // process comments
                        if (!_process_singlinecomment(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"/*")) {
                        // this is a start of comments
                        if (!_process_multilinecommentbegin(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"*/")) {
                        // this is an end of comments
                        if (!_process_multilinecommentend(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"==")) {
                        std::wcerr << L"unimplemented: \n" << getLocation(i).getFormatText(2) << L'\n';
                        return false;
                    }
                    else if (is(L"=")) {
                        if (!_process_assign(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"{")) {
                        if (!_process_curly_begin(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"}")) {
                        if (!_process_curly_end(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"<=")) {
                        std::wcerr << L"unimplemented: \n" << getLocation(i).getFormatText(2) << L'\n';
                        return false;
                    }
                    else if (is(L">=")) {
                        std::wcerr << L"unimplemented: \n" << getLocation(i).getFormatText(2) << L'\n';
                        return false;
                    }
                    else if (is(L"<")) {
                        if (!_process_less(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L">")) {
                        if (!_process_greater(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L",")) {
                        if (!_process_comma(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"(")) {
                        if (!_process_paren_open(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L")")) {
                        if (!_process_paren_close(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L":")) {
                        if (!_process_colon(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"--")) {
                        std::wcerr << L"unimplemented: \n" << getLocation(i).getFormatText(2) << L'\n';
                        return false;
                    }
                    else if (is(L"-")) {
                        if (!_process_minus(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"?")) {
                        if (!_process_question(tokens)) {
                            return false;
                        }
                    }
                    else if (is(L"...")) {
                        std::wcerr << L"unimplemented: \n" << getLocation(i).getFormatText(3) << L'\n';
                        return false;
                    }
                    else if (is(L"..")) {
                        std::wcerr << L"unimplemented: \n" << getLocation(i).getFormatText(2) << L'\n';
                        return false;
                    }
                    else if (is(L".")) {
                        if (!_process_dot(tokens)) {
                            return false;
                        }
                    }
                    else {
                        std::wcerr << L"error: unrecognized character at line: \n" << getLocation(i).getFormatText(1) << L"\n";
                        return false;
                    }
                }

            }
            advance_line();
        }

        return true;
    }

    bool tokenizer::_process_text(token_stream_t& tokens) noexcept {
        const auto start = i;

        while (issafe() && (is_valid_name_start() || isdigit(current()))) {
            advance();
        }

        const auto len = i - start;
        const auto _text = current_line().substr(start, len);
        tokens.push_back(create_identifier({_text.data(), _text.size()}, getLocation(start)));

        return true;
    }

    bool tokenizer::_process_singlinecomment(token_stream_t& tokens) noexcept {

        const auto start = i;

        while (issafe()) {
            advance();
        }

        const auto len = i - start;
        const auto _commented = current_line().substr(start, len);
        tokens.push_back(create_single_comment(_commented, getLocation(start)));

        return true;
    }
    
    bool tokenizer::_process_multilinecommentbegin(token_stream_t& tokens) noexcept {
        tokens.push_back(create_multi_comment_begin(getLocation(i)));

        // skip '/*'
        advance();
        advance();

        return true;
    }
    
    bool tokenizer::_process_multilinecommentend(token_stream_t& tokens) noexcept {
        tokens.push_back(create_multi_comment_end(getLocation(i)));

        // skip '*/'
        advance();
        advance();

        return true;
    }
    
    bool tokenizer::_process_assign(token_stream_t &tokens) noexcept {
        
        tokens.push_back(create_assign(getLocation(i)));
        // skip '='
        advance();
        
        return true;
    }
    
    bool tokenizer::_process_curly_begin(token_stream_t &tokens) noexcept {

        tokens.push_back(create_curly_begin(getLocation(i)));

        // skip '{'
        advance();

        return true;
    }
    
    bool tokenizer::_process_curly_end(token_stream_t &tokens) noexcept {

        tokens.push_back(create_curly_end(getLocation(i)));

        // skip '}'
        advance();

        return true;
    }
    
    bool tokenizer::_process_less(token_stream_t &tokens) noexcept {

        tokens.push_back(create_less(getLocation(i)));

        // skip '<'
        advance();

        return true;
    }
    
    bool tokenizer::_process_greater(token_stream_t &tokens) noexcept {

        tokens.push_back(create_greater(getLocation(i)));

        // skip '>'
        advance();

        return true;
    }
    
    bool tokenizer::_process_comma(token_stream_t &tokens) noexcept {

        tokens.push_back(create_comma(getLocation(i)));

        // skip ','
        advance();

        return true;
    }
    
    bool tokenizer::_process_number_literal(token_stream_t &tokens) noexcept {
        
        const auto start = i;
        bool has_dot = false;
        bool has_number_mod = false;
        string32 _text = {};

        // carry about -1 +1
        if (current() == '-' || current() == '+') {
            _text.assign(1, current());
            advance();
        }

        // carry about .0 numbers
        if (current() == '.') {
            has_dot = true;
            _text.append(L"0.");
            advance();
        }

        while (issafe() && is_valid_number_literal_character()) {
            if (current() == '.' && has_dot) {
                std::wcerr << L"error: invalid number literal: \n" << getLocation(start).getFormatText(i - start);
                return false;
            }
            if (is_number_modifier()) {
                if (has_number_mod) {
                    std::wcerr << L"error: invalid number literal: \n" << getLocation(start).getFormatText(i - start);
                    return false;
                }
                has_number_mod = true;
            }
            _text.append(1, current());
            advance();
        }

        tokens.push_back(create_number_literal(_text, getLocation(start)));
        
        return true;
    }

    bool tokenizer::_process_paren_open(token_stream_t &tokens) noexcept {

        tokens.push_back(create_paren_open(getLocation(i)));

        // skip '('
        advance();

        return true;
    }
    
    bool tokenizer::_process_paren_close(token_stream_t &tokens) noexcept {

        tokens.push_back(create_paren_close(getLocation(i)));

        // skip ')'
        advance();

        return true;
    }
    
    bool tokenizer::_process_colon(token_stream_t &tokens) noexcept {

        tokens.push_back(create_colon(getLocation(i)));

        // skip ':'
        advance();

        return true;
    }
    
    bool tokenizer::_process_minus(token_stream_t &tokens) noexcept {
        
        tokens.push_back(create_minus(getLocation(i)));

        // skip '-'
        advance();

        return true;
    }
    
    bool tokenizer::_process_question(token_stream_t &tokens) noexcept {
        
        tokens.push_back(create_question(getLocation(i)));

        // skip '?'
        advance();

        return true;
    }
    
    bool tokenizer::_process_dot(token_stream_t &tokens) noexcept {
        
        tokens.push_back(create_dot(getLocation(i)));

        // skip '.'
        advance();

        return true;
    }
}
