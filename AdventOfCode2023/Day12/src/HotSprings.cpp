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
            std::string record;
            for (size_t i = 0; i < row.size(); ++i)
            {
                if (row[i] != '?')
                {
                    record += row[i];
                }
                else if (!record.empty())
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        unfoldedRow += record;
                        for (size_t k = 0; k < record.size(); ++k)
                        {
                            unfoldedRow += '?';
                        }
                    }
                    unfoldedRow += record;
                    record = "";
                }
                else
                {
                    unfoldedRow += '?';
                }
            }

            if (!record.empty())
            {
                for (int j = 0; j < 4; ++j)
                {
                    unfoldedRow += record;
                    for (size_t k = 0; k < record.size(); ++k)
                    {
                        unfoldedRow += '?';
                    }
                }
                unfoldedRow += record;
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
            springs.push_back({ row, group });
            unfoldedSprings.push_back({ unfoldedRow, group });
        }

        file.close();
    }

    std::string HotSprings::getPart1()
    {
        return std::to_string(getCounts(springs));
    }

    std::string HotSprings::getPart2()
    {
        return std::to_string(getCounts(unfoldedSprings));
    }

    std::vector<int> HotSprings::getGroup(const std::string& row) const
    {
        std::vector<int> group;
        int count = 0;
        for (char c : row)
        {
            if (c == '.')
            {
                if (count != 0)
                {
                    group.push_back(count);
                }
                count = 0;
            }
            else
            {
                ++count;
            }
        }
        if (count != 0)
        {
            group.push_back(count);
        }
        return group;
    }

    int HotSprings::getBit(int number, int n) const
    {
        return (number >> n) & 1;
    }

    long long HotSprings::getCounts(const std::vector<std::pair<std::string, std::vector<int>>>& springs) const
    {
        long long counts = 0;
        int counter = 0;
        for (const auto& spring : springs)
        {
            std::cout << counter++ << "/" << springs.size() << std::endl;
            std::vector<size_t> unknownPositions;
            for (size_t i = 0; i < spring.first.size(); ++i)
            {
                if (spring.first[i] == '?')
                {
                    unknownPositions.push_back(i);
                }
            }
            int cases = static_cast<int>(std::pow(2, unknownPositions.size()));
            for (int i = 0; i < cases; ++i)
            {
                int bitset = i;
                std::string rowCopy = spring.first;
                for (int j = 0; j < static_cast<int>(unknownPositions.size()); ++j)
                {
                    if (getBit(bitset, j) == 1)
                    {
                        rowCopy[unknownPositions[j]] = '#';
                    }
                    else
                    {
                        rowCopy[unknownPositions[j]] = '.';
                    }
                }
                auto group = getGroup(rowCopy);
                if (group.size() == spring.second.size())
                {
                    bool sameGroup = true;
                    for (size_t k = 0; k < group.size(); ++k)
                    {
                        if (group[k] != spring.second[k])
                        {
                            sameGroup = false;
                        }
                    }

                    if (sameGroup)
                    {
                        ++counts;
                    }
                }
            }
        }
        return counts;
    }
}