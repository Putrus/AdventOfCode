#pragma once

#include <vector>

class SonarSweep {
private:
   std::vector<int> depths;
   std::vector<int> threes;
public:
   void loadInput(const char* filename);
   int getResultPart1();
   int getResultPart2();
private:
   void createThrees();
   int getIncreases(std::vector<int>& arr);
};
