#pragma once

#include <vector>
#include <string>

struct Line {
   int x1, y1, x2, y2;
};


class HydrotermalVenture {
private:
   std::vector<std::vector<int>> diagram;
   std::vector<Line> lines;
public:
   HydrotermalVenture();
   void loadInput(const char* filename);
   int getResultPart1();
   void printDiagram();
};