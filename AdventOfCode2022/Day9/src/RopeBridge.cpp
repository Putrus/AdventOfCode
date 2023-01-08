#include "../inc/RopeBridge.h"

#include <fstream>
#include <iostream>
#include <map>

RopeBridge::RopeBridge(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void RopeBridge::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(9, "Rope Bridge");
   puzzle->calcAndPrintAnswers();
}

void RopeBridge::loadInput(const char* input_path)
{
   std::fstream input(input_path);
   MoveRB move;
   while (input >> move.direction >> move.steps)
   {
      moves.push_back(move);
   }
   input.close();
}

void RopeBridge::calcAndPrintAnswerToPart1()
{
   Position tail = { 0, 0 };
   Position head = { 0, 0 };
   std::vector<Position> positions;
   positions.push_back(tail);
   for (auto const& move : moves)
   {
      for (int i = 0; i < move.steps; ++i)
      {
         moveHead(move, head);
         moveSegment(head, tail);

         if (std::find(positions.begin(), positions.end(), tail) == positions.end())
         {
            positions.push_back(tail);
         }
      }
   }
   std::cout << positions.size() << std::endl;
}

void RopeBridge::calcAndPrintAnswerToPart2()
{
   std::vector<Position> tail(9, { 0, 0 });
   Position head = { 0, 0 };
   std::vector<Position> positions;
   Position start_position = { 0, 0 };
   positions.push_back({ 0, 0 });
   //int turn = 0;
   for (auto const& move : moves)
   {
      for (int i = 0; i < move.steps; ++i)
      {
         moveHead(move, head);
         moveSegment(head, tail[0]);

         for (size_t j = 1; j < tail.size(); ++j)
         {
            moveSegment(tail[j - 1], tail[j]);
         }
         if (std::find(positions.begin(), positions.end(), tail[8]) == positions.end())
         {
            positions.push_back(tail[8]);
         }
         //printGrid(head, tail, 20, 20, turn);
         //++turn;
      }
   }

   std::cout << positions.size() << std::endl;
}

void RopeBridge::moveSegment(Position const& head, Position& tail)
{
   //move tail and add position to existing positions vector
   if (head.x - tail.x == 2)
   {
      if (tail.y == head.y)
      {
         ++tail.x;
      }
      else if (tail.y > head.y)
      {
         ++tail.x;
         --tail.y;
      }
      else
      {
         ++tail.x;
         ++tail.y;
      }
   }
   if (tail.x - head.x == 2)
   {
      if (tail.y == head.y)
      {
         --tail.x;
      }
      else if (tail.y > head.y)
      {
         --tail.x;
         --tail.y;
      }
      else
      {
         --tail.x;
         ++tail.y;
      }
   }
   if (head.y - tail.y == 2)
   {
      if (tail.x == head.x)
      {
         ++tail.y;
      }
      else if (tail.x > head.x)
      {
         ++tail.y;
         --tail.x;
      }
      else
      {
         ++tail.y;
         ++tail.x;
      }
   }
   if (tail.y - head.y == 2)
   {
      if (tail.x == head.x)
      {
         --tail.y;
      }
      else if (tail.x > head.x)
      {
         --tail.y;
         --tail.x;
      }
      else
      {
         --tail.y;
         ++tail.x;
      }
   }
}

void RopeBridge::printGrid(Position const& head, std::vector<Position> const& tail, int size_x, int size_y, int turn)
{
   std::vector<std::vector<char>> grid;
   for (int i = 0; i < size_y; ++i)
   {
      std::vector<char> row(size_x, '.');
      grid.push_back(row);
   }
   
   for (char i = 0; i < static_cast<char>(tail.size()); ++i)
   {
      grid[grid.size() / 2 + tail[i].y][grid[0].size() / 2 + tail[i].x] = i + '1';
   }
   grid[grid.size() / 2 + head.y][grid[0].size() / 2 + head.x] = 'H';
   
   std::cout << std::endl << "Turn " << turn << std::endl;
   for (size_t i = 0; i < grid.size(); ++i)
   {
      for (size_t j = 0; j < grid[i].size(); ++j)
      {
         std::cout << grid[i][j];
      }
      std::cout << std::endl;
   }
}

void RopeBridge::moveHead(MoveRB const& move, Position& head)
{
   //move head
   if (move.direction == 'R')
   {
      ++head.x;
   }
   if (move.direction == 'L')
   {
      --head.x;
   }
   if (move.direction == 'D')
   {
      ++head.y;
   }
   if (move.direction == 'U')
   {
      --head.y;
   }
}