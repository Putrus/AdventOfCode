#pragma once

#include "DecoratorTask.h"
#include "NoTask.h"

#include <vector>

enum class TaskName {
   SonarSweep = 1,
   Dive = 2,
   BinaryDiagnostic = 3,
   GiantSquid = 4,
   HydrothermalVenture = 5,
   LanternFish = 6,
   TheTreacheryOfWhales = 7,
   SevenSegmentSearch = 8,
   SmokeBasin = 9,
   SyntaxScoring = 10,
   DumboOctopus = 11
};

class Task {
private:
   ComponentTask * task;
public:
   Task(std::vector<TaskName> tasks);
   void printResults();
};