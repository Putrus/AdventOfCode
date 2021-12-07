#include "Utilities.h"


std::vector<int> uti::split(const std::string &str) {
   int last = 0;
   std::vector<int> result;
   for (size_t i = 0; i < str.length(); ++i) {
      if (str[i] == ',') {
         result.push_back(atoi(str.substr(last, i - last).c_str()));
         last = i + 1;
      }
   }
   result.push_back(atoi(str.substr(last, str.length() - last).c_str()));
   return result;
}