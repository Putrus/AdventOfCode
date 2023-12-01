#pragma once

#include <string>

namespace aoc2023
{
    class PuzzleComponent
    {
    public:
        virtual void printAnswers() = 0;

    protected:
        virtual void loadInput(const char* filename) = 0;
        virtual std::string getPart1() = 0;
        virtual std::string getPart2() = 0;
    };
}