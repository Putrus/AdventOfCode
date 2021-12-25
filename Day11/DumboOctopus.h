#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>
#include <string>

class DumboOctopus : public DecoratorTask {
private:
   std::vector<std::vector<int>> grid;

public:
   DumboOctopus(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;

   void increaseEnergy(int x, int y, int &flashes);
};