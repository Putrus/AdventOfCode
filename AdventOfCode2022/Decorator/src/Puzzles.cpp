#include "../inc/Puzzles.h"
#include "../inc/EmptyPuzzle.h"

#include "../../Day1/inc/CalorieCounting.h"
#include "../../Day2/inc/RockPaperScissors.h"
#include "../../Day3/inc/RucksackReorganization.h"
//day4
#include "../../Day5/inc/SupplyStacks.h"
#include "../../Day6/inc/TuningTrouble.h"
#include "../../Day7/inc/NoSpaceLeftOnDevice.h"
#include "../../Day8/inc/TreetopTreeHouse.h"
#include "../../Day9/inc/RopeBridge.h"
#include "../../Day10/inc/CathodeRayTube.h"
#include "../../Day11/inc/MonkeyInTheMiddle.h"

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
      case PuzzleName::RucksackReorganization:
         puzzles = std::make_shared<RucksackReorganization>(puzzles);
         break;
      case PuzzleName::SupplyStacks:
         puzzles = std::make_shared<SupplyStacks>(puzzles);
         break;
      case PuzzleName::TuningTrouble:
         puzzles = std::make_shared<TuningTrouble>(puzzles);
         break;
      case PuzzleName::NoSpaceLeftOnDevice:
         puzzles = std::make_shared<NoSpaceLeftOnDevice>(puzzles);
         break;
      case PuzzleName::TreetopTreeHouse:
         puzzles = std::make_shared<TreetopTreeHouse>(puzzles);
         break;
      case PuzzleName::RopeBridge:
         puzzles = std::make_shared<RopeBridge>(puzzles);
         break;
      case PuzzleName::CathodeRayTube:
         puzzles = std::make_shared<CathodeRayTube>(puzzles);
         break;
      case PuzzleName::MonkeyInTheMiddle:
         puzzles = std::make_shared<MonkeyInTheMiddle>(puzzles);
         break;
      }
   }
}

void Puzzles::calcAndPrintAnswers()
{
   puzzles->calcAndPrintAnswers();
}
