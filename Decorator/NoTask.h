#pragma once

#include "ComponentTask.h"

//concrete component
class NoTask : public ComponentTask {
private:
   void loadInput(const char* filename) override;
   int getResultPart1() override;
   int getResultPart2() override;
public:
   void printResults() override;
   
};