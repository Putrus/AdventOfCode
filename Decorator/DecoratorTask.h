#pragma once

#include "ComponentTask.h"

#include <memory>
#include <string>

class DecoratorTask : public ComponentTask {
protected:
   ComponentTask* task;

public:
   DecoratorTask(ComponentTask* task);
   virtual ~DecoratorTask();
   virtual void printResults();

protected:
   virtual void loadInput(const char* filename) override;
   virtual void printResultPart1() override;
   virtual void printResultPart2() override;
   void printResultsArgs(const char* input, const char* taskName);
};