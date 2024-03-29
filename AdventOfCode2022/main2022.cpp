#include "Decorator/inc/Puzzles.h"

int main()
{  
   Puzzles puzzles({/*
      PuzzleName::CalorieCounting,
      PuzzleName::RockPaperScissors,
      PuzzleName::RucksackReorganization,
      PuzzleName::CampCleanup,
      PuzzleName::SupplyStacks,
      PuzzleName::TuningTrouble,
      PuzzleName::NoSpaceLeftOnDevice,
      PuzzleName::TreetopTreeHouse,
      PuzzleName::RopeBridge,
      PuzzleName::CathodeRayTube,
      PuzzleName::MonkeyInTheMiddle,
      PuzzleName::HillClimbingAlgorithm*/
      PuzzleName::DistressSignal,
      PuzzleName::RegolithReservoir
      });
   puzzles.calcAndPrintAnswers();
   return 0;
}