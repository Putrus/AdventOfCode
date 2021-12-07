#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>

class SonarSweep : public DecoratorTask{
private:
   std::vector<int> depths;

public:
   SonarSweep(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   int getResultPart1() override;
   int getResultPart2() override;

   int getIncreases(const std::vector<int>& arr);
   std::vector<int> createThrees();
};
