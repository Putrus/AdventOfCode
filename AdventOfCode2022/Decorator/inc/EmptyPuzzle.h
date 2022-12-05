#pragma once

#include "PuzzleComponent.h"

class EmptyPuzzle final : public PuzzleComponent
{
public:
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;
};