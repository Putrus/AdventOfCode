#include "Decorator/inc/Puzzles.h"

int main()
{  
   Puzzles puzzles({ /*PuzzleName::CalorieCounting,
      PuzzleName::RockPaperScissors,
      PuzzleName::SupplyStacks,
      PuzzleName::TuningTrouble,*/
      PuzzleName::NoSpaceLeftOnDevice,
      PuzzleName::TreetopTreeHouse });
   puzzles.calcAndPrintAnswers();
   return 0;
}