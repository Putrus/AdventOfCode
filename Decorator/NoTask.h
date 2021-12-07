#pragma once

#include "ComponentTask.h"

//concrete component
class NoTask : public ComponentTask {
public:
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   int getResultPart1() override;
   int getResultPart2() override;
};