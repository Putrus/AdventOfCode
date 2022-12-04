#pragma once 

class ComponentTask {
protected:
   virtual void loadInput(const char* filename) = 0;
   virtual void printResultPart1() = 0;
   virtual void printResultPart2() = 0;
public:
   virtual ~ComponentTask() {}
   virtual void printResults() = 0;
};