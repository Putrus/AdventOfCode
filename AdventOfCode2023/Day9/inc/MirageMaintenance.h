#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <deque>
#include <vector>

namespace aoc2023
{
    class MirageMaintenance : public PuzzleDecorator
    {
    public:
        MirageMaintenance(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        long long getExtrapolatedValue(const std::deque<long long>& sequence);
        long long getExtrapolatedBackwardValue(const std::deque<long long>& sequence);

        std::vector<std::deque<long long>> histories;
    };
}