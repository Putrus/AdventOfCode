#pragma once

#include "PuzzleComponent.h"

namespace aoc2023
{
    class PuzzleEmpty final : public PuzzleComponent
    {
    public:
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;
    };
}