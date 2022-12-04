#pragma once

#include "../Decorator/DecoratorTask.h"

#include <string>
#include <vector>

struct Note {
   std::vector<std::string> patterns;
   std::vector<std::string> output;
};


class SevenSegmentSearch : public DecoratorTask {
private:
   std::vector<Note> notes;

public:
   SevenSegmentSearch(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;

   std::string displayDecode(Note note);

   int outputToNumber(const std::string& display, const Note& note);
};