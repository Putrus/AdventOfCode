#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <string>
#include <vector>

struct File
{
   File
   (
      std::string const& name,
      std::shared_ptr<File> parent = nullptr,
      unsigned int size = 0,
      bool directory = true
   ) : name(name),
      parent(parent),
      size(size),
      directory(directory)
   {}

   void countPart1Directories(unsigned int& total_size)
   {
      if (this->size <= 100000)
      {
         total_size += this->size;
      }
      for (auto const& child : this->children)
      {
         if (child->directory)
         {
            child->countPart1Directories(total_size);
         }
      }
   }

   void choosePart2Best(unsigned int require_space, unsigned int& best)
   {
      if (this->size > require_space && this->size < best)
      {
         best = this->size;
      }
      for (auto const& child : this->children)
      {
         if (child->directory)
         {
            child->choosePart2Best(require_space, best);
         }
      }
   }

   std::string name;
   std::shared_ptr<File> parent;
   unsigned int size;
   bool directory;
   std::vector<std::shared_ptr<File>> children;
};

class NoSpaceLeftOnDevice final : public PuzzleDecorator
{
public:
   NoSpaceLeftOnDevice(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;

private:
   std::shared_ptr<File> file;
};