#pragma once

#include "Decorator.h"
#include "NoTask.h"

#include <vector>

enum class Day {
   SonarSweep = 1,
   Dive = 2,
   BinaryDiagnostic = 3,
   GiantSquid = 4,
   HydrotermalVenture = 5,
   LanternFish = 6
};


class Task {
private:
   std::unique_ptr<InterfaceTask> task;

public:
   Task(const std::vector<Day>& tasks);
};