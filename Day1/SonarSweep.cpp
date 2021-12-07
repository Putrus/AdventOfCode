#include "SonarSweep.h"

#include <fstream>

SonarSweep::SonarSweep(ComponentTask *task) : DecoratorTask(task){}

void SonarSweep::printResults() {
   printResultsArgs("Day1/Input.txt", "--- Day 1: SonarSweep ---");
   task->printResults();
}

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

int SonarSweep::getResultPart1() {
   return getIncreases(depths);
}

int SonarSweep::getResultPart2() {
   std::vector<int> threes = createThrees();
   return getIncreases(threes);
}

int SonarSweep::getIncreases(const std::vector<int>& arr) {
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

std::vector<int> SonarSweep::createThrees() {
   std::vector<int> threes;
   for (size_t i = 0; i < depths.size() - 2; ++i) {
      threes.push_back(depths[i] + depths[i + 1] + depths[i + 2]);
   }
   return threes;
}
