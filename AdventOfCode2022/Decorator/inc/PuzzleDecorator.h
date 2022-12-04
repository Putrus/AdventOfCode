#pragma once

#include "PuzzleComponent.h"

#include <memory>

class PuzzleDecorator : public PuzzleComponent
{
public:
   PuzzleDecorator(std::shared_ptr<PuzzleComponent> puzzle);
   virtual void calcAndPrintAnswers() override;

protected:
   virtual void loadInput(const char* filename) = 0;
   virtual void calcAndPrintAnswerToPart1() = 0;
   virtual void calcAndPrintAnswerToPart2() = 0;
   void calcAndPrintAnswersTemplate(const char* input, const char* puzzle_name);

protected:
   std::shared_ptr<PuzzleComponent> puzzle;
};