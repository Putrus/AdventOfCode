#pragma once

#include "../Decorator/DecoratorTask.h"

#include <string>
#include <map>

class ExtendedPolimerization : public DecoratorTask {
private:
   std::string polymer;
   std::map<std::string, char> rules;

public:
   ExtendedPolimerization(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;

   void printResultAfterSteps(int steps);
};