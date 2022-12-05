#pragma once

#include "PuzzleComponent.h"

#include <memory>

class PuzzleDecorator : public PuzzleComponent
{
public:
   PuzzleDecorator(std::shared_ptr<PuzzleComponent> puzzle);
   virtual void calcAndPrintAnswers() override;

protected:
   virtual void loadInput(const char* input_path) = 0;
   virtual void calcAndPrintAnswerToPart1() = 0;
   virtual void calcAndPrintAnswerToPart2() = 0;
   void calcAndPrintAnswersTemplate(unsigned int day, const char* puzzle_name);

protected:
   std::shared_ptr<PuzzleComponent> puzzle;
};