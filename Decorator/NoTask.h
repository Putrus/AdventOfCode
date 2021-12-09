#pragma once

#include "ComponentTask.h"

//concrete component
class NoTask : public ComponentTask {
public:
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;
};