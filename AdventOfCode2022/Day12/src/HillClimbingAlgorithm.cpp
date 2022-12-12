#include "../inc/HillClimbingAlgorithm.h"

#include <fstream>
#include <iostream>
#include <list>

HillClimbingAlgorithm::HillClimbingAlgorithm(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void HillClimbingAlgorithm::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(12, "Hill Climbing Algorithm");
   puzzle->calcAndPrintAnswers();
}

void HillClimbingAlgorithm::loadInput(const char* input_path)
{
   std::ifstream input(input_path);
   std::string line;
   while (std::getline(input, line))
   {
      heightmap.push_back(line);
      for (size_t i = 0; i < line.length(); ++i)
      {
         if (line[i] == 'S')
         {
            start_position = { (int)i, (int)heightmap.size() - 1 };
            heightmap[start_position.y][start_position.x] = 'a';
         }
         else if (line[i] == 'E')
         {
            goal_position = { (int)i, (int)heightmap.size() - 1 };
            heightmap[goal_position.y][goal_position.x] = 'z';
         }
      }
   }
   input.close();
}

void HillClimbingAlgorithm::calcAndPrintAnswerToPart1()
{
   std::cout << bfs(start_position) << std::endl;
}

void HillClimbingAlgorithm::calcAndPrintAnswerToPart2()
{
   int best = 99999;
   for (size_t i = 0; i < heightmap.size(); ++i)
   {
      for (size_t j = 0; j < heightmap[i].length(); ++j)
      {
         if (heightmap[i][j] == 'a')
         {
            int bfs_result = bfs({ (int)j, (int)i });
            if (bfs_result < best)
            {
               best = bfs_result;
            }
         }
      }
   }
   std::cout << best << std::endl;
}

int HillClimbingAlgorithm::bfs(HCAPosition start_height_position)
{
   std::vector<std::vector<int>> steps;
   for (size_t i = 0; i < heightmap.size(); ++i)
   {
      steps.emplace_back(heightmap[i].size(), 99999);
   }

   std::list<HCAPosition> list;
   steps[start_height_position.y][start_height_position.x] = 0;
   list.push_back(start_height_position);
   HCAPosition position = start_height_position;
   while (!list.empty())
   {
      position = list.front();
      list.pop_front();

      if (position.x >= 1)
      {
         //left
         if (heightmap[position.y][position.x - 1] <= heightmap[position.y][position.x] + 1
            && steps[position.y][position.x] < steps[position.y][position.x - 1] - 1)
         {
            steps[position.y][position.x - 1] = steps[position.y][position.x] + 1;
            list.push_back({ position.x - 1, position.y });
         }
      }
      if (position.x < (int)heightmap[0].length() - 1)
      {
         //right
         if (heightmap[position.y][position.x + 1] <= heightmap[position.y][position.x] + 1
            && steps[position.y][position.x] < steps[position.y][position.x + 1] - 1)
         {
            steps[position.y][position.x + 1] = steps[position.y][position.x] + 1;
            list.push_back({ position.x + 1, position.y });
         }
      }
      if (position.y >= 1)
      {
         //up
         if (heightmap[position.y - 1][position.x] <= heightmap[position.y][position.x] + 1
            && steps[position.y][position.x] < steps[position.y - 1][position.x] - 1)
         {
            steps[position.y - 1][position.x] = steps[position.y][position.x] + 1;
            list.push_back({ position.x, position.y - 1 });
         }
      }
      if (position.y < (int)heightmap.size() - 1)
      {
         //down
         if (heightmap[position.y + 1][position.x] <= heightmap[position.y][position.x] + 1
            && steps[position.y][position.x] < steps[position.y + 1][position.x] - 1)
         {
            steps[position.y + 1][position.x] = steps[position.y][position.x] + 1;
            list.push_back({ position.x, position.y + 1 });
         }
      }
   }
   return steps[goal_position.y][goal_position.x];
}
