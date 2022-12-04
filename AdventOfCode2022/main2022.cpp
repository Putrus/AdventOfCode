#include "Decorator/inc/Puzzles.h"

int main()
{  
   Puzzles puzzles({ PuzzleName::CalorieCounting });
   puzzles.calcAndPrintAnswers();
   return 0;
}