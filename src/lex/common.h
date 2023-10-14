#pragma once
#include "../common.h"
#include "../symbol_location.h"

namespace lex {

    struct source_content {
        std::vector<string32> lines;
    };

    bool load_file32(source_content& src, const char* filename);

}
