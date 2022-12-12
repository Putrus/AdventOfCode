#include "../inc/RucksackReorganization.h"

#include <fstream>
#include <iostream>

RucksackReorganization::RucksackReorganization(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void RucksackReorganization::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(3, "Rucksack Reorganization");
   puzzle->calcAndPrintAnswers();
}

void RucksackReorganization::loadInput(const char* input_path)
{
   std::fstream input(input_path);
   std::string rucksack;
   while (std::getline(input, rucksack))
   {
      rucksacks.push_back(rucksack);
   }
   input.close();
}

void RucksackReorganization::calcAndPrintAnswerToPart1()
{
   int sum = 0;
   for (auto const& rucksack : rucksacks)
   {
      char type = commonType(rucksack);
      if (type <= 'z' && type >= 'a')
      {
         sum += type - 'a' + 1;
      }
      else
      {
         sum += type - 'A' + 27;
      }
   }
   std::cout << sum << std::endl;
}

void RucksackReorganization::calcAndPrintAnswerToPart2()
{
   int sum = 0;
   int counter = 0;
   std::string l1, l2, l3;
   for (auto const& rucksack : rucksacks)
   {
      ++counter;
      if (counter == 1)
      {
         l1 = rucksack;
      }
      else if (counter == 2)
      {
         l2 = rucksack;
      }
      else
      {
         l3 = rucksack;
         char group = commonGroup(l1, l2, l3);
         if (group <= 'z' && group >= 'a')
         {
            sum += group - 'a' + 1;
         }
         else
         {
            sum += group - 'A' + 27;
         }
         counter = 0;
      }
   }
   std::cout << sum << std::endl;
}

char RucksackReorganization::commonType(std::string const& line)
{
   for (size_t i = 0; i < line.length() / 2; ++i)
   {
      for (size_t j = line.length() / 2; j < line.length(); ++j)
      {
         if (line[i] == line[j])
         {
            return line[i];
         }
      }
   }
   return 0;
}

char RucksackReorganization::commonGroup(std::string const& line1, std::string const& line2, std::string const& line3)
{
   for (auto const& c1 : line1)
   {
      for (auto const& c2 : line2)
      {
         if (c1 == c2)
         {
            for (auto const& c3 : line3)
            {
               if (c2 == c3)
               {
                  return c3;
               }
            }
         }
      }
   }
   return 0;
}
