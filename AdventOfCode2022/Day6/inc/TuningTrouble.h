#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <string>

class TuningTrouble final : public PuzzleDecorator
{
public:
   TuningTrouble(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;

private:
   std::string datastream_buffer;
};