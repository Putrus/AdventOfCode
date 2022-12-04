#include "../inc/Puzzles.h"
#include "../inc/EmptyPuzzle.h"

Puzzles::Puzzles(std::vector<PuzzleName> const& puzzles_names)
{
   puzzles = std::make_shared<EmptyPuzzle>();
   for (auto const& puzzle_name : puzzles_names)
   {
      switch (puzzle_name)
      {

      }
   }
}

void Puzzles::calcAndPrintAnswers()
{
   puzzles->calcAndPrintAnswers();
}
