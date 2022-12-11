#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>
#include <string>

struct Instruction
{
   std::string name;
   int value = 0;
};

class CathodeRayTube final : public PuzzleDecorator
{
public:
   CathodeRayTube(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;
   bool checkCycle(int cycle);

private:
   std::vector<Instruction> instructions;
};
