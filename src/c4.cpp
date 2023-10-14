#include "lex/tokenizer.h"

auto main(int argc, char* argv[]) -> int {

    const auto filename = "../../rtlib/crt.c4";
    lex::source_content src;
    if (!lex::load_file32(src, filename)) {
        std::wcout << L"Failed to load file, not found!\n";
        return 1;
    }

    lex::tokenizer t(src);
    std::vector<lex::token_t> tokens;
    if (!t(tokens)) {
        return 1;
    }

    return 0;
}