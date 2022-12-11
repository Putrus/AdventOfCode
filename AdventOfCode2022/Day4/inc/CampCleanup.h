#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>

class CampCleanup final : public PuzzleDecorator
{
public:
   CampCleanup(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;

private:
   std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> pairs;
};