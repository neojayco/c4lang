#include "tokenizer.h"
#include <ctype.h>

bool tokenizer::tokenize_main(std::vector<token_t>& tokens) noexcept {
    
    const auto issafe = [this]() -> bool { return !is_buffer_empty(); };

    while (issafe()) {
        // don't allow any whitespace since they're not
        while (issafe() && isspace(current())) {
            advance();
        }
    }

}
