#include "../inc/PuzzleDecorator.h"

#include <iostream>
#include <string>

PuzzleDecorator::PuzzleDecorator(std::shared_ptr<PuzzleComponent> puzzle) : puzzle(puzzle)
{}

void PuzzleDecorator::calcAndPrintAnswers()
{
   puzzle->calcAndPrintAnswers();
}

void PuzzleDecorator::calcAndPrintAnswersTemplate(unsigned int day, const char* puzzle_name)
{
   std::cout << "--- Day " << day << ": " << puzzle_name << " ---" << std::endl;
   loadInput(("Day" + std::to_string(day) + "/res/input.txt").c_str());

   std::cout << "Part 1: ";
   calcAndPrintAnswerToPart1();
   std::cout << std::endl;

   std::cout << "Part 2: ";
   calcAndPrintAnswerToPart2();
   std::cout << std::endl;
}
