#include "../inc/TuningTrouble.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

TuningTrouble::TuningTrouble(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void TuningTrouble::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(6, "Tuning Trouble");
   puzzle->calcAndPrintAnswers();
}

void TuningTrouble::loadInput(const char* input_path)
{
   std::fstream input(input_path);
   input >> datastream_buffer;
   input.close();
}

void TuningTrouble::calcAndPrintAnswerToPart1()
{
   //start-of-packet marker
   for (size_t i = 0; i < datastream_buffer.length(); ++i)
   {
      std::string four = datastream_buffer.substr(i, 4);
      bool marker_found = true;
      for (size_t j = 0; j < four.length(); ++j)
      {
         for (size_t k = j + 1; k < four.length(); ++k)
         {
            if (four[j] == four[k])
            {
               marker_found = false;
            }
         }
      }
      if (marker_found)
      {
         std::cout << i + 4 << std::endl;
         return;
      }
   }
}

void TuningTrouble::calcAndPrintAnswerToPart2()
{
   //start-of-message marker
   for (size_t i = 0; i < datastream_buffer.length(); ++i)
   {
      std::string four = datastream_buffer.substr(i, 14);
      bool marker_found = true;
      for (size_t j = 0; j < four.length(); ++j)
      {
         for (size_t k = j + 1; k < four.length(); ++k)
         {
            if (four[j] == four[k])
            {
               marker_found = false;
            }
         }
      }
      if (marker_found)
      {
         std::cout << i + 14 << std::endl;
         return;
      }
   }
}
