#include "DecoratorTask.h"

#include <iostream>

DecoratorTask::DecoratorTask(ComponentTask * task) : task(task) {}

DecoratorTask::~DecoratorTask() {
   delete task;
}

void DecoratorTask::printResults() {
   task->printResults();
}

void DecoratorTask::loadInput(const char* filename) {
   return;
}

void DecoratorTask::printResultPart1() {
   return;
}

void DecoratorTask::printResultPart2() {
   return;
}

void DecoratorTask::printResultsArgs(const char * input, const char * taskName) {
   std::cout << taskName << std::endl;
   loadInput(input);
     
   std::cout << "Part 1: ";
   printResultPart1(); 
   std::cout << std::endl;

   std::cout << "Part 2: ";
   printResultPart2();
   std::cout << std::endl;
}