#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class ClumsyCrucible : public PuzzleDecorator
    {
    public:
        ClumsyCrucible(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        struct Pos
        {
            int x;
            int y;
            bool operator==(const Pos& other) const
            {
                return x == other.x && y == other.y;
            }
        };

        struct Move
        {
            Pos pos;
            Pos dir;
            int heatLoss = 0;
            int straight = 0;
        };

        std::vector<std::vector<int>> map;
    };
}