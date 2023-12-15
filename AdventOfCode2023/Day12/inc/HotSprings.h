#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class HotSprings : public PuzzleDecorator
    {
    public:
        HotSprings(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        long long getCounts(const std::pair<std::string, std::vector<int>>& spring) const;

        std::vector<std::pair<std::string, std::vector<int>>> springs;
        std::vector<std::pair<std::string, std::vector<int>>> unfoldedSprings;
    };
}