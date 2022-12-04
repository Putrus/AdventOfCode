#pragma once

#include "../inc/PuzzleComponent.h"

#include <vector>
#include <memory>

enum class PuzzleName {
   CalorieCounting = 1,
   RockPaperScissors = 2,
   RucksackReorganization = 3,
   CampCleanup = 4
};

class Puzzles
{
public:
   Puzzles(std::vector<PuzzleName> const& puzzles_names);

private:
   std::shared_ptr<PuzzleComponent> puzzles;
   void calcAndPrintAnswers();
};