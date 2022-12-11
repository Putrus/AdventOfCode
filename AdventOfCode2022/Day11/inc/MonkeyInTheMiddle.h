#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>
#include <functional>

struct Monkey
{
   std::vector<long long> items;
   std::function<long long(long long item)> operation;
   long long divider;
   int true_monkey_id;
   int false_monkey_id;
   long long inspected_items = 0;
   bool mul = false;
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
   long long calcResult(std::vector<Monkey> monkeys_copy, int rounds, std::function<long long(long long item, bool mul)> lambda = [](long long item, bool mul) {return item / 3; });

private:
   std::vector<Monkey> monkeys;
   //lowest common denominator
   long long lcd = 1;
};
