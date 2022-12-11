#include "../inc/CathodeRayTube.h"

#include <fstream>
#include <iostream>

CathodeRayTube::CathodeRayTube(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void CathodeRayTube::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(10, "Cathode-Ray Tube");
   puzzle->calcAndPrintAnswers();
}

void CathodeRayTube::loadInput(const char* input_path)
{
   std::fstream input(input_path);
   std::string instruction_name;
   while (input >> instruction_name)
   {
      Instruction instruction;
      instruction.name = instruction_name;
      if (instruction_name != "noop")
      {
         input >> instruction.value;
      }
      instructions.push_back(instruction);
   }
   input.close();
}

void CathodeRayTube::calcAndPrintAnswerToPart1()
{
   int cycle = 0;
   int signal_strength_sum = 0;
   int reg = 1;
   for (Instruction const& instruction : instructions)
   {
      if (instruction.name == "addx")
      {
         for (int i = 0; i < 2; ++i)
         {
            ++cycle;
            if (checkCycle(cycle))
            {
               signal_strength_sum += reg * cycle;
            }
         }
         reg += instruction.value;
      }
      else
      {
         ++cycle;
         if (checkCycle(cycle))
         {
            signal_strength_sum += reg * cycle;
         }
      }
   }
   std::cout << signal_strength_sum << std::endl;
}

void CathodeRayTube::calcAndPrintAnswerToPart2()
{
   std::vector<std::string> grid;
   for (int i = 0; i < 6; ++i)
   {
      grid.push_back(std::string(40, '.'));
   }

   int cycle = 0;
   int row = 0;
   int sprite_position = 0;
   for (Instruction const& instruction : instructions)
   {
      if (instruction.name == "addx")
      {
         for (int i = 0; i < 2; ++i)
         {
            if (cycle >= sprite_position && cycle <= sprite_position + 2)
            {
               grid[row][cycle] = '#';
            }
            ++cycle;
            if (cycle >= 40)
            {
               ++row;
               cycle %= 40;
            }
         }
         sprite_position += instruction.value;
      }
      else
      {
         if (cycle >= sprite_position && cycle <= sprite_position + 2)
         {
            grid[row][cycle] = '#';
         }
         ++cycle;
         if (cycle >= 40)
         {
            ++row;
            cycle %= 40;
         }
      }
   }
   std::cout << std::endl;
   for (auto const& row : grid)
   {
      std::cout << row << std::endl;
   }
}

bool CathodeRayTube::checkCycle(int cycle)
{
   if (cycle == 20 || cycle == 60 ||
      cycle == 100 || cycle == 140 ||
      cycle == 180 || cycle == 220)
   {
      return true;
   }
   return false;
}
