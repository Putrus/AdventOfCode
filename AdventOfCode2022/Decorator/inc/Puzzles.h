#pragma once

#include "../inc/PuzzleComponent.h"

#include <vector>
#include <memory>

enum class PuzzleName {
   CalorieCounting = 1,
   RockPaperScissors = 2,
   RucksackReorganization = 3,
   CampCleanup = 4,
   SupplyStacks = 5,
   TuningTrouble = 6,
   NoSpaceLeftOnDevice = 7,
   TreetopTreeHouse = 8,
   RopeBridge = 9,
   CathodeRayTube = 10,
   MonkeyInTheMiddle = 11,
   HillClimbingAlgorithm = 12
};

class Puzzles
{
public:
   Puzzles(std::vector<PuzzleName> const& puzzles_names);
   void calcAndPrintAnswers();

private:
   std::shared_ptr<PuzzleComponent> puzzles;
};