#include "../inc/IfYouGiveASeedAFertilizer.h"

#include <fstream>
#include <algorithm>

namespace aoc2023
{
    IfYouGiveASeedAFertilizer::IfYouGiveASeedAFertilizer(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void IfYouGiveASeedAFertilizer::printAnswers()
    {
        PuzzleDecorator::printAnswers(5, "If You Give A Seed A Fertilizer");
    }

    void IfYouGiveASeedAFertilizer::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }
        std::string input;
        file >> input;

        //initial seeds
        long long start = -1;
        while (true)
        {
            file >> input;
            if (input == "seed-to-soil")
            {
                break;
            }
            initialSeeds.push_back(std::stoll(input));
            if (start == -1)
            {
                start = std::stoll(input);
            }
            else
            {
                initialSeedsRanges.push_back({ start, start + std::stoll(input) });
                start = -1;
            }
        }

        auto readMap = [this, &file, &input](int type, const std::string& end)
        {
            Range range;
            file >> input;
            while (!file.eof())
            {
                file >> input;
                if (input == end)
                {
                    break;
                }
                range.destination = std::stoll(input);
                file >> range.source;
                file >> range.length;
                maps.at(type).ranges.push_back(range);
            }
        };

        readMap(0, "soil-to-fertilizer");
        readMap(1, "fertilizer-to-water");
        readMap(2, "water-to-light");
        readMap(3, "light-to-temperature");
        readMap(4, "temperature-to-humidity");
        readMap(5, "humidity-to-location");
        readMap(6, "end-of-file");
    }

    std::string IfYouGiveASeedAFertilizer::getPart1()
    {
        long long lowestLocation = std::numeric_limits<long long>::max();

        for (long long initialSeed : initialSeeds)
        {
            long long lastCategoryValue = initialSeed;
            for (size_t i = 0; i < maps.size(); ++i)
            {
                lastCategoryValue = maps.at(i).getCorrespondingCategoryNumber(lastCategoryValue);
            }

            if (lastCategoryValue < lowestLocation)
            {
                lowestLocation = lastCategoryValue;
            }
        }
        
        return std::to_string(lowestLocation);
    }

    std::string IfYouGiveASeedAFertilizer::getPart2()
    {
        long long lowestLocation = std::numeric_limits<long long>::max();
        
        int count = 0;
        for (const auto& initialSeedsRange : initialSeedsRanges)
        {
            for (long long i = initialSeedsRange.first; i < initialSeedsRange.second; ++i)
            {
                long long lastCategoryValue = i;
                for (size_t j = 0; j < maps.size(); ++j)
                {
                    lastCategoryValue = maps.at(j).getCorrespondingCategoryNumber(lastCategoryValue);
                }

                if (lastCategoryValue < lowestLocation)
                {
                    lowestLocation = lastCategoryValue;
                }
            }
        }

        return std::to_string(lowestLocation);
    }
}