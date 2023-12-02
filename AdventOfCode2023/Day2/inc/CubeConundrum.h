#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class CubeConundrum : public PuzzleDecorator
    {
    public:
        CubeConundrum(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

        struct Cubes
        {
            int red = 0;
            int green = 0;
            int blue = 0;
        };

        std::vector<std::vector<Cubes>> games;
    };
}