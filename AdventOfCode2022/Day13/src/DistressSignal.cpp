#include "../inc/DistressSignal.h"

#include <fstream>
#include <iostream>

DistressSignal::DistressSignal(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void DistressSignal::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(13, "Distress Signal");
   puzzle->calcAndPrintAnswers();
}

void DistressSignal::loadInput(const char* input_path)
{
   std::ifstream input(input_path);

   input.close();
}

void DistressSignal::calcAndPrintAnswerToPart1()
{

}

void DistressSignal::calcAndPrintAnswerToPart2()
{

}