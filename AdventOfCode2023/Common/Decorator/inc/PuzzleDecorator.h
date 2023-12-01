#pragma once

#include "PuzzleComponent.h"

#include <memory>

namespace aoc2023
{
    class PuzzleDecorator : public PuzzleComponent
    {
    public:
        PuzzleDecorator(std::unique_ptr<PuzzleComponent>&& puzzle);
        virtual void printAnswers() = 0;

    protected:
        virtual void loadInput(const char* filename) = 0;
        virtual std::string getPart1() = 0;
        virtual std::string getPart2() = 0;

        void printAnswers(int day, const std::string& puzzleName);

        std::unique_ptr<PuzzleComponent> mPuzzle;
    };
}