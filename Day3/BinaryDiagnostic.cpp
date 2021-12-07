#include "BinaryDiagnostic.h"

#include <fstream>
#include <iostream>
#include <algorithm>

BinaryDiagnostic::BinaryDiagnostic(ComponentTask* task) : DecoratorTask(task), gamma(0), epsilon(0) {}

void BinaryDiagnostic::printResults() {
   printResultsArgs("Day3/Input.txt", "--- Day 3: Binary Diagnostic ---");
   task->printResults();
}

void BinaryDiagnostic::loadInput(const char* filename) {
   std::ifstream file(filename);
   while (!file.eof()) {
      std::string n;
      file >> n;
      diagnosticReport.push_back(n);
   }
   diagnosticReport.erase(diagnosticReport.end() - 1);
   file.close();
}

int BinaryDiagnostic::getResultPart1() {
   std::vector<int> ones = createOnes();

   int binary = 1;
   for (int i = ones.size() - 1; i >= 0; --i) {
      gamma += ((ones[i] > diagnosticReport.size() / 2) ? 1 : 0) * binary;
      epsilon += ((ones[i] > diagnosticReport.size() / 2) ? 0 : 1) * binary;
      binary *= 2;
   }
   return gamma * epsilon;
}

int BinaryDiagnostic::getResultPart2() {
   std::string oxygen = "";
   std::string co2 = "";
   std::vector<int> ones = createOnes();
   gamma = -1;
   epsilon = -1;
   for (size_t i = 0; i < ones.size(); ++i) {
      //oxygen part
      int oxCommonPartOne = countWithCommonPart(oxygen + "1");
      int oxCommonPartZero = countWithCommonPart(oxygen + "0");
      
      if (oxCommonPartOne == oxCommonPartZero || oxCommonPartOne > oxCommonPartZero) {
         oxygen += "1";
      }
      else {
         oxygen += "0";
      }

      if (oxCommonPartOne <= 1 && oxCommonPartZero <= 1 && gamma == -1) {
         gamma = binaryToInt(elementWithCommonPart(oxygen));
      }
      
      //co2 part
      int co2CommonPartOne = countWithCommonPart(co2 + "1");
      int co2CommonPartZero = countWithCommonPart(co2 + "0");

      if (co2CommonPartOne == co2CommonPartZero || co2CommonPartOne > co2CommonPartZero) {
         co2 += "0";
      }
      else {
         co2 += "1";
      }

      if (co2CommonPartOne <= 1 && co2CommonPartZero <= 1 && epsilon == -1) {
         epsilon = binaryToInt(elementWithCommonPart(co2));
      }
   }
   return gamma * epsilon;
}

std::vector<int> BinaryDiagnostic::createOnes() {
   std::vector<int> ones;
   if (!diagnosticReport.empty()) {
      for (size_t i = 0; i < diagnosticReport[0].length(); ++i) {
         ones.push_back(0);
      }
   }
   for (auto const& report : diagnosticReport) {
      for (size_t i = 0; i < report.length(); ++i) {
         ones[i] += (report[i] == '1') ? 1 : 0;
      }
   }
   return ones;
}

int BinaryDiagnostic::countWithCommonPart(std::string part) {
   return std::count_if(diagnosticReport.begin(), diagnosticReport.end(), [part](auto const& element) {
      return element.substr(0, part.length()) == part; });
}

std::string BinaryDiagnostic::elementWithCommonPart(std::string part) {
   return *std::find_if(diagnosticReport.begin(), diagnosticReport.end(), [part](auto const& element) {
      return element.substr(0, part.length()) == part; });
}

int BinaryDiagnostic::binaryToInt(std::string binary) {
   int b = 1;
   int result = 0;
   for (int i = binary.length() - 1; i >= 0; --i) {
      result += ((binary[i] == '1') ? 1 : 0) * b;
      b *= 2;
   }
   return result;
}
