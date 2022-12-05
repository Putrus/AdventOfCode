#include "../inc/CalorieCounting.h"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

CalorieCounting::CalorieCounting(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void CalorieCounting::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(1, "Calorie Counting");
   puzzle->calcAndPrintAnswers();
}

void CalorieCounting::loadInput(const char* input_path)
{
   std::ifstream input(input_path);
   std::string line;
   int sum = 0;
   while (std::getline(input, line))
   {
      if (line.empty())
      {
         sums.push_back(sum);
         sum = 0;
      }
      else
      {
         sum += stoi(line);
      }
   }
   input.close();
}

void CalorieCounting::calcAndPrintAnswerToPart1()
{
   int max = 0;
   for (auto const& sum : sums)
   {
      if (sum > max)
      {
         max = sum;
      }
   }
   std::cout << max << std::endl;
}

void CalorieCounting::calcAndPrintAnswerToPart2()
{
   std::vector<int> bests(3, 0);
   for (auto const& sum : sums)
   {
      if (sum > bests[0])
      {
         bests[0] = sum;
         std::sort(bests.begin(), bests.end());
      }
   }
   std::cout << bests[0] + bests[1] + bests[2] << std::endl;
}