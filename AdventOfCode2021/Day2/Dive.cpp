#include "Dive.h"

#include <iostream>
#include <fstream>

Dive::Dive(ComponentTask * task) : DecoratorTask(task), x(0), y(0), aim(0){}

void Dive::printResults() {
   printResultsArgs("Day2/Input.txt", "--- Day 2: Dive! ---");
   task->printResults();
}

void Dive::loadInput(const char* filename) {
   std::ifstream file(filename);
   while (!file.eof()) {
      int val;
      std::string comm;
      file >> comm >> val;
      commands.push_back({ comm, val });
   }
   commands.erase(commands.end() - 1);
   file.close();
}

void Dive::printResultPart1() {
   x = 0;
   y = 0;
   for (auto const& command : commands) {
      if (command.first == "forward") {
         x += command.second;
      }
      else if (command.first == "up") {
         y -= command.second;
      }
      else {
         y += command.second;
      }
   }
   std::cout << x * y;
}

void Dive::printResultPart2() {
   x = 0;
   y = 0;
   aim = 0;
   for (auto const& command : commands) {
      if (command.first == "forward") {
         x += command.second;
         y += aim * command.second;
      }
      else if (command.first == "up") {
         aim -= command.second;
      }
      else {
         aim += command.second;
      }
   }
   std::cout << x * y;
}
