#include "../inc/MonkeyInTheMiddle.h"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

MonkeyInTheMiddle::MonkeyInTheMiddle(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void MonkeyInTheMiddle::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(11, "Monkey in the Middle");
   puzzle->calcAndPrintAnswers();
}

void MonkeyInTheMiddle::loadInput(const char* input_path)
{
   std::fstream input(input_path);
   std::string monkey_text;
   int monkey_id;
   while (input >> monkey_text >> monkey_id)
   {
      Monkey monkey;

      //starting items
      std::string colon_text, starting_text, items_text;
      input >> colon_text >> starting_text >> items_text;
      std::string item;
      while (input >> item)
      {
         if (item == "Operation:")
         {
            break;
         }
         else
         {
            monkey.items.push_back(stoi(item));
         }
      }

      //operation
      std::string new_text, equal_text;
      input >> new_text >> equal_text;
      std::string first_argument;
      char operation;
      std::string second_argument;
      input >> first_argument >> operation >> second_argument;
      if (operation == '+')
      {
         monkey.mul = false;
         if (first_argument == "old" && second_argument == "old")
         {
            monkey.operation = [](long long item) -> long long
            {
               return item + item;
            };
         }
         else if (first_argument == "old")
         {
            long long argument = stoi(second_argument);
            monkey.operation = [argument](long long item) -> long long
            {
               return item + argument;
            };
         }
         else
         {
            long long argument1 = stoi(first_argument);
            long long argument2 = stoi(second_argument);
            monkey.operation = [argument1, argument2](long long item) -> long long
            {
               return argument1 + argument2;
            };
         }
      }
      else
      {
         monkey.mul = true;
         if (first_argument == "old" && second_argument == "old")
         {
            monkey.operation = [](long long item) -> long long
            {
               return item * item;
            };
         }
         else if (first_argument == "old")
         {
            long long argument = stoi(second_argument);
            monkey.operation = [argument](long long item) -> long long
            {
               return item * argument;
            };
         }
         else
         {
            long long argument1 = stoi(first_argument);
            long long argument2 = stoi(second_argument);
            monkey.operation = [argument1, argument2](long long item) -> long long
            {
               return argument1 * argument2;
            };
         }
      }

      //test
      std::string text1, text2, text3, text4, text5;
      input >> text1 >> text2 >> text3 >> monkey.divider;
      long long denominator = std::max(lcd, monkey.divider);
      while (true)
      {
         if (denominator % lcd == 0 && denominator % monkey.divider == 0)
         {
            lcd = denominator;
            break;
         }
         ++denominator;
      }
      //if true
      input >> text1 >> text2 >> text3 >> text4 >> text5 >> monkey.true_monkey_id;
      //if false
      input >> text1 >> text2 >> text3 >> text4 >> text5 >> monkey.false_monkey_id;
      monkeys.push_back(monkey);
   }
   input.close();
}

void MonkeyInTheMiddle::calcAndPrintAnswerToPart1()
{
   std::cout << calcResult(monkeys, 20);
}

void MonkeyInTheMiddle::calcAndPrintAnswerToPart2()
{
   std::cout << calcResult(monkeys, 10000, [this](long long item, bool mul) {
      return mul ? item : item % lcd;
      });
}

long long MonkeyInTheMiddle::calcResult(std::vector<Monkey> monkeys_copy, int rounds, std::function<long long(long long item, bool mul)> lambda)
{
   for (int round = 0; round < rounds; ++round)
   {
      for (Monkey& monkey : monkeys_copy)
      {
         auto it = monkey.items.begin();
         while (it != monkey.items.end())
         {
            long long new_item = lambda(monkey.operation(*it), monkey.mul);
            it = monkey.items.erase(it);
            if (new_item % monkey.divider == 0)
            {
               monkeys_copy[monkey.true_monkey_id].items.push_back(new_item);
            }
            else
            {
               monkeys_copy[monkey.false_monkey_id].items.push_back(new_item);
            }
            ++monkey.inspected_items;
         }
      }
   }

   std::vector<long long> bests(2, 0);
   for (auto const& monkey : monkeys_copy)
   {
      if (monkey.inspected_items > bests[0])
      {
         bests[0] = monkey.inspected_items;
         std::sort(bests.begin(), bests.end());
      }
   }
   return bests[0] * bests[1];
}
