#include "../inc/CampCleanup.h"

#include <fstream>
#include <iostream>
#include <string>

CampCleanup::CampCleanup(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void CampCleanup::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(4, "CampCleanup");
   puzzle->calcAndPrintAnswers();
}

void CampCleanup::loadInput(const char* input_path)
{
   std::fstream input(input_path);
   std::string line;
   while (std::getline(input, line))
   {
      pairs.push_back({ {stoi(line.substr(0, line.find('-'))), stoi(line.substr(line.find('-') + 1, line.find(',') - line.find('-') + 1)) },
         { stoi(line.substr(line.find(',') + 1, line.find_last_of('-') - line.find(',') + 1)), stoi(line.substr(line.find_last_of('-') + 1)) } });
   }
   input.close();
}

void CampCleanup::calcAndPrintAnswerToPart1()
{
   int counter = 0;
   for (auto const& pair : pairs)
   {
      if ((pair.first.first >= pair.second.first && pair.first.second <= pair.second.second) ||
         (pair.second.first >= pair.first.first && pair.second.second <= pair.first.second))
      {
         ++counter;
      }
   }
   std::cout << counter << std::endl;
}

void CampCleanup::calcAndPrintAnswerToPart2()
{
   int counter = 0;
   for (auto const& pair : pairs)
   {
      if ((pair.first.first >= pair.second.first && pair.first.first <= pair.second.second) ||
         (pair.first.second >= pair.second.first && pair.first.second <= pair.second.second) ||
         (pair.second.first >= pair.first.first && pair.second.first <= pair.first.second) ||
         (pair.second.second >= pair.first.first && pair.second.second <= pair.first.second))
      {
         ++counter;
      }
   }
   std::cout << counter << std::endl;
}
