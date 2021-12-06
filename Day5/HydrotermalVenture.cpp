#include "HydrotermalVenture.h"

#include <fstream>
#include <iostream>

HydrotermalVenture::HydrotermalVenture() {
   for (int i = 0; i < 1000; ++i) {
      std::vector<int> row(1000, 0);
      diagram.push_back(row);
   }
}

void HydrotermalVenture::loadInput(const char* filename) {
   std::ifstream file(filename);
   //lines.clear();
   //std::string p1;
   //std::string arrow;
   //std::string p2;
   //std::vector<int> split1;
   //std::vector<int> split2;
   //while (!file.eof()) {
   //   file >> p1 >> arrow >> p2;
   //   split1 = split(p1);
   //   split2 = split(p2);
   //   lines.push_back({ split1[0], split1[1], split2[0], split2[1] });
   //}
   //lines.erase(lines.end() - 1);
   file.close();
}

int HydrotermalVenture::getResultPart1() {
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

         while((incrX == 1) ? (startX <= endX) : (startX >= endX)) {
               ++diagram[startY][startX];
               startY += incrY;
               startX += incrX;
         }

        /* std::cout << line.x1 << ", " << line.y1 << " -> " << line.x2 << ", " << line.y2 << std::endl;
         printDiagram();*/
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
      /*std::cout << line.x1 << ", " << line.y1 << " -> " << line.x2 << ", " << line.y2 << std::endl;
      printDiagram();*/
   }

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

void HydrotermalVenture::printDiagram() {
   for (size_t i = 0; i < diagram.size(); ++i) {
      for (size_t j = 0; j < diagram[i].size(); ++j) {
         std::cout << diagram[i][j] << " ";
      }
      std::cout << std::endl;
   }
   std::cout << std::endl;
}