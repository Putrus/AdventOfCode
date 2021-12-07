#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>
#include <string>

class Dive : public DecoratorTask {
private:
   //horizontal position
   int x;
   //depth
   int y;
   int aim;
   std::vector<std::pair<std::string, int>> commands;

public:
   Dive(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   int getResultPart1() override;
   int getResultPart2() override;
};