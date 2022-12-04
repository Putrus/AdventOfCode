#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>
#include <string>
#include <set>

class SmokeBasin : public DecoratorTask {
private:
   std::vector<std::vector<int>> heightmap;

public:
   SmokeBasin(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;

   bool checkAdjacents(int x, int y, int sizeX, int sizeY);
   void getBasin(int x, int y, std::set<std::pair<int, int>> &elements);
};