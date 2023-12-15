#include "../inc/HotSprings.h"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <sstream>

#include <iostream>

namespace aoc2023
{
    HotSprings::HotSprings(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void HotSprings::printAnswers()
    {
        PuzzleDecorator::printAnswers(12, "Hot Springs");
    }

    void HotSprings::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string strDamaged;
        while (!file.eof())
        {
            std::string row;
            std::vector<int> group;
            file >> row;
            if (row.empty())
            {
                break;
            }
            std::string unfoldedRow;

            if (!row.empty())
            {
                unfoldedRow += row;
                for (int j = 0; j < 4; ++j)
                {
                    unfoldedRow += "?";
                    unfoldedRow += row;
                }
            }

            file >> strDamaged;
            std::replace(strDamaged.begin(), strDamaged.end(), ',', ' ');
            std::stringstream ss(strDamaged);
            while (!ss.eof())
            {
                int number;
                ss >> number;
                group.push_back(number);
            }

            std::vector<int> unfoldedGroup = group;
            for (int i = 0; i < 4; ++i)
            {
                for (int number : group)
                {
                    unfoldedGroup.push_back(number);
                }
            }

            springs.push_back({ row, group });
            unfoldedSprings.push_back({ unfoldedRow, unfoldedGroup });
        }

        file.close();
    }

    std::string HotSprings::getPart1()
    {
        long long arrangementCountsSum = 0;
        for (const auto& spring : springs)
        {
            long long arrangementCounts = getCounts(spring);
            arrangementCountsSum += arrangementCounts;
        }
        return std::to_string(arrangementCountsSum);
    }

    std::string HotSprings::getPart2()
    {
        long long arrangementCountsSum = 0;
        for (const auto& spring : unfoldedSprings)
        {
            long long arrangementCounts = getCounts(spring);
            arrangementCountsSum += arrangementCounts;
        }
        return std::to_string(arrangementCountsSum);
    }

    long long HotSprings::getCounts(const std::pair<std::string, std::vector<int>>& pair) const
    {
        std::string spring = "." + pair.first + ".";
        std::string group;
        for (int value : pair.second)
        {
            group += ".";
            for (int i = 0; i < value; ++i)
            {
                group += "#";
            }
        }
        group += ".";

        std::vector<std::vector<long long>> dp;
        for (size_t i = 0; i < group.size(); ++i)
        {
            std::vector<long long> row(spring.size(), 0);
            dp.push_back(row);
        }
        dp[0][0] = 1;

        for (int i = 0; i < static_cast<int>(dp.size()); ++i)
        {
            for (int j = 0; j < static_cast<int>(dp[i].size()); ++j)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }

                long long dpValue = 0;
                if (group[i] == '.')
                {
                    if (spring[j] == '.' || spring[j] == '?')
                    {
                        if (j > 0)
                        {
                            dpValue += dp[i][j - 1];
                            if (i > 0)
                            {
                                dpValue += dp[i - 1][j - 1];
                            }
                        }
                    }
                }
                else
                {
                    if (spring[j] == '#' || spring[j] == '?')
                    {
                        if (i > 0 && j > 0)
                        {
                            dpValue += dp[i - 1][j - 1];
                        }
                    }
                }
                dp[i][j] = dpValue;
            }
        }

        return dp[dp.size() - 1][dp[0].size() - 1];
    }
}