#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>
#include <deque>
#include <istream>

struct Move
{
   size_t quantity;
   size_t from;
   size_t to;

   friend std::istream& operator>>(std::istream& is, Move& move)
   {
      std::string text;
      is >> text >> move.quantity >> text >> move.from >> text >> move.to;
      return is;
   };
};

class SupplyStacks final : public PuzzleDecorator
{
public:
   SupplyStacks(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;

private:
   std::vector<std::deque<char>> stacks;
   std::vector<Move> moves;
};