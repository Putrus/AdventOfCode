#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>

class CalorieCounting final : public PuzzleDecorator
{
public:
   CalorieCounting(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;

private:
   std::vector<int> sums;
};