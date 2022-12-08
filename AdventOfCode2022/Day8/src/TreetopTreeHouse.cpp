#include "../inc/TreetopTreeHouse.h"

#include <fstream>
#include <iostream>

TreetopTreeHouse::TreetopTreeHouse(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void TreetopTreeHouse::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(8, "Treetop Tree House");
   puzzle->calcAndPrintAnswers();
}

void TreetopTreeHouse::loadInput(const char* input_path)
{
   std::fstream input(input_path);
   std::string line;
   while (std::getline(input, line))
   {
      grid.push_back(line);
   }
   input.close();
}

void TreetopTreeHouse::calcAndPrintAnswerToPart1()
{
   unsigned int visible_counter = 0;
   for (size_t i = 0; i < grid.size(); ++i)
   {
      for (size_t j = 0; j < grid[i].length(); ++j)
      {
         if (checkVisibleHorizontal(i, j, 0, j) ||
            checkVisibleHorizontal(i, j, j + 1, grid[i].length()) ||
            checkVisibleVertical(i, j, 0, i) ||
            checkVisibleVertical(i, j, i + 1, grid.size()))
         {
            ++visible_counter;
         }
      }
   }
   std::cout << visible_counter << std::endl;
}

void TreetopTreeHouse::calcAndPrintAnswerToPart2()
{
   unsigned int best = 0;
   for (size_t i = 0; i < grid.size(); ++i)
   {
      for (size_t j = 0; j < grid[i].length(); ++j)
      {
         size_t scenic_score = calcScenicScore(j, i);
         if (scenic_score > best)
         {
            best = scenic_score;
         }
      }
   }
   std::cout << best << std::endl;
}

bool TreetopTreeHouse::checkVisibleHorizontal(size_t y, size_t x, size_t start, size_t end)
{
   for (size_t i = start; i < end; ++i)
   {
      if (grid[y][i] >= grid[y][x])
      {
         return false;
      }
   }
   return true;
}

bool TreetopTreeHouse::checkVisibleVertical(size_t y, size_t x, size_t start, size_t end)
{
   for (size_t i = start; i < end; ++i)
   {
      if (grid[i][x] >= grid[y][x])
      {
         return false;
      }
   }
   return true;
}

size_t TreetopTreeHouse::calcScenicScore(size_t x, size_t y)
{
   return getTreesCanSee(y, x, Direction::Left) *
      getTreesCanSee(y, x, Direction::Right) *
      getTreesCanSee(y, x, Direction::Up) *
      getTreesCanSee(y, x, Direction::Down);
}

size_t TreetopTreeHouse::getTreesCanSee(int y, int x, Direction direction)
{
   size_t trees = 0;
   switch (direction)
   {
   case Direction::Left:
      for (int i = x - 1; i >= 0; --i)
      {
         ++trees;
         if (grid[y][i] >= grid[y][x])
         {
            return trees;
         }
      }
      break;
   case Direction::Right:
      for (size_t i = x + 1; i < grid[y].length(); ++i)
      {
         ++trees;
         if (grid[y][i] >= grid[y][x])
         {
            return trees;
         }
      }
      break;
   case Direction::Up:
      for (int i = y - 1; i >= 0; --i)
      {
         ++trees;
         if (grid[i][x] >= grid[y][x])
         {
            return trees;
         }
      }
      break;
   case Direction::Down:
      for (size_t i = y + 1; i < grid.size(); ++i)
      {
         ++trees;
         if (grid[i][x] >= grid[y][x])
         {
            return trees;
         }
      }
      break;
   default:
      break;
   }
   return trees;
}