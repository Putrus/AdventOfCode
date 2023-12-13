#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

namespace aoc2023
{
    class PointOfIncidence : public PuzzleDecorator
    {
    public:
        PointOfIncidence(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;
    };
}