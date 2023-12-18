#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class LavaductLagoon : public PuzzleDecorator
    {
    public:
        LavaductLagoon(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        int hexToInt(const std::string& hex) const;
        
        struct Dig
        {
            char direction;
            int meters;
        };

        std::vector<Dig> digs;
        std::vector<Dig> digs2;
    };
}