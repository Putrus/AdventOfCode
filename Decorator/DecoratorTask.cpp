#include "DecoratorTask.h"

#include <iostream>

DecoratorTask::DecoratorTask(ComponentTask * task) : task(task) {}

DecoratorTask::~DecoratorTask() {
   delete task;
}

void DecoratorTask::loadInput(const char* filename) {
   return;
}

int DecoratorTask::getResultPart1() {
   return 0;
}

int DecoratorTask::getResultPart2() {
   return 0;
}

void DecoratorTask::printResults() {
   task->printResults();
}

void DecoratorTask::printResultsArgs(const char * input, const char * taskName) {
      loadInput(input);
      std::cout << taskName << std::endl;
      std::cout << "Part 1: " << getResultPart1() << std::endl;
      std::cout << "Part 2: " << getResultPart2() << std::endl << std::endl;
}