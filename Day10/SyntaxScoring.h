#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>
#include <string>

class SyntaxScoring : public DecoratorTask {
private:
   std::vector<std::string> subsystem;

public:
   SyntaxScoring(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;
};