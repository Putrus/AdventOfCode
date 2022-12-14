#include "../inc/RegolithReservoir.h"

#include <fstream>
#include <iostream>

RegolithReservoir::RegolithReservoir(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void RegolithReservoir::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(14, "Regolith Reservoir");
   puzzle->calcAndPrintAnswers();
}

void RegolithReservoir::loadInput(const char* input_path)
{
   std::ifstream input(input_path);

   input.close();
}

void RegolithReservoir::calcAndPrintAnswerToPart1()
{

}

void RegolithReservoir::calcAndPrintAnswerToPart2()
{

}