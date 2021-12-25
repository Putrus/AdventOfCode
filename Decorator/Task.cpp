#include "Task.h"

#include "../Day1/SonarSweep.h"
#include "../Day2/Dive.h"
#include "../Day3/BinaryDiagnostic.h"
#include "../Day4/GiantSquid.h"
#include "../Day5/HydrothermalVenture.h"
#include "../Day6/Lanternfish.h"
#include "../Day7/TheTreacheryOfWhales.h"
#include "../Day8/SevenSegmentSearch.h"
#include "../Day9/SmokeBasin.h"
#include "../Day10/SyntaxScoring.h"
#include "../Day11/DumboOctopus.h"
#include "../Day12/PassagePathing.h"
#include "../Day13/TransparentOrigami.h"

Task::Task(std::vector<TaskName> tasks) {
   task = new NoTask();
   for (const auto& t : tasks) {
      switch (t) {
      case TaskName::SonarSweep:
         task = new SonarSweep(task);
         break;
      case TaskName::Dive:
         task = new Dive(task);
         break;
      case TaskName::BinaryDiagnostic:
         task = new BinaryDiagnostic(task);
         break;
      case TaskName::GiantSquid:
         task = new GiantSquid(task);
         break;
      case TaskName::HydrothermalVenture:
         task = new HydrothermalVenture(task);
         break;
      case TaskName::LanternFish:
         task = new Lanternfish(task);
         break;
      case TaskName::TheTreacheryOfWhales:
         task = new TheTreacheryOfWhales(task);
         break;
      case TaskName::SevenSegmentSearch:
         task = new SevenSegmentSearch(task);
         break;
      case TaskName::SmokeBasin:
         task = new SmokeBasin(task);
         break;
      case TaskName::SyntaxScoring:
         task = new SyntaxScoring(task);
         break;
      case TaskName::DumboOctopus:
         task = new DumboOctopus(task);
         break;
      case TaskName::PassagePathing:
         task = new PassagePathing(task);
         break;
      case TaskName::TransparentOrigami:
         task = new TransparentOrigami(task);
         break;
      }
   }
}

void Task::printResults() {
   task->printResults();
}