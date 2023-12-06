#include "../inc/WaitForIt.h"

#include <fstream>

namespace aoc2023
{
    WaitForIt::WaitForIt(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void WaitForIt::printAnswers()
    {
        PuzzleDecorator::printAnswers(6, "Wait For It");
    }

    void WaitForIt::loadInput(const char* filename)
    {
        std::fstream file(filename);
        std::string input;
        file >> input;
        std::string time;
        while (!file.eof())
        {
            file >> input;
            if (input == "Distance:")
            {
                break;
            }
            records.push_back({ std::stoll(input), 0 });
            time += input;
        }
        oneRaceRecord.first = std::stoll(time);

        std::string distance;
        for(size_t i = 0; i < records.size(); ++i)
        {
            file >> input;
            records[i].second = std::stoll(input);
            distance += input;
        }
        oneRaceRecord.second = std::stoll(distance);

        file.close();
    }

    std::string WaitForIt::getPart1()
    {
        long long ways = 1;
        for (const auto& record : records)
        {
            long long toBeat = record.second;
            long long internalWays = 0;
            for (long long i = 0; i < record.first; ++i)
            {
                long long distance = (record.first - i) * i;
                if (distance > toBeat)
                {
                    ++internalWays;
                }
            }
            ways *= internalWays;
        }
        return std::to_string(ways);
    }

    std::string WaitForIt::getPart2()
    {
        long long ways = 1;
        long long toBeat = oneRaceRecord.second;
        for (long long i = 0; i < oneRaceRecord.first; ++i)
        {
            long long distance = (oneRaceRecord.first - i) * i;
            if (distance > toBeat)
            {
                ++ways;
            }
        }
        return std::to_string(ways - 1);
    }
}