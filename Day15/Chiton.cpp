#include "Chiton.h"

#include <fstream>
#include <iostream>

Chiton::Chiton(ComponentTask* task) : DecoratorTask(task) {
}

void Chiton::printResults() {
   printResultsArgs("Day15/Input.txt", "--- Day 15: Chiton ---");
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
   std::vector<std::vector<std::pair<int, bool>>> dp;
   for (int i = 0; i < grid.size(); ++i) {
      std::vector<std::pair<int, bool>> dpRow(grid[i].size(), { INT_MAX, true });
      dp.push_back(dpRow);
   }
   dp[0][0] = { 0, true };
   int Qsize = grid.size() * grid[0].size();
   while (true) {
      int x = -1;
      int y = -1;
      int min = INT_MAX;
      for (int i = 0; i < dp.size(); ++i) {
         for (int j = 0; j < dp[0].size(); ++j) {
            if (dp[i][j].first < min && dp[i][j].second) {
               x = j;
               y = i;
               min = dp[i][j].first;
            }
         }
      }
      if (x == -1 && y == -1) {
         break;
      }
      dp[y][x].second = false;
      if (x >= 1 && dp[y][x - 1].second) {
         dp[y][x - 1].first = std::min(dp[y][x - 1].first, dp[y][x].first + grid[y][x - 1]);
      }
      if (y >= 1 && dp[y - 1][x].second) {
         dp[y - 1][x].first = std::min(dp[y - 1][x].first, dp[y][x].first + grid[y - 1][x]);
      }
      if (x < dp[0].size() - 1 && dp[y][x + 1].second) {
         dp[y][x + 1].first = std::min(dp[y][x + 1].first, dp[y][x].first + grid[y][x + 1]);
      }
      if (y < dp.size() - 1 && dp[y + 1][x].second) {
         dp[y + 1][x].first = std::min(dp[y + 1][x].first, dp[y][x].first + grid[y + 1][x]);
      }
   }
   std::cout << dp[dp.size() - 1][dp[0].size() - 1].first;
}

void Chiton::printResultPart2() {

}
