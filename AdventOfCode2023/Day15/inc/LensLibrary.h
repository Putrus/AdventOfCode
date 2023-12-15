#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class LensLibrary : public PuzzleDecorator
    {
    public:
        LensLibrary(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        unsigned char getHash(const std::string& sequence) const;

        std::vector<std::string> sequences;
    };
}