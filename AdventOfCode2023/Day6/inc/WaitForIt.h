#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class WaitForIt : public PuzzleDecorator
    {
    public:
        WaitForIt(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        std::vector<std::pair<long long, long long>> records;
        std::pair<long long, long long> oneRaceRecord;
    };
}