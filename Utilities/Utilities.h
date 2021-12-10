#pragma once

#include <vector>
#include <string>

namespace uti {
   std::vector<int> split(const std::string &str);
   int median(const std::vector<int>& arr);
   float mean(const std::vector<int>& arr);
}