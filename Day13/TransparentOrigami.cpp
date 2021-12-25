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
   int paperSize = 0;
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
         paperSize = std::max(first, std::max(second, paperSize));
         pairs.insert({ first, second });
      }
   }
   //pairs to transparent paper
   for (int i = 0; i < paperSize + 1; ++i) {
      std::vector<char> row(paperSize + 1, '.');
      paper.push_back(row);
   }
   for (auto const& pair : pairs) {
      paper[pair.second][pair.first] = '#';
   }
   file.close();
}

void TransparentOrigami::printResultPart1() {
   auto newPaper = paper;
   for (auto const& instruction : instructions) {
      if (instruction.first == 'y') {
         for (int i = instruction.second + 1; i < newPaper.size(); ++i) {
            for (int j = 0; j < newPaper[i].size(); ++j) {
               if (newPaper[i][j] == '#') {
                  newPaper[instruction.second + (instruction.second - i)][j] = '#';
               }
            }
         }
         int oldNewPaperSize = newPaper.size();
         for (int i = instruction.second; i < oldNewPaperSize; ++i) {
            newPaper.erase(newPaper.begin() + instruction.second);
         }
         break;
      }
      if (instruction.first == 'x') {
         for (int i = 0; i < newPaper.size(); ++i) {
            for (int j = instruction.second; j < newPaper[i].size(); ++j) {
               int mirrId = instruction.second + (instruction.second - j);
               if (newPaper[i][j] == '#' && mirrId >= 0) {
                  newPaper[i][mirrId] = '#';
               }
            }
         }
         for (int i = 0; i < newPaper.size(); ++i) {
            while (newPaper[i].size() != instruction.second) {
               newPaper[i].erase(newPaper[i].begin() + instruction.second);
            }
         }
      }
      break;
   }
   int result = 0;
   for (auto const& row : newPaper) {
      for (auto const& el : row) {
         if (el == '#') {
            ++result;
         }
      }
   }
   std::cout << result;
}

void TransparentOrigami::printResultPart2() {
   
}