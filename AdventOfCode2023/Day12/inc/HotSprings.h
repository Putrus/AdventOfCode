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
        std::vector<int> getGroup(const std::string& row) const;
        int getBit(int number, int n) const;
        long long getCounts(const std::vector<std::pair<std::string, std::vector<int>>>& springs) const;

        std::vector<std::pair<std::string, std::vector<int>>> springs;
        std::vector<std::pair<std::string, std::vector<int>>> unfoldedSprings;
    };
}