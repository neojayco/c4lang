#include "lex/tokenizer.h"

constexpr const std::string_view src = {
"s"
};

auto main(int argc, char* argv[]) -> int {

    tokenizer t(src);
    std::vector<token_t> tokens;
    if (!t(tokens)) {
        return 1;
    }

    return 0;
}
