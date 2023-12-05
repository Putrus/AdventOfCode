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
        std::vector<std::pair<long long, long long>> initialSeedsRanges;

        struct Range
        {
            long long destination;
            long long source;
            long long length;
        };
        struct Map
        {
            std::vector<Range> ranges;

            long long getCorrespondingCategoryNumber(long long n) const
            {
                for (const auto& range : ranges)
                {
                    if (n >= range.source && n < range.source + range.length)
                    {
                        return range.destination + (n - range.source);
                    }
                }
                return n;
            }
        };

        std::array<Map, 7> maps;
    };
}