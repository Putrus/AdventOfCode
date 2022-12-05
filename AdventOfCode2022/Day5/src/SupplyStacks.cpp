#include "../inc/SupplyStacks.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

SupplyStacks::SupplyStacks(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void SupplyStacks::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(5, "Supply Stacks");
   puzzle->calcAndPrintAnswers();
}

void SupplyStacks::loadInput(const char* input_path)
{
   stacks.clear();
   stacks.shrink_to_fit();

   std::fstream input(input_path);
   std::string line;
   bool load_stack = true;
   while (std::getline(input, line))
   {
      if (load_stack)
      {
         if (line.empty())
         {
            load_stack = false;
            continue;
         }
         for (size_t i = 2; i < line.length(); i += 4)
         {
            if (line[i] == ']')
            {
               size_t stack_index = (i - 2) / 4;
               while (stack_index + 1 > stacks.size())
               {
                  stacks.push_back({});
               }
               stacks[stack_index].push_back(line[i - 1]);
            }
         } 
      }
      else
      {
         std::stringstream ss(line);
         Move move;
         ss >> move;
         moves.push_back(move);
      }
   }
}

void SupplyStacks::calcAndPrintAnswerToPart1()
{
   auto stacks_copy = stacks;
   for (auto const& move : moves)
   {
      for (size_t i = 0; i < move.quantity; ++i)
      {
         stacks_copy[move.to - 1].push_front(stacks_copy[move.from - 1].front());
         stacks_copy[move.from - 1].pop_front();
      }
   }
   for (auto const& stack : stacks_copy)
   {
      std::cout << stack.front();
   }
   std::cout << std::endl;
}

void SupplyStacks::calcAndPrintAnswerToPart2()
{
   auto stacks_copy = stacks;
   for (auto const& move : moves)
   {
      std::deque<char> tmp_stack;
      for (size_t i = 0; i < move.quantity; ++i)
      {   
         tmp_stack.push_front(stacks_copy[move.from - 1].front());
         stacks_copy[move.from - 1].pop_front();
      }
      for (auto const& crate : tmp_stack)
      {
         stacks_copy[move.to - 1].push_front(crate);
      }
   }
   for (auto const& stack : stacks_copy)
   {
      std::cout << stack.front();
   }
   std::cout << std::endl;
}
