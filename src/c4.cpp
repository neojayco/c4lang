#include "lex/tokenizer.h"
#include "pass/post_lex.h"

static constexpr auto DEFAULT_TEST_FILEPATH = "../../rtlib/test.c4";

auto main(int argc, char* argv[]) -> int {

    const auto* filename = argv[1];
    if (argc != 2) {
        std::wcout << L"usage: ./c4 <filename>" << std::endl;
        filename = DEFAULT_TEST_FILEPATH;
        //return 1;
    }

    lex::source_content src;
    if (!lex::load_file32(src, filename)) {
        std::wcout << L"Failed to load file, not found!\n";
        return 1;
    }

    lex::tokenizer t(src);
    std::vector<lex::token_t> tokens;
    if (!t(tokens)) {
        //std::wcerr << tokens;
        std::wcout << L"tokens: " << tokens.size();
        return 1;
    }

    pass::lex::resolve_keywords(tokens);

    std::wcout << L"tokens: " << tokens.size() << std::endl;
    return 0;
}
