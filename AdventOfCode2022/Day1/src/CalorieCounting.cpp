#include "../inc/CalorieCounting.h"

#include <fstream>
#include <iostream>
#include <string>

CalorieCounting::CalorieCounting(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void CalorieCounting::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate("Day1/res/input.txt", "Calorie Counting");
   puzzle->calcAndPrintAnswers();
}

void CalorieCounting::loadInput(const char* filename)
{
   
}

void CalorieCounting::calcAndPrintAnswerToPart1()
{
   std::ifstream input("Day1/res/input.txt");
   std::string line;
   int max = 0;
   int sum = 0;
   while (std::getline(input, line))
   {
      if (line.empty())
      {
         if (sum > max)
         {
            max = sum;
         }
         sum = 0;
      }
      else
      {
         sum += stoi(line);
      }
   }
   input.close();
   std::cout << max << std::endl;
}

void CalorieCounting::calcAndPrintAnswerToPart2()
{
}