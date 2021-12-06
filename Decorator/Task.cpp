#include "Task.h"

Task::Task(const std::vector<Day>& tasks) {
   task = std::make_unique<NoTask>();
   for (const auto& t : tasks) {
      switch (t) {
      case Day::SonarSweep:
         break;
      }
   }
}