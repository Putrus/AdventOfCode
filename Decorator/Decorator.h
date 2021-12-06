#pragma once

#include "InterfaceTask.h"

#include <memory>
#include <string>

class Decorator {
protected:
   std::unique_ptr<InterfaceTask> task;
   std::string taskName;
protected:
   virtual void loadInput(const char* filename) = 0;
   virtual int getResultPart1() = 0;
   virtual int getResultPart2() = 0;

public:
   Decorator(InterfaceTask* task, std::string taskName = nullptr);

   void printResults();
};