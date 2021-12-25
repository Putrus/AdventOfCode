#include "DumboOctopus.h"

#include <fstream>
#include <iostream>

DumboOctopus::DumboOctopus(ComponentTask* task) : DecoratorTask(task) {
}

void DumboOctopus::printResults() {
   printResultsArgs("Day11/Input.txt", "--- Day 11: Dumbo Octopus ---");
   task->printResults();
}

void DumboOctopus::loadInput(const char* filename) {
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

void DumboOctopus::printResultPart1() {
   int flashes = 0;
   for (int i = 0; i < 100; ++i) {
      for (int y = 0; y < grid.size(); ++y) {
         for (int x = 0; x < grid[y].size(); ++x) {
            increaseEnergy(x, y, flashes);
         }
      }
      for (int y = 0; y < grid.size(); ++y) {
         for (int x = 0; x < grid[y].size(); ++x) {
            if (grid[y][x] >= 10) {
               grid[y][x] = 0;
            }
         }
      }
   }
   std::cout << flashes;
}

void DumboOctopus::printResultPart2() {
   int flashesInDay = 0;
   int step = 0;
   while (flashesInDay != grid.size() * grid[0].size()) {
      flashesInDay = 0;
      for (int y = 0; y < grid.size(); ++y) {
         for (int x = 0; x < grid[y].size(); ++x) {
            increaseEnergy(x, y, flashesInDay);
         }
      }
      for (int y = 0; y < grid.size(); ++y) {
         for (int x = 0; x < grid[y].size(); ++x) {
            if (grid[y][x] >= 10) {
               grid[y][x] = 0;
            }
         }
      }
      ++step;
   }
   //+100, because 100 steps in part 1
   std::cout << step + 100;
}

void DumboOctopus::increaseEnergy(int x, int y, int &flashes) {
   ++grid[y][x];
   if (grid[y][x] == 10) {
      ++flashes;
      if (y >= 1) {
         increaseEnergy(x, y - 1, flashes);
         if (x < grid[y].size() - 1) {
            increaseEnergy(x + 1, y - 1, flashes);
         }
         if (x >= 1) {
            increaseEnergy(x - 1, y - 1, flashes);
         }
      }
      if (y < grid.size() - 1) {
         increaseEnergy(x, y + 1, flashes);
         if (x < grid[y].size() - 1) {
            increaseEnergy(x + 1, y + 1, flashes);
         }
         if (x >= 1) {
            increaseEnergy(x - 1, y + 1, flashes);
         }
      }
      if (x < grid[y].size() - 1) {
         increaseEnergy(x + 1, y, flashes);
      }
      if (x >= 1) {
         increaseEnergy(x - 1, y, flashes);
      }
   }
}