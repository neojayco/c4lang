#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <functional>
#include <optional>
#include <iostream>

using string32 = std::wstring;
using string_view32 = std::wstring_view;

struct source_content {
    std::vector<string32> lines;
};

bool load_file32(source_content& src, const char* filename);
