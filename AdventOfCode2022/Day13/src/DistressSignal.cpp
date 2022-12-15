#include "../inc/DistressSignal.h"

#include <fstream>
#include <iostream>

DistressSignal::DistressSignal(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void DistressSignal::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(13, "Distress Signal");
   puzzle->calcAndPrintAnswers();
}

void DistressSignal::loadInput(const char* input_path)
{
   std::ifstream input(input_path);
   std::string first, second, line;
   while (std::getline(input, line))
   {
      if (line.empty())
      {
         pairs.push_back({ first, second });
         first.clear();
         second.clear();
         continue;
      }
      if (first.empty())
      {
         first = line;
         continue;
      }
      if (second.empty())
      {
         second = line;
         continue;
      }
   }
   input.close();
}

void DistressSignal::calcAndPrintAnswerToPart1()
{

}

void DistressSignal::calcAndPrintAnswerToPart2()
{

}