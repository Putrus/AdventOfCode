#include "../inc/RockPaperScissors.h"

#include <fstream>
#include <iostream>

RockPaperScissors::RockPaperScissors(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void RockPaperScissors::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(2, "Rock Paper Scissors");
   puzzle->calcAndPrintAnswers();
}

void RockPaperScissors::loadInput(const char* input_path)
{
   std::fstream input(input_path);
   char opponent;
   char you;
   while (input >> opponent >> you)
   {
      predictions.push_back({ opponent, you });
   }
   input.close();
}

void RockPaperScissors::calcAndPrintAnswerToPart1()
{
   int total_score = 0;
   for (auto const& prediction : predictions)
   {
      int score = prediction.second - 'W';
      if (prediction.first - 'A' == prediction.second - 'X')
      {
         score += 3;
      }

      if ((prediction.first == 'A' && prediction.second == 'Y') ||
         (prediction.first == 'B' && prediction.second == 'Z') ||
         (prediction.first == 'C' && prediction.second == 'X'))
      {
         score += 6;
      }
      total_score += score;
   }
   std::cout << total_score << std::endl;
}

void RockPaperScissors::calcAndPrintAnswerToPart2()
{
   int total_score = 0;
   for (auto const& prediction : predictions)
   {
      int score = 0;
      if (prediction.second == 'X')
      {
         score = prediction.first - 'A';
         if (score == 0)
         {
            score = 3;
         }
      }
      else if (prediction.second == 'Y')
      {
         score = 3;
         score += prediction.first - 'A' + 1;
      }
      else
      {
         score = 6;
         score += (prediction.first - 'A' + 1) % 3 + 1;
      }
      total_score += score;
   }
   std::cout << total_score << std::endl;
}
