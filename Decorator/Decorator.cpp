#include "Decorator.h"

#include <iostream>

Decorator::Decorator(InterfaceTask * task, std::string taskName) : task(task), taskName(taskName) {}

void Decorator::printResults() {
   if (!taskName.empty()) {
      loadInput((taskName.substr(0, taskName.find('/') + 1) + "Input.txt").c_str());
      std::cout << taskName << std::endl;
      std::cout << "Part 1: " << getResultPart1();
      std::cout << "Part 2: " << getResultPart2();
      task->printResults();
   }
}