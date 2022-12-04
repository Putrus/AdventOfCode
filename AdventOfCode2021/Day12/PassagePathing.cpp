#include "PassagePathing.h"

#include <fstream>
#include <iostream>

PassagePathing::PassagePathing(ComponentTask* task) : DecoratorTask(task) {
}

void PassagePathing::printResults() {
   printResultsArgs("Day12/Input.txt", "--- Day 12: Passage Pathing ---");
   task->printResults();
}

void PassagePathing::loadInput(const char* filename) {
   std::ifstream file(filename);
   list.clear();
   while (!file.eof()) {
      std::string strRow;
      file >> strRow;
      if (!strRow.empty()) {
         int dashId = strRow.find_first_of('-');
         std::string first = strRow.substr(0, dashId);
         std::string second = strRow.substr(dashId + 1, strRow.length() - dashId);
         list[first].insert(second);
         list[second].insert(first);
      }
   }
   file.close();
}

void PassagePathing::printResultPart1() {
   std::vector<std::string> path;
   pathFinding("start", path);
   std::cout << paths.size();
}

void PassagePathing::printResultPart2() {
   std::vector<std::string> path;
   pathFinding2("start", path);
   std::cout << paths.size();
}

void PassagePathing::pathFinding(std::string vertex, std::vector<std::string> path) {
   path.push_back(vertex);
   for (auto const& v : list[vertex]) {
      if (v != "start") {
         if (v == "end") {
            std::vector<std::string> newPath = path;
            newPath.push_back(v);
            paths.insert(newPath);
            continue;
         }
         else if (v[0] >= 'a' && v[0] <= 'z' && std::find(path.begin(), path.end(), v) != path.end()) {
            continue;
         }
         else {
            pathFinding(v, path);
         }
      }
   }
}

void PassagePathing::pathFinding2(std::string vertex, std::vector<std::string> path) {
   path.push_back(vertex);
   for (auto const& v : list[vertex]) {
      if (v != "start") {
         if (v == "end") {
            std::vector<std::string> newPath = path;
            newPath.push_back(v);
            paths.insert(newPath);
            continue;
         }
         bool ok = true;
         if (v[0] >= 'a' && v[0] <= 'z' && std::count(path.begin(), path.end(), v) >= 1) {
            for (auto const& el : list) {
               if (el.first[0] >= 'a' && el.first[0] <= 'z' && std::count(path.begin(), path.end(), el.first) >= 2) {
                  ok = false;
                  break;
               }
            }
         }
         if (ok) {
            pathFinding2(v, path);
         }
      }
   }
}