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

        fillCorrespondingTypes(file, "soil-to-fertilizer", 0);
        for (long long initialSeed : initialSeeds)
        {
            bool ok = true;
            for (const auto& types : allTypes)
            {
                if (types->at(0) == initialSeed)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                auto types = std::make_unique<Types>(initialSeed);
                allTypes.push_back(std::move(types));
            }
        }

        fillCorrespondingTypes(file, "fertilizer-to-water", 1);
        fillCorrespondingTypes(file, "water-to-light", 2);
        fillCorrespondingTypes(file, "light-to-temperature", 3);
        fillCorrespondingTypes(file, "temperature-to-humidity", 4);
        fillCorrespondingTypes(file, "humidity-to-location", 5);
        fillCorrespondingTypes(file, "end-of-file", 6);

        file.close();
        std::sort(allTypes.begin(), allTypes.end(), [](const auto& lhs, const auto& rhs)
            {
                return lhs->at(0) < rhs->at(0);
            });
    }

    std::string IfYouGiveASeedAFertilizer::getPart1()
    {
        long long lowestLocation = std::numeric_limits<long long>::max();
        for (const auto& types : allTypes)
        {
            if (types->at(7) < lowestLocation)
            {
                lowestLocation = types->at(7);
            }
        }

        return std::to_string(lowestLocation);
    }

    std::string IfYouGiveASeedAFertilizer::getPart2()
    {
        int result = 0;
        
        return std::to_string(result);
    }

    void IfYouGiveASeedAFertilizer::fillCorrespondingTypes(std::ifstream& file,
        const std::string& end, int type)
    {
        std::string input;
        long long destination;
        long long source;
        long long range;

        file >> input;
        while (!file.eof())
        {
            file >> input;
            if (input == end)
            {
                break;
            }
            destination = std::stoll(input);
            file >> source >> range;

            if (type == 0)
            {
                for (long long initialSeed : initialSeeds)
                {
                    if (initialSeed >= source && initialSeed < source + range)
                    {
                        auto types = std::make_unique<Types>(0);
                        types->at(type) = initialSeed;
                        types->fill(type + 1, destination + (initialSeed - source));
                        allTypes.push_back(std::move(types));
                    }
                }
            }
            else
            {
                for (auto& types : allTypes)
                {
                    if (types->at(type) >= source && types->at(type) < source + range)
                    {
                        types->fill(type + 1, destination + (types->at(type) - source));
                    }
                }
            }
        }
    }
}