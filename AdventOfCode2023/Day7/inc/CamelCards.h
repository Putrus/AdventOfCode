#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class CamelCards : public PuzzleDecorator
    {
    public:
        CamelCards(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        int getType(const std::string& hand);
        int getTypeJoker(const std::string& hand);

        std::vector<std::pair<std::string, long long>> hands;
    };
}