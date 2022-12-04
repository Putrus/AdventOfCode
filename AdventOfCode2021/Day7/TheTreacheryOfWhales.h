#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>

class TheTreacheryOfWhales : public DecoratorTask {
private:
   //crabs' horizontal positions
   std::vector<int> crabs;

public:
   TheTreacheryOfWhales(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;
};