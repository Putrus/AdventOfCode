#pragma once

#include <vector>
#include <string>

class BinaryDiagnostic {
private:
   std::vector<std::string> diagnosticReport;
   int gamma;
   int epsilon;

public:
   void loadInput(const char* filename);
   void test();
   int getResultPart1();
   int getResultPart2();

private:
   std::vector<int> createOnes();
   int countWithCommonPart(std::string part);
   int binaryToInt(std::string binary);
   std::string elementWithCommonPart(std::string part);
};