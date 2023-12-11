#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class CosmicExpansion : public PuzzleDecorator
    {
    public:
        CosmicExpansion(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        long long getShortestPaths(int expansion);
        std::vector<std::string> image;
        std::vector<size_t> expandedColumns;
        std::vector<size_t> expandedRows;
    };
}