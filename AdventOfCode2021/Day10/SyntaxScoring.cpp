#include "SyntaxScoring.h"

#include <fstream>
#include <map>
#include <iostream>
#include <algorithm>

SyntaxScoring::SyntaxScoring(ComponentTask* task) : DecoratorTask(task) {
}

void SyntaxScoring::printResults() {
   printResultsArgs("Day10/Input.txt", "--- Day 10: Syntax Scoring ---");
   task->printResults();
}

void SyntaxScoring::loadInput(const char* filename) {
   std::ifstream file(filename);
   subsystem.clear();
   while (!file.eof()) {
      std::string chunks;
      file >> chunks;
      if (!chunks.empty()) {
         subsystem.push_back(chunks);
      }
   }
   file.close();
}

void SyntaxScoring::printResultPart1() {
   int syntaxErrorScore = 0;
   std::string open = "([{<";
   std::map<char, char> closeOpen = { {')', '('}, {']', '['}, {'}', '{'}, {'>', '<'} };
   std::map<char, int> closePoints = { {')', 3}, {']', 57}, {'}', 1197}, {'>', 25137} };
   std::string chunksNow;
   for (auto const& ch : subsystem) {
      for (auto const& chunk : ch) {
         if (std::find(open.begin(), open.end(), chunk) != open.end()){
            chunksNow.push_back(chunk);
         }
         else {
            if (closeOpen[chunk] != chunksNow[chunksNow.size() - 1]) {
               syntaxErrorScore += closePoints[chunk];
            }
            chunksNow.erase(chunksNow.end() - 1);
         }
      }
   }
   std::cout << syntaxErrorScore;
}

void SyntaxScoring::printResultPart2() {
   int syntaxErrorScore = 0;
   std::string open = "([{<";
   std::map<char, char> closeOpen = { {')', '('}, {']', '['}, {'}', '{'}, {'>', '<'} };
   std::map<char, int> openPoints = { {'(', 1}, {'[', 2}, {'{', 3}, {'<', 4} };
   std::string chunksNow;
   std::vector<unsigned long long> autocompletePoints;
   bool correct = true;
   for (auto const& ch : subsystem) {
      correct = true;
      for (auto const& chunk : ch) {
         if (std::find(open.begin(), open.end(), chunk) != open.end()) {
            chunksNow.push_back(chunk);
         }
         else {
            if (closeOpen[chunk] != chunksNow[chunksNow.size() - 1]) {
               correct = false;
               break;
            }
            chunksNow.erase(chunksNow.end() - 1);
         }
      }
      if (correct) {
         unsigned long long points = 0;
         for (int i = chunksNow.length() - 1; i >= 0; --i) {
            points = points * 5 + openPoints[chunksNow[i]];
         }
         if (points) {
            autocompletePoints.push_back(points);
         }
      }
      chunksNow.clear();
   }
   std::sort(autocompletePoints.begin(), autocompletePoints.end());
   std::cout << autocompletePoints[autocompletePoints.size() / 2];
}