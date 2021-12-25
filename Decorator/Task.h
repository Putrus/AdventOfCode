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
   DumboOctopus = 11,
   PassagePathing = 12,
   TransparentOrigami = 13,
   ExtendedPolymerization = 14,
   Chiton = 15,
   PacketDecoder = 16,
   TrickShot = 17,
   Snailfish = 18,
   BeaconScanner = 19,
   TrenchMap = 20,
   DiracDice = 21,
   ReactorReboot = 22,
   Amphipod = 23,
   ArithmeticLogicUnit = 24
};

class Task {
private:
   ComponentTask * task;
public:
   Task(std::vector<TaskName> tasks);
   void printResults();
};