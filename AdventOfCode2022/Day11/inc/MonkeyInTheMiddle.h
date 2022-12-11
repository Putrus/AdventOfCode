#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>
#include <functional>

struct Monkey
{
   std::vector<int> items;
   std::function<int(int item)> operation;
   int divider;
   int true_monkey_id;
   int false_monkey_id;
   int inspected_items = 0;
};

class MonkeyInTheMiddle final : public PuzzleDecorator
{
public:
   MonkeyInTheMiddle(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;

private:
   std::vector<Monkey> monkeys;
};
