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
   virtual int getResultPart1() override;
   virtual int getResultPart2() override;
   void printResultsArgs(const char* input, const char* taskName);
};