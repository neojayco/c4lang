#include "common.h"

#include <fstream>

bool load_file32(source_content& src, const char* filename) {

    std::wfstream f(filename);
    if (f.is_open()) {
        string32 line;
        while (std::getline(f, line)) {
            src.lines.emplace_back(std::move(line));
        }

        f.close();
        return true;
    }

    return false;
}
