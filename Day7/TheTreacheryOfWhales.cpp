#include "TheTreacheryOfWhales.h"

#include "../Utilities/Utilities.h"

#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

TheTreacheryOfWhales::TheTreacheryOfWhales(ComponentTask* task) : DecoratorTask(task) {}

void TheTreacheryOfWhales::printResults() {
   printResultsArgs("Day7/Input.txt", "--- Day 7: The Treachery of Whales ---");
   task->printResults();
}

void TheTreacheryOfWhales::loadInput(const char* filename) {
   std::ifstream file(filename);
   std::string numString;
   file >> numString;
   crabs.clear();
   crabs = uti::split(numString);
   file.close();
}

void TheTreacheryOfWhales::printResultPart1() {
   std::sort(crabs.begin(), crabs.end());
   //the best is median in this case when we want minimalize fuel and fuel is ++
   int median = uti::median(crabs);
   int fuel = 0;
   for (auto const& el : crabs) {
      fuel += std::abs(el - median);
   }
   std::cout << fuel;
}

void TheTreacheryOfWhales::printResultPart2() {
   std::sort(crabs.begin(), crabs.end());
   //the best is median in this case when we want minimalize fuel and fuel is +1, +2, +3
   int mean = int(std::round(uti::mean(crabs) - 0.02f));
   int fuel = 0;
   for (auto const& el : crabs) {
      for (int i = 1; i <= std::abs(el - mean); ++i) {
         fuel += i;
      }
   }
   std::cout << fuel;
}