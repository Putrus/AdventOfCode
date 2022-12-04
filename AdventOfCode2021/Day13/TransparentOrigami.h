#pragma once

#include "../Decorator/DecoratorTask.h"

#include <string>
#include <vector>

class TransparentOrigami : public DecoratorTask {
private:
   std::vector<std::vector<char>> paper;
   std::vector<std::pair<char, int>> instructions;

public:
   TransparentOrigami(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;
};