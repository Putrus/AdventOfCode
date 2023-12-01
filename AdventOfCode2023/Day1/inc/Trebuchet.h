#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <fstream>

namespace aoc2023
{
    class Trebuchet : public PuzzleDecorator
    {
    public:
        Trebuchet(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        std::ifstream mFile;
    };
}