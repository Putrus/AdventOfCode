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
         if (first_argument == "old" && second_argument == "old")
         {
            monkey.operation = [](int item) -> int
            {
               return item + item;
            };
         }
         else if (first_argument == "old")
         {
            monkey.operation = [second_argument](int item) -> int
            {
               return item + stoi(second_argument);
            };
         }
         else
         {
            monkey.operation = [first_argument, second_argument](int item) -> int
            {
               return stoi(first_argument) + stoi(second_argument);
            };
         }
      }
      else
      {
         if (first_argument == "old" && second_argument == "old")
         {
            monkey.operation = [](int item) -> int
            {
               return item * item;
            };
         }
         else if (first_argument == "old")
         {
            monkey.operation = [second_argument](int item) -> int
            {
               return item * stoi(second_argument);
            };
         }
         else
         {
            monkey.operation = [first_argument, second_argument](int item) -> int
            {
               return stoi(first_argument) * stoi(second_argument);
            };
         }
      }

      //test
      std::string text1, text2, text3, text4, text5;
      input >> text1 >> text2 >> text3 >> monkey.divider;
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
   for (int round = 0; round < 20; ++round)
   {
      for (Monkey& monkey : monkeys)
      {
         auto it = monkey.items.begin();
         while (it != monkey.items.end())
         {
            int new_item = monkey.operation(*it) / 3;
            it = monkey.items.erase(it);
            if (new_item % monkey.divider == 0)
            {
               monkeys[monkey.true_monkey_id].items.push_back(new_item);
            }
            else
            {
               monkeys[monkey.false_monkey_id].items.push_back(new_item);
            }
            ++monkey.inspected_items;
         }
      }
   }
   
   std::vector<int> bests(2, 0);
   for (auto const& monkey : monkeys)
   {
      if (monkey.inspected_items > bests[0])
      {
         bests[0] = monkey.inspected_items;
         std::sort(bests.begin(), bests.end());
      }
   }
   std::cout << bests[0] * bests[1] << std::endl;
}

void MonkeyInTheMiddle::calcAndPrintAnswerToPart2()
{

}
