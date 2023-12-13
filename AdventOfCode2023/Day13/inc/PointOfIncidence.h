#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class PointOfIncidence : public PuzzleDecorator
    {
    public:
        PointOfIncidence(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        std::vector<std::vector<std::string>> patterns;

        int getHorizontalReflection(const std::vector<std::string>& pattern) const;
        int getVerticalReflection(const std::vector<std::string>& pattern) const;

        std::vector<std::string> getTransposePattern(const std::vector<std::string>& pattern) const;
    };
}