#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class Scratchcards : public PuzzleDecorator
    {
    public:
        Scratchcards(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

        std::vector<std::pair<std::vector<int>, std::vector<int>>> scratchcards;
    };
}