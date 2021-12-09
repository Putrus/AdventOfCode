#pragma once

#include "../Decorator/DecoratorTask.h"
#include "../Utilities/Utilities.h"

#include <vector>
#include <string>

struct Line {
   int x1, y1, x2, y2;
};

class HydrothermalVenture : public DecoratorTask{
private:
   std::vector<std::vector<int>> diagram;
   std::vector<Line> lines;

public:
   HydrothermalVenture(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;
   
   void clearDiagram();
   int countTwoLinesOverlap();
};