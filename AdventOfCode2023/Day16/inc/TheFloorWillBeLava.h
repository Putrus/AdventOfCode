#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class TheFloorWillBeLava: public PuzzleDecorator
    {
    public:
        TheFloorWillBeLava(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        struct Beam
        {
            int x;
            int y;
            int dx;
            int dy;
        };
        void energize(Beam beam);
        void energizedReset();

        std::vector<std::string> contraption;
        std::vector<std::string> energized;
        std::vector<Beam> beamHistory;
        long long result = 0;
    };
}