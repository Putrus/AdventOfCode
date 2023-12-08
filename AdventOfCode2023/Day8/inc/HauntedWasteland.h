#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <map>
#include <vector>

namespace aoc2023
{
    class HauntedWasteland : public PuzzleDecorator
    {
    public:
        HauntedWasteland(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        std::string instruction;
        std::vector<std::string> startNodes;
        std::map<std::string, std::pair<std::string, std::string>> network;

    };
}