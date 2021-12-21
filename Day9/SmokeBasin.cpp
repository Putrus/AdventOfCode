#include "SmokeBasin.h"

#include <fstream>
#include <algorithm>
#include <iostream>

SmokeBasin::SmokeBasin(ComponentTask* task) : DecoratorTask(task) {
}

void SmokeBasin::printResults(){
   printResultsArgs("Day9/Input.txt", "--- Day 9: Smoke Basin ---");
   task->printResults();
}

void SmokeBasin::loadInput(const char* filename) {
   std::ifstream file(filename);
   while (!file.eof()) {
      std::string row;
      file >> row;
      if (!row.empty()) {
         std::vector<int> heightmapRow;
         std::transform(row.begin(), row.end(), std::back_inserter(heightmapRow),
            [](const char sign) {return sign - '0'; });
         heightmap.push_back(heightmapRow);
      }
   }
   file.close();
}

void SmokeBasin::printResultPart1() {
   int result = 0;
   for (int i = 0; i < (int)heightmap.size(); ++i) {
      for (int j = 0; j < (int)heightmap[i].size(); ++j) {
         if (checkAdjacents(i, j, int(heightmap.size()), int(heightmap[i].size()))) {
            result += heightmap[i][j] + 1;
         }
      }
   }
   std::cout << result;
}

void SmokeBasin::printResultPart2() {
   int result = 0;
   std::set<std::pair<int, int>> elements;
   std::vector<int> basinsSize;
   for (int i = 0; i < (int)heightmap.size(); ++i) {
      for (int j = 0; j < (int)heightmap[i].size(); ++j) {
         if (checkAdjacents(i, j, int(heightmap.size()), int(heightmap[i].size()))) {
            getBasin(j, i, elements);
            basinsSize.push_back(elements.size());
            elements.clear();
         }
      }
   }
   std::sort(basinsSize.begin(), basinsSize.end(), [](const auto& lhs, const auto& rhs) {
      return lhs > rhs; 
      });
   if (basinsSize.size() >= 3) {
      result = basinsSize[0] * basinsSize[1] * basinsSize[2];
   }
   std::cout << result;
}

bool SmokeBasin::checkAdjacents(int y, int x, int sizeY, int sizeX) {
   for (int i : {-1, 0, 1}) {
      for (int j : {-1, 0, 1}) {
         if (i != j && y + i >= 0 && x + j >= 0 
            && y + i < sizeY && x + j < sizeX) {
            if (heightmap[y + i][x + j] <= heightmap[y][x]) {
               return false;
            }
         }
      }
   }
   return true;
}

void SmokeBasin::getBasin(int x, int y, std::set<std::pair<int, int>> &elements) {
   if (heightmap.empty() || x < 0 || x >= heightmap[0].size()
      || y < 0 || y >= heightmap.size() || heightmap[y][x] == 9) {
      return;
   }
   elements.insert({ x, y });
   if (elements.find({ x - 1, y }) == elements.end()) {
      getBasin(x - 1, y, elements);
   }
   if (elements.find({ x + 1, y }) == elements.end()) {
      getBasin(x + 1, y, elements);
   }
   if (elements.find({ x, y - 1 }) == elements.end()) {
      getBasin(x, y - 1, elements);
   }
   if (elements.find({ x, y + 1}) == elements.end()) {
      getBasin(x, y + 1, elements);
   }
}