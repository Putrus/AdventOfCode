#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <array>
#include <vector>

namespace aoc2023
{
    
    class IfYouGiveASeedAFertilizer : public PuzzleDecorator
    {
    public:
        IfYouGiveASeedAFertilizer(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        std::vector<long long> initialSeeds;

        class Types : public std::array<long long, 8>
        {
        public:
            Types(long long value)
            {
                for (int i = 0; i < 8; ++i)
                {
                    this->at(i) = value;
                }
            }

            void fill(int id, long long value)
            {
                for (int i = id; i < 8; ++i)
                {
                    this->at(i) = value;
                }
            }
        };

        std::vector<std::unique_ptr<Types>> allTypes;

        void fillCorrespondingTypes(std::ifstream& file, const std::string& end, int type);
    };
}