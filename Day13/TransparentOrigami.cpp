#include "TransparentOrigami.h"

#include <fstream>
#include <iostream>
#include <set>

TransparentOrigami::TransparentOrigami(ComponentTask* task) : DecoratorTask(task) {
}

void TransparentOrigami::printResults() {
   printResultsArgs("Day13/Input.txt", "--- Day 13: Transparent Origami ---");
   task->printResults();
}

void TransparentOrigami::loadInput(const char* filename) {
   std::ifstream file(filename);
   if (file.fail()) {
      std::cout << "Failed to load Input file!" << std::endl;
      file.close();
      return;
   }
   paper.clear();
   std::set<std::pair<int, int>> pairs;
   int paperSizeX = 0;
   int paperSizeY = 0;
   while (!file.eof()) {
      std::string strRow;
      file >> strRow;
      if (strRow == "fold") {
         std::string al, strAction;
         file >> al >> strAction;
         int equalId = strAction.find_first_of('=');
         char actionChar = strAction.substr(0, equalId)[0];
         int actionNr = atoi(strAction.substr(equalId + 1, strAction.length() - equalId).c_str());
         instructions.push_back({ actionChar, actionNr });
      }
      if (!strRow.empty()) {
         int commaId = strRow.find_first_of(',');
         int first = atoi(strRow.substr(0, commaId).c_str());
         int second = atoi(strRow.substr(commaId + 1, strRow.length() - commaId).c_str());
         paperSizeX = std::max(first, paperSizeX);
         paperSizeY = std::max(second, paperSizeY);
         pairs.insert({ first, second });
      }
   }
   //pairs to transparent paper
   for (int i = 0; i < paperSizeY + 1; ++i) {
      std::vector<char> row(paperSizeX + 1, '.');
      paper.push_back(row);
   }
   for (auto const& pair : pairs) {
      paper[pair.second][pair.first] = '#';
   }
   file.close();
}

void TransparentOrigami::printResultPart1() {
   bool first = true;
   for (auto const& instruction : instructions) {
      if (instruction.first == 'y') {
         for (int i = instruction.second + 1; i < paper.size(); ++i) {
            for (int j = 0; j < paper[i].size(); ++j) {
               if (paper[i][j] == '#') {
                  paper[instruction.second + (instruction.second - i)][j] = '#';
               }
            }
         }
         int oldpaperSize = paper.size();
         for (int i = instruction.second; i < oldpaperSize; ++i) {
            paper.erase(paper.begin() + instruction.second);
         }
      }
      if (instruction.first == 'x') {
         for (int i = 0; i < paper.size(); ++i) {
            for (int j = instruction.second + 1; j < paper[i].size(); ++j) {
               int mirrId = instruction.second + (instruction.second - j);
               if (paper[i][j] == '#') {
                  paper[i][mirrId] = '#';
               }
            }
         }
         for (int i = 0; i < paper.size(); ++i) {
            while (paper[i].size() != instruction.second) {
               paper[i].erase(paper[i].begin() + instruction.second);
            }
         }
      }
      if (first) {
         int result = 0;
         for (auto const& row : paper) {
            for (auto const& el : row) {
               if (el == '#') {
                  ++result;
               }
            }
         }
         std::cout << result - 1;
         first = false;
      }
   }
}

void TransparentOrigami::printResultPart2() {
   std::cout << std::endl;
   for (auto const& row : paper) {
      for (auto const& el : row) {
         if (el == '#') {
            std::cout << '#';
            continue;
         }
         std::cout << ' ';
      }
      std::cout << std::endl;
   }
}