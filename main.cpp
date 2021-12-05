#include <iostream>

#include "Day1/SonarSweep.h"
#include "Day2/Dive.h"
#include "Day3/BinaryDiagnostic.h"
#include "Day4/GiantSquid.h"
#include "Day5/HydrotermalVenture.h"

int main() {
   HydrotermalVenture h;
   h.loadInput("Day5/Input.txt");
   std::cout << h.getResultPart1();
   return 0;
}