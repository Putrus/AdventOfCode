#include "ExtendedPolimerization.h"

#include <fstream>
#include <iostream>
#include <algorithm>

ExtendedPolimerization::ExtendedPolimerization(ComponentTask* task) : DecoratorTask(task) {
}

void ExtendedPolimerization::printResults() {
   printResultsArgs("Day14/Input.txt", "--- Day 14: Extended Polimerization ---");
   task->printResults();
}

void ExtendedPolimerization::loadInput(const char* filename) {
   std::ifstream file(filename);
   if (file.fail()) {
      std::cout << "Failed to load Input file!" << std::endl;
      file.close();
      return;
   }
   rules.clear();
   polymer.clear();
   file >> polymer;
   while (!file.eof()) {
      std::string first;
      file >> first;
      if (!first.empty()) {
         std::string arrow;
         char second;
         file >> arrow >> second;
         rules[first] = second;
      }
   }
   file.close();
}

void ExtendedPolimerization::printResultPart1() {
   printResultAfterSteps(10);
}

void ExtendedPolimerization::printResultPart2() {
   printResultAfterSteps(40);
}

void ExtendedPolimerization::printResultAfterSteps(int steps) {
   std::string mainPolymer = polymer;
   std::map<char, unsigned long long> quantities;
   std::map<std::string, unsigned long long> pairs;
   for (int i = 0; i < mainPolymer.length(); ++i) {
      if (quantities[mainPolymer[i]]) {
         ++quantities[mainPolymer[i]];
      }
      else {
         quantities[mainPolymer[i]] = 1;
      }
      if (i < mainPolymer.length() - 1) {
         std::string newPair = { mainPolymer[i], mainPolymer[i + 1] };
         if (pairs[newPair]) {
            ++pairs[newPair];
         }
         else {
            pairs[newPair] = 1;
         }
      }
   }
   for (int step = 0; step < steps; ++step) {
      std::map<std::string, unsigned long long> newPairs;
      for (auto const& pair : pairs) {
         std::string newPairL = { pair.first[0], rules[pair.first] };
         std::string newPairR = { rules[pair.first], pair.first[1] };
         newPairs[newPairL] = newPairs[newPairL] ? newPairs[newPairL] + pair.second : pair.second;
         newPairs[newPairR] = newPairs[newPairR] ? newPairs[newPairR] + pair.second : pair.second;
         quantities[rules[pair.first]] = quantities[rules[pair.first]] ? quantities[rules[pair.first]] + pair.second : pair.second;
      }
      pairs = newPairs;
   }
   auto maxElement = std::max_element(quantities.begin(), quantities.end(), [](
      const auto& lhs, const auto& rhs) {return lhs.second < rhs.second; });
   auto minElement = std::min_element(quantities.begin(), quantities.end(), [](
      const auto& lhs, const auto& rhs) {return lhs.second < rhs.second; });
   std::cout << maxElement->second - minElement->second;
}