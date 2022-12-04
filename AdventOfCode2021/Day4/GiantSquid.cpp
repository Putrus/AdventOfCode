#include "GiantSquid.h"

#include "../Utilities/Utilities.h"

#include <fstream>
#include <iostream>

Board::Board() {
   for (int i = 0; i < 5; ++i) {
      std::vector<int> row(5, 0);
      board.push_back(row);
   }
}
Board::Board(std::vector<std::vector<int>> b) {
   board = b;
}

void Board::insertRow(std::vector<int> row) {
   board.push_back(row);
}

std::vector<int> Board::getUnmarkedWin(std::vector<int> numbers) {
   if (numbers.size() < 5) {
      return {};
   }

   std::vector<int> unmarkedNumbers;

   std::vector<std::vector<bool>> bingo = { {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,0,0} };

   for (size_t i = 0; i < board.size(); ++i) {
      for (auto const& number : numbers) {
         auto it = std::find(board[i].begin(), board[i].end(), number);
         int index = std::distance(board[i].begin(), it);
         if (it != board[i].end()) {
            bingo[i][index] = 1;
         }
      }
   }

   for (size_t i = 0; i < bingo.size(); ++i) {
      int counterR = 0;
      int counterC = 0;
      for (size_t j = 0; j < bingo.size(); ++j) {
         if (bingo[i][j] == 1) {
            ++counterR;
         }
         if (bingo[j][i] == 1) {
            ++counterC;
         }
      }
      if (counterR == 5 || counterC == 5) {
         for (size_t x = 0; x < board.size(); ++x) {
            for (size_t y = 0; y < board.size(); ++y) {
               if (bingo[x][y] == 0) {
                  unmarkedNumbers.push_back(board[x][y]);
               }
            }
         }
         return unmarkedNumbers;
      }
   }
   return {};
}

GiantSquid::GiantSquid(ComponentTask* task) : DecoratorTask(task) {}

void GiantSquid::printResults() {
   printResultsArgs("Day4/Input.txt", "--- Day 4: Giant Squid ---");
   task->printResults();
}

void GiantSquid::loadInput(const char* filename) {
   std::ifstream file(filename);
   std::string numString;
   file >> numString;
   numbers.clear();
   numbers = uti::split(numString);
   
   while (!file.eof()) {
      Board b;
      for (int i = 0; i < 5; ++i) {
         for (int j = 0; j < 5; ++j) {
            int n;
            file >> n;
            b.board[i][j] = n;
         }
      }
      boards.push_back(b);
   }
   
   boards.erase(boards.end() - 1);

   file.close();
}

void GiantSquid::printResultPart1() {
   int sum = 0;
   int winNumber = 0;
   for (size_t i = 0; i < numbers.size(); ++i) {
      std::vector<int> numbersNow(numbers.begin(), numbers.begin() + i);
         for(size_t bI = 0; bI < boards.size(); ++bI){
            std::vector<int> unmarked = boards[bI].getUnmarkedWin(numbersNow);
            if (!unmarked.empty()) {
               for (auto const& number : unmarked) {
                  sum += number;
               }
               winNumber = numbersNow[numbersNow.size() - 1];
               std::cout << sum * winNumber;
               return;
            }
         }
   }
   std::cout << "0";
}

void GiantSquid::printResultPart2() {
   int sum = 0;
   int winNumber = 0;
   int counter = 0;
   std::vector<bool> winBoards(boards.size(), 0);
   for (size_t i = 0; i < numbers.size(); ++i) {
      std::vector<int> numbersNow(numbers.begin(), numbers.begin() + i);
      for (size_t bI = 0; bI < boards.size(); ++bI) {
         std::vector<int> unmarked = boards[bI].getUnmarkedWin(numbersNow);
         if (!unmarked.empty() && winBoards[bI] == 0) {
            winBoards[bI] = 1;
            ++counter;
            if (counter == boards.size()) {
               for (auto const& number : unmarked) {
                  sum += number;
               }
               winNumber = numbersNow[numbersNow.size() - 1];
               std::cout << sum * winNumber;
               return;
            }
         }
      }
   }
   std::cout << "0";
}
