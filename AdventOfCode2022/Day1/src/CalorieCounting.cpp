#include "../inc/CalorieCounting.h"

#include <fstream>
#include <iostream>
#include <string>

CalorieCounting::CalorieCounting(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void CalorieCounting::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(1, "Calorie Counting");
   puzzle->calcAndPrintAnswers();
}

void CalorieCounting::loadInput(const char* input_path)
{
   
}

void CalorieCounting::calcAndPrintAnswerToPart1()
{
   std::ifstream input_path("Day1/res/input_path.txt");
   std::string line;
   int max = 0;
   int sum = 0;
   while (std::getline(input_path, line))
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
   input_path.close();
   std::cout << max << std::endl;
}

void CalorieCounting::calcAndPrintAnswerToPart2()
{
}