#include "Decorator/inc/Puzzles.h"

int main()
{  
   Puzzles puzzles({ PuzzleName::CalorieCounting,
      PuzzleName::SupplyStacks});
   puzzles.calcAndPrintAnswers();
   return 0;
}