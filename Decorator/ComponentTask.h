#pragma once 

class ComponentTask {
protected:
   virtual void loadInput(const char* filename) = 0;
   virtual int getResultPart1() = 0;
   virtual int getResultPart2() = 0;
public:
   virtual ~ComponentTask() {}
   virtual void printResults() = 0;
};