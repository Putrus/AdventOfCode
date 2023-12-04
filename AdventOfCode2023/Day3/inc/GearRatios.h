#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class GearRatios : public PuzzleDecorator
    {
    public:
        GearRatios(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        bool checkAdjacency(int x, int y, size_t length);
        bool checkSymbol(int i, int j);

        struct POINT
        {
            int x;
            int y;

            bool operator<(const GearRatios::POINT& other) const;
            bool operator==(const GearRatios::POINT& other) const;
        };

        

        std::pair<POINT, char> getAdjacency(int x, int y, size_t length);
        char getSymbol(int i, int j);

        std::vector<std::string> schematic;
    };
}