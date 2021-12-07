#include <iostream>

#include "Decorator/Task.h"

int main() {
   Task task({ TaskName::SonarSweep, 
      TaskName::Dive,
      TaskName::BinaryDiagnostic,
      TaskName::GiantSquid,
      TaskName::HydrothermalVenture});
   task.printResults();
   return 0;
}