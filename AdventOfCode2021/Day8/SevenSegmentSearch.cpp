#include "SevenSegmentSearch.h"

#include <fstream>
#include <iostream>
#include <algorithm>

SevenSegmentSearch::SevenSegmentSearch(ComponentTask* task) : DecoratorTask(task) {
}

void SevenSegmentSearch::printResults() {
   printResultsArgs("Day8/Input.txt", "--- Day 8: Seven Segment Search ---");
   task->printResults();
}

void SevenSegmentSearch::loadInput(const char* filename) {
   std::ifstream file(filename);
   std::string input;
   while (!file.eof()) {
      //load 10 patterns
      std::vector<std::string> patterns;
      for (int i = 0; i < 10; ++i) {
         file >> input;
         std::sort(input.begin(), input.end());
         patterns.push_back(input);
      }
      file >> input; //delimeter "|"
      //load 4 outputs
      std::vector<std::string> output;
      for (int i = 0; i < 4; ++i) {
         file >> input;
         std::sort(input.begin(), input.end());
         output.push_back(input);
      }
      notes.push_back({ patterns, output });
   }
   notes.erase(notes.end() - 1);
   file.close();
}

void SevenSegmentSearch::printResultPart1() {
   int counter1478 = 0;
   for (auto const& note : notes) {
      for (auto const& out : note.output) {
         if (out.size() == 2 || out.size() == 3 || out.size() == 4 || out.size() == 7) {
            ++counter1478;
         }
      }
   }
   std::cout << counter1478;
}

void SevenSegmentSearch::printResultPart2() {
   int sum = 0;
   for (auto & note : notes) {
      std::string display = displayDecode(note); 
      sum += outputToNumber(display, note);
   }
   std::cout << sum;
}

std::string SevenSegmentSearch::displayDecode(Note note) {
   // 0000
   //1    2
   //1    2
   // 3333
   //4    5
   //4    5
   // 6666
   std::string display = ".......";
   //sort by string lengths
   std::sort(note.patterns.begin(), note.patterns.end(), [](auto const& lhs, auto const& rhs) {
      return lhs.length() < rhs.length();});

   std::string seven = note.patterns[1];
   seven.erase(std::remove(seven.begin(), seven.end(), note.patterns[0][0]), seven.end());
   seven.erase(std::remove(seven.begin(), seven.end(), note.patterns[0][1]), seven.end());

   display[0] = seven[0];
   //6/9/0 iteration
   std::string six = "......";
   for (int i = 6; i < 9; ++i) {
      auto search1 = std::find(note.patterns[i].begin(), note.patterns[i].end(), note.patterns[0][0]);
      auto search2 = std::find(note.patterns[i].begin(), note.patterns[i].end(), note.patterns[0][1]);
      if (search1 == note.patterns[i].end() || search2 == note.patterns[i].end()) {
         display[2] = (search1 == note.patterns[i].end()) ? note.patterns[0][0] : note.patterns[0][1];
         display[5] = (search2 == note.patterns[i].end()) ? note.patterns[0][0] : note.patterns[0][1];
         six = note.patterns[i];
      }
   }
   //search for 5 iteration
   for (int i = 3; i <= 5; ++i) {
      std::string sixTmp = six;
      for (size_t j = 0; j < note.patterns[i].size(); ++j) {
         sixTmp.erase(std::remove(sixTmp.begin(), sixTmp.end(), note.patterns[i][j]), sixTmp.end());
      }
      if (sixTmp.size() == 1) {
         display[4] = sixTmp[0];
      }
      auto find2 = std::find(note.patterns[i].begin(), note.patterns[i].end(), display[5]);
      if (find2 == note.patterns[i].end()) {
         for (char a = 'a'; a <= 'g'; ++a) {
            if (a != display[5]) {
               auto findlack = std::find(note.patterns[i].begin(), note.patterns[i].end(), a);
               if (findlack == note.patterns[i].end()) {
                  display[1] = a;
                  break;
               }
            }
         }
      }
   }

   for (int i = 0; i < note.patterns[2].length(); ++i) {
      auto find = std::find(display.begin(), display.end(), note.patterns[2][i]);
      if (find == display.end()) {
         display[3] = note.patterns[2][i];
         break;
      }
   }

   for (char a = 'a'; a <= 'g'; ++a) {
      auto find = std::find(display.begin(), display.end(), a);
      if (find == display.end()) {
         display[6] = a;
         break;
      }
   }
   return display;
}

int SevenSegmentSearch::outputToNumber(const std::string &display, const Note & note) {
   std::string number = "";
   for (auto const& out : note.output) {
      if (out.length() == 2) {
         number += "1";
      }
      else if (out.length() == 3) {
         number += "7";
      }
      else if (out.length() == 4) {
         number += "4";
      }
      else if (out.length() == 5) {
         auto check2 = std::find(out.begin(), out.end(), display[1]);
         if (check2 == out.end()) {
            auto check3 = std::find(out.begin(), out.end(), display[4]);
            if (check3 == out.end()) {
               number += "3";
               continue;
            }
            number += "2";
            continue;
         }
         number += "5";
      }
      else if (out.length() == 6) {
         auto check0 = std::find(out.begin(), out.end(), display[3]);
         if (check0 == out.end()) {
            number += "0";
            continue;
         }
         auto check6 = std::find(out.begin(), out.end(), display[2]);
         if (check6 == out.end()) {
            number += "6";
            continue;
         }
         number += "9";
      }
      else if (out.length() == 7) {
         number += "8";
      }
   }
   return atoi(number.c_str());
}