#include "Utilities.h"

#include <numeric>

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

int uti::median(const std::vector<int>& arr) {
   if (arr.size() % 2 == 0) {
      return (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2;
   }
   return arr[arr.size() - 1 / 2];
}

float uti::mean(const std::vector<int>& arr) {
   return std::reduce(arr.begin(), arr.end()) / (float)arr.size();
}