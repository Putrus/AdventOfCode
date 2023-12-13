#include "../inc/PointOfIncidence.h"

#include <fstream>

#include <iostream>

namespace aoc2023
{
    PointOfIncidence::PointOfIncidence(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void PointOfIncidence::printAnswers()
    {
        PuzzleDecorator::printAnswers(13, "Point of Incidence");
    }

    void PointOfIncidence::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        std::vector<std::string> pattern;
        while (std::getline(file, line))
        {
            if (line.empty())
            {
                patterns.push_back(pattern);
                pattern.clear();
            }
            else
            {
                pattern.push_back(line);
            }
        }
        patterns.push_back(pattern);
        file.close();
    }

    std::string PointOfIncidence::getPart1()
    {
        int sum = 0;
        for (const auto& pattern : patterns)
        {
            int horizontalReflection = getHorizontalReflection(pattern);
            if (horizontalReflection != -1)
            {
                sum += (horizontalReflection + 1) * 100;
                continue;
            }

            int verticalReflection = getVerticalReflection(pattern);
            if (verticalReflection == -1)
            {
                std::cerr << "Something wrong, vertical reflection shouldn't be -1" << std::endl;
            }
            sum += verticalReflection + 1;
        }
        return std::to_string(sum);
    }

    std::string PointOfIncidence::getPart2()
    {
        int sum = 0;
        for (const auto& pattern : patterns)
        {
            int horizontalReflection = getSmudgeHorizontalReflection(pattern);
            if (horizontalReflection != -1)
            {
                sum += (horizontalReflection + 1) * 100;
                continue;
            }

            int verticalReflection = getSmudgeVerticalReflection(pattern);
            if (verticalReflection == -1)
            {
                std::cerr << "Something wrong, vertical reflection shouldn't be -1" << std::endl;
            }
            sum += verticalReflection + 1;
        }
        return std::to_string(sum);
    }

    int PointOfIncidence::getHorizontalReflection(const std::vector<std::string>& pattern) const
    {
        for (int i = 0; i < static_cast<int>(pattern.size()) - 1; ++i)
        {
            int l = i;
            int r = i + 1;
            bool isPerfectReflection = true;
            while (l > -1 && r < static_cast<int>(pattern.size()))
            {
                if (pattern[l] != pattern[r])
                {
                    isPerfectReflection = false;
                    break;
                }
                --l;
                ++r;
            }
            if (isPerfectReflection)
            {
                return i;
            }
        }

        return -1;
    }

    int PointOfIncidence::getVerticalReflection(const std::vector<std::string>& pattern) const
    {
        return getHorizontalReflection(getTransposePattern(pattern));
    }

    std::vector<std::string> PointOfIncidence::getTransposePattern(const std::vector<std::string>& pattern) const
    {
        std::vector<std::string> transposePattern;
        for (size_t j = 0; j < pattern[0].size(); ++j)
        {
            std::string row;
            for (size_t i = 0; i < pattern.size(); ++i)
            {
                row += pattern[i][j];
            }
            transposePattern.push_back(row);
        }
        return transposePattern;
    }

    int PointOfIncidence::getSmudgeHorizontalReflection(const std::vector<std::string>& pattern) const
    {
        for (int i = 0; i < static_cast<int>(pattern.size()) - 1; ++i)
        {
            int l = i;
            int r = i + 1;
            bool isPerfectReflection = true;
            int smudges = 0;
            while (l > -1 && r < static_cast<int>(pattern.size()))
            {
                for (size_t j = 0; j < pattern[l].size(); ++j)
                {
                    if (pattern[l][j] != pattern[r][j])
                    {
                        ++smudges;
                        if (smudges > 1)
                        {
                            isPerfectReflection = false;
                            break;
                        }
                    }
                }
                if (smudges > 1)
                {
                    isPerfectReflection = false;
                    break;
                }
                --l;
                ++r;
            }
            if (smudges == 1 && isPerfectReflection)
            {
                return i;
            }
        }

        return -1;
    }

    int PointOfIncidence::getSmudgeVerticalReflection(const std::vector<std::string>& pattern) const
    {
        return getSmudgeHorizontalReflection(getTransposePattern(pattern));
    }
}