#pragma once

class PuzzleComponent
{
public:
   virtual void calcAndPrintAnswers() = 0;

protected:
   virtual void loadInput(const char* input_path) = 0;
   virtual void calcAndPrintAnswerToPart1() = 0;
   virtual void calcAndPrintAnswerToPart2() = 0;
};