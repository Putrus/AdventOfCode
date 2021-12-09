#include <iostream>

#include "Decorator/Task.h"

int main() {
   Task task({ /*TaskName::SonarSweep, 
      TaskName::Dive,
      TaskName::BinaryDiagnostic,
      TaskName::GiantSquid,
      TaskName::HydrothermalVenture,
      */TaskName::LanternFish});
   task.printResults();
   return 0;
}