#include "../inc/PuzzleDecorator.h"

#include <iostream>

void PuzzleDecorator::calcAndPrintAnswers()
{
   puzzle->calcAndPrintAnswers();
}

void PuzzleDecorator::calcAndPrintAnswers(const char* input, const char* puzzle_name)
{
   std::cout << "--- " << puzzle_name << " ---" << std::endl;
   loadInput(input);

   std::cout << "Part 1: ";
   calcAndPrintAnswerToPart1();
   std::cout << std::endl;

   std::cout << "Part 2: ";
   calcAndPrintAnswerToPart2();
   std::cout << std::endl;
}
