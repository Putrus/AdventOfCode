#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>

class Lanternfish : public DecoratorTask{
private:
   std::vector<int> fishes;

public:
   Lanternfish(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;

   unsigned long long fishesAfterDays(int days);
};