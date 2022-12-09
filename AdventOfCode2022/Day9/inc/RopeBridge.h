#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>

struct MoveRB
{
   char direction;
   int steps;
};

struct Position
{
   int x;
   int y;

   friend bool operator==(Position const& lhs, Position const& rhs)
   {
      return lhs.x == rhs.x && lhs.y == rhs.y;
   }

   friend bool operator<(Position const& lhs, Position const& rhs)
   {
      return lhs.x < rhs.x;
   }
};



class RopeBridge final : public PuzzleDecorator
{
public:
   RopeBridge(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;
   void moveHead(MoveRB const& move, Position& head);
   void moveSegment(Position const& head, Position& tail);
   void printGrid(Position const& head, std::vector<Position> const& tail, int size_x, int size_y, int turn);

private:
   std::vector<MoveRB> moves;
};
