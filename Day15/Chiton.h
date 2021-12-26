#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>

class Chiton : public DecoratorTask {
private:
   std::vector<std::vector<int>> grid;

public:
   Chiton(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;

   void printResultAfterSteps(int steps);
};