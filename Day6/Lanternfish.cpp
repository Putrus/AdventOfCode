#include "Lanternfish.h"

#include "../Utilities/Utilities.h"

#include <fstream>
#include <algorithm>
#include <iostream>

Lanternfish::Lanternfish(ComponentTask* task) : DecoratorTask(task){
}

void Lanternfish::printResults() {
   printResultsArgs("Day6/Input.txt", "--- Lanternfish ---");
   task->printResults();
}

void Lanternfish::loadInput(const char* filename) {
   std::ifstream file(filename);
   std::string numString;
   file >> numString;
   fishes.clear();
   fishes = uti::split(numString);
   file.close();
}

void Lanternfish::printResultPart1() {
   std::cout << fishesAfterDays(80);
}

void Lanternfish::printResultPart2() {
   std::cout << fishesAfterDays(256);
}

unsigned long long Lanternfish::fishesAfterDays(int days) {
   std::vector<unsigned long long> fishesThatDay = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   for (size_t i = 0; i < fishes.size(); ++i) {
      ++fishesThatDay[fishes[i]];
   }
   for (int day = 0; day < days; ++day) {
      fishesThatDay = { fishesThatDay[1], fishesThatDay[2], fishesThatDay[3], fishesThatDay[4],
      fishesThatDay[5], fishesThatDay[6], fishesThatDay[0] + fishesThatDay[7], fishesThatDay[8], fishesThatDay[0] };
   }
   unsigned long long fishesAmount = 0;
   for (int i = 0; i < 9; ++i) {
      fishesAmount += fishesThatDay[i];
   }
   return fishesAmount;
}