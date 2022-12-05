#include "../inc/Puzzles.h"
#include "../inc/EmptyPuzzle.h"

#include "../../Day1/inc/CalorieCounting.h"
#include "../../Day2/inc/RockPaperScissors.h"
//day3
//day4
#include "../../Day5/inc/SupplyStacks.h"

Puzzles::Puzzles(std::vector<PuzzleName> const& puzzles_names)
{
   puzzles = std::make_shared<EmptyPuzzle>();
   for (auto const& puzzle_name : puzzles_names)
   {
      switch (puzzle_name)
      {
      case PuzzleName::CalorieCounting:
         puzzles = std::make_shared<CalorieCounting>(puzzles);
         break;
      case PuzzleName::RockPaperScissors:
         puzzles = std::make_shared<RockPaperScissors>(puzzles);
         break;
      case PuzzleName::SupplyStacks:
         puzzles = std::make_shared<SupplyStacks>(puzzles);
         break;
      }
   }
}

void Puzzles::calcAndPrintAnswers()
{
   puzzles->calcAndPrintAnswers();
}
