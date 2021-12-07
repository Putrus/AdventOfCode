#include "HydrothermalVenture.h"

#include <fstream>
#include <iostream>

HydrothermalVenture::HydrothermalVenture(ComponentTask* task) : DecoratorTask(task) {}

void HydrothermalVenture::printResults() {
   printResultsArgs("Day5/Input.txt", "--- Hydrothermal Venture ---");
   task->printResults();
}

void HydrothermalVenture::loadInput(const char* filename) {
   std::ifstream file(filename);
   lines.clear();
   std::string p1;
   std::string arrow;
   std::string p2;
   std::vector<int> split1;
   std::vector<int> split2;
   while (!file.eof()) {
      file >> p1 >> arrow >> p2;
      split1 = uti::split(p1);
      split2 = uti::split(p2);
      lines.push_back({ split1[0], split1[1], split2[0], split2[1] });
   }
   lines.erase(lines.end() - 1);
   file.close();
}

int HydrothermalVenture::getResultPart1() {
   clearDiagram();
   for (auto const& line : lines) {  
      if (line.x1 == line.x2) {
         for (size_t i = std::min(line.y1, line.y2); i <= std::max(line.y1, line.y2); ++i) {
            ++diagram[i][line.x1];
         }
      }
      if (line.y1 == line.y2) {
         for (size_t i = std::min(line.x1, line.x2); i <= std::max(line.x1, line.x2); ++i) {
            ++diagram[line.y1][i];
         }
      }
   }
   return countTwoLinesOverlap();
}

int HydrothermalVenture::getResultPart2() {
   clearDiagram();
   for (int i = 0; i < 1000; ++i) {
      std::vector<int> row(1000, 0);
      diagram.push_back(row);
   }
   for (auto const& line : lines) {
      if (abs(line.x1 - line.x2) == abs(line.y1 - line.y2)) {
         int incrX = 1;
         int startX = line.x1;
         int endX = line.x2;
         if (line.x1 > line.x2) {
            incrX = -1;
         }

         int incrY = 1;
         int startY = line.y1;
         int endY = line.y2;
         if (line.y1 > line.y2) {
            incrY = -1;
         }

         while ((incrX == 1) ? (startX <= endX) : (startX >= endX)) {
            ++diagram[startY][startX];
            startY += incrY;
            startX += incrX;
         }
         continue;
      }

      if (line.x1 == line.x2) {
         for (size_t i = std::min(line.y1, line.y2); i <= std::max(line.y1, line.y2); ++i) {
            ++diagram[i][line.x1];
         }
      }
      if (line.y1 == line.y2) {
         for (size_t i = std::min(line.x1, line.x2); i <= std::max(line.x1, line.x2); ++i) {
            ++diagram[line.y1][i];
         }
      }
   }
   return countTwoLinesOverlap();
}

void HydrothermalVenture::clearDiagram() {
   diagram.clear();
   for (int i = 0; i < 1000; ++i) {
      std::vector<int> row(1000, 0);
      diagram.push_back(row);
   }
}

int HydrothermalVenture::countTwoLinesOverlap() {
   int result = 0;
   for (size_t i = 0; i < diagram.size(); ++i) {
      for (size_t j = 0; j < diagram[i].size(); ++j) {
         if (diagram[i][j] >= 2) {
            ++result;
         }
      }
   }
   return result;
}
