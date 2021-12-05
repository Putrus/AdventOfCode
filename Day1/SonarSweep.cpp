#include "SonarSweep.h"

#include <iostream>
#include <fstream>


void SonarSweep::loadInput(const char* filename) {
   std::ifstream file(filename);
   while (!file.eof()) {
      int n;
      file >> n;
      depths.push_back(n);
   }
   depths.erase(depths.end() - 1);
   file.close();
}

int SonarSweep::getIncreases(std::vector<int> &arr) {
   int lastElement = 0;
   int result = 0;
   if (arr.size()) {
      lastElement = arr[0];
   }
   for (size_t i = 1; i < arr.size(); ++i) {
      if (lastElement < arr[i]) {
         ++result;
      }
      lastElement = arr[i];
   }
   return result;
}

int SonarSweep::getResultPart1() {
   return getIncreases(depths);
}

int SonarSweep::getResultPart2() {
   createThrees();
   return getIncreases(threes);
}

void SonarSweep::createThrees() {
   threes.clear();
   for (size_t i = 0; i < depths.size() - 2; ++i) {
      threes.push_back(depths[i] + depths[i + 1] + depths[i + 2]);  
   }
}