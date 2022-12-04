#pragma once

#include "../Decorator/DecoratorTask.h"

#include <map>
#include <set>
#include <string>
#include <vector>

class PassagePathing : public DecoratorTask {
private:
   std::map<std::string, std::set<std::string>> list;
   std::set<std::vector<std::string>> paths;

public:
   PassagePathing(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;

   void pathFinding(std::string vertex, std::vector<std::string> path);
   void pathFinding2(std::string vertex, std::vector<std::string> path);
};