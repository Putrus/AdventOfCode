#include "Chiton.h"

#include <fstream>

Chiton::Chiton(ComponentTask* task) : DecoratorTask(task) {
}

void Chiton::printResults() {
   printResultsArgs("Day15/TestInput.txt", "--- Day 15: Chiton ---");
   task->printResults();
}

void Chiton::loadInput(const char* filename) {
   std::ifstream file(filename);
   grid.clear();
   while (!file.eof()) {
      std::string strRow;
      file >> strRow;
      if (!strRow.empty()) {
         std::vector<int> row;
         for (auto const& octopus : strRow) {
            row.push_back(octopus - '0');
         }
         grid.push_back(row);
      }
   }
   file.close();
}

void Chiton::printResultPart1() {
   std::vector<std::vector<int>> dp;
   for (int i = 0; i < grid.size(); ++i) {
      std::vector<int> dpRow(0, grid[i].size());
      dp.push_back(dpRow);
   }

}

void Chiton::printResultPart2() {

}