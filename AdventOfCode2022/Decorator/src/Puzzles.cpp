#include "../inc/Puzzles.h"
#include "../inc/EmptyPuzzle.h"

#include "../../Day1/inc/CalorieCounting.h"

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
      }
   }
}

void Puzzles::calcAndPrintAnswers()
{
   puzzles->calcAndPrintAnswers();
}
