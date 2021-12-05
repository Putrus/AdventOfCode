#pragma once

#include <vector>
#include <string>

class Dive {
private:
   //horizontal position
   int x;
   //depth
   int y;
   //
   int aim;
   std::vector<std::pair<std::string, int>> commands;

public:
   Dive();
   void loadInput(const char* filename);
   int getResultPart1();
   int getResultPart2();
};