#include "Chiton.h"

#include <fstream>
#include <iostream>
#include <time.h>

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
   //myDijkstra(grid);
}

void Chiton::printResultPart2() {
   //create grid 5x5
   std::vector<std::vector<int>> grid5 = grid;
   for (int i = 10; i < grid.size() * 5; ++i) {
      std::vector<int> row;
      for (int j = 0; j < grid[0].size(); ++j) {
         int value = grid5[i - 10][j] == 9 ? 1 : grid5[i - 10][j] + 1;
         row.push_back(value);
      }
      grid5.push_back(row);
   }
   for (int i = 0; i < grid5.size(); ++i) {
      for (int j = 10; j < grid[0].size() * 5; ++j) {
         int value = grid5[i][j - 10] == 9 ? 1 : grid5[i][j - 10] + 1;
         grid5[i].push_back(value);
      }
   }
   myDijkstra(grid5);
}

void Chiton::myDijkstra(std::vector<std::vector<int>>& grid) {
   std::vector<std::vector<int>> dp;
   for (int i = 0; i < grid.size(); ++i) {
      std::vector<int> dpRow(grid[i].size(), INT_MAX);
      dp.push_back(dpRow);
   }
   dp[0][0] = 0;
   clock_t start = clock();
   while (true) {
      if (clock() - start > 240000) {
         break;
      }
      for (int y = 0; y < dp.size(); ++y) {
         for (int x = 0; x < dp[0].size(); ++x) {
            if (x >= 1 && dp[y][x - 1] > dp[y][x] + grid[y][x - 1]) {
               dp[y][x - 1] = dp[y][x] + grid[y][x - 1];
            }
            if (y >= 1 && dp[y - 1][x] > dp[y][x] + grid[y - 1][x]) {
               dp[y - 1][x] = dp[y][x] + grid[y - 1][x];
            }
            if (x < dp[0].size() - 1 && dp[y][x + 1] > dp[y][x] + grid[y][x + 1]) {
               dp[y][x + 1] = dp[y][x] + grid[y][x + 1];
            }
            if (y < dp.size() - 1 && dp[y + 1][x] > dp[y][x] + grid[y + 1][x]) {
               dp[y + 1][x] = dp[y][x] + grid[y + 1][x];
            }
         }
      }
   }
   std::cout << dp[dp.size() - 1][dp[0].size() - 1];
}