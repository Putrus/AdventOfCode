#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>
#include <string>

class RucksackReorganization final : public PuzzleDecorator
{
public:
   RucksackReorganization(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;
   char commonType(std::string const& line);
   char commonGroup(std::string const& line1, std::string const& line2, std::string const& line3);

private:
   std::vector<std::string> rucksacks;
};