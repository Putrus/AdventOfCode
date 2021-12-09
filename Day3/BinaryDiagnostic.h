#pragma once

#include "../Decorator/DecoratorTask.h"

#include <vector>
#include <string>

class BinaryDiagnostic : public DecoratorTask {
private:
   std::vector<std::string> diagnosticReport;
   int gamma;
   int epsilon;

public:
   BinaryDiagnostic(ComponentTask* task);
   void printResults() override;

private:
   void loadInput(const char* filename) override;
   void printResultPart1() override;
   void printResultPart2() override;

   std::vector<int> createOnes();
   int countWithCommonPart(std::string part);
   int binaryToInt(std::string binary);
   std::string elementWithCommonPart(std::string part);
};