#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>

class Board {
public:
   std::vector<std::vector<int>> board;
   Board();
   Board(std::vector<std::vector<int>> b);
   void insertRow(std::vector<int> row);
   std::vector<int> getUnmarkedWin(std::vector<int> numbers);
};

class GiantSquid : public DecoratorTask{
private:
   std::vector<int> numbers;
   std::vector<Board> boards;

public:
   GiantSquid(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   int getResultPart1() override;
   int getResultPart2() override;
};