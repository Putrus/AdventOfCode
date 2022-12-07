#include "../inc/NoSpaceLeftOnDevice.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

NoSpaceLeftOnDevice::NoSpaceLeftOnDevice(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void NoSpaceLeftOnDevice::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(7, "No Space Left On Device");
   puzzle->calcAndPrintAnswers();
}

void NoSpaceLeftOnDevice::loadInput(const char* input_path)
{
   std::fstream input(input_path);
   std::string first;
   std::shared_ptr<File> current_directory;
   while (input >> first)
   {
      if (first == "$")
      {
         std::string command;
         input >> command;
         if (command == "cd")
         {
            std::string argument;
            input >> argument;
            if (argument == "/")
            {
               //file initialization
               if (!file)
               {
                  file = std::make_shared<File>("/");
               }
               current_directory = file;
            }
            else if (argument == "..")
            {
               current_directory = current_directory->parent;
            }
            else
            {
               auto find_child = std::find_if(
                  current_directory->children.begin(), current_directory->children.end(),
                  [argument](auto const& child)
                  {
                     return child->name == argument;
                  });
               if (find_child != current_directory->children.end())
               {
                  current_directory = *find_child;
               }
               else
               {
                  std::shared_ptr<File> new_directory =
                     std::make_shared<File>(argument, current_directory);
                  current_directory->children.push_back(new_directory);
                  current_directory = new_directory;
               }
            }
         }
      }
      else if (first == "dir")
      {
         //dir in ls command
         std::string name;
         input >> name;
         auto find_child = std::find_if(
            current_directory->children.begin(), current_directory->children.end(),
            [name](auto const& child)
            {
               return child->name == name;
            });
         if (find_child == current_directory->children.end())
         {
            std::shared_ptr<File> new_directory =
               std::make_shared<File>(first, current_directory);
            current_directory->children.push_back(new_directory);
         }
      }
      else
      {
         //file in ls command
         unsigned int size = std::stoi(first);
         std::string name;
         input >> name;
         auto find_child = std::find_if(
            current_directory->children.begin(), current_directory->children.end(),
            [name](auto const& child)
            {
               return child->name == name;
            });
         if (find_child == current_directory->children.end())
         {
            std::shared_ptr<File> new_file =
               std::make_shared<File>(name, current_directory, size, false);
            current_directory->children.push_back(new_file);
            auto it = current_directory;
            while (it != nullptr)
            {
               it->size += size;
               it = it->parent;
            }
         }
      }
   }
}

void NoSpaceLeftOnDevice::calcAndPrintAnswerToPart1()
{
   unsigned int total_size = 0;
   file->countPart1Directories(total_size);
   std::cout << total_size << std::endl;
}

void NoSpaceLeftOnDevice::calcAndPrintAnswerToPart2()
{
   unsigned int require_space = 30000000 - (70000000 - file->size);
   unsigned int best = 70000000;
   file->choosePart2Best(require_space, best);
   std::cout << best << std::endl;
}
