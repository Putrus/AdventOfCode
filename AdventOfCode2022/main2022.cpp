#include "Decorator/inc/Puzzles.h"

int main()
{  
   Puzzles puzzles({ /*PuzzleName::CalorieCounting,
      PuzzleName::RockPaperScissors,
      PuzzleName::SupplyStacks,
      PuzzleName::TuningTrouble,
      PuzzleName::NoSpaceLeftOnDevice,
      PuzzleName::TreetopTreeHouse,
      PuzzleName::RopeBridge,
      PuzzleName::CathodeRayTube,*/
      PuzzleName::MonkeyInTheMiddle});
   puzzles.calcAndPrintAnswers();
   return 0;
}