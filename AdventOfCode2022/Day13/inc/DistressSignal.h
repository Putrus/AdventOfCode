#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>
#include <string>

class DistressSignal final : public PuzzleDecorator
{
public:
   DistressSignal(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;

private:
   std::vector<std::pair<std::string, std::string>> pairs;
};