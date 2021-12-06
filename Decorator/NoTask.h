#pragma once

#include "InterfaceTask.h"

class NoTask : public InterfaceTask {
protected:
   void loadInput(const char* filename);
   int getResultPart1();
   int getResultPart2();

public:
   void printResults();
};