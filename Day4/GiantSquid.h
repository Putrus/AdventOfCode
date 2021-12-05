#pragma once

#include <vector>

class Board {
public:
   std::vector<std::vector<int>> board;
   Board();
   Board(std::vector<std::vector<int>> b);
   void insertRow(std::vector<int> row);
   std::vector<int> getUnmarkedWin(std::vector<int> numbers);
};



class GiantSquid {
private:
   std::vector<int> numbers;
   std::vector<Board> boards;

public:
   void loadInput(const char* filename);
   int getResultPart1();
   int getResultPart2();
};