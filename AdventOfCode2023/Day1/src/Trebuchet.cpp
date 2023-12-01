#include "../inc/Trebuchet.h"

#include <string>
#include <vector>

namespace aoc2023
{
    Trebuchet::Trebuchet(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void Trebuchet::printAnswers()
    {
        PuzzleDecorator::printAnswers(1, "Trebuchet?!");
    }

    void Trebuchet::loadInput(const char* filename)
    {
        mFile = std::ifstream(filename);
    }

    std::string Trebuchet::getPart1()
    {
        std::string line;
        int first = -1;
        int last = -1;
        int sum = 0;
        while (std::getline(mFile, line))
        {
            for (char c : line)
            {
                if (first == -1 && std::isdigit(c))
                {
                    first = c - '0';
                    last = c - '0';
                }
                else if (std::isdigit(c))
                {
                    last = c - '0';
                }
            }
            sum += first * 10 + last;
            first = -1;
            last = -1;
        }
        mFile.clear();
        mFile.seekg(0, std::ios::beg);
        return std::to_string(sum);
    }

    std::string Trebuchet::getPart2()
    {
        std::string line;
        int first = -1;
        int last = -1;
        int sum = 0;
        std::vector<std::string> digits = { "zero", "one", "two", "three", "four",
            "five", "six", "seven", "eight", "nine" };
        while (std::getline(mFile, line))
        {
            for (size_t i = 0; i < line.size(); ++i)
            {
                if (first == -1)
                {
                    if (std::isdigit(line[i]))
                    {
                        first = line[i] - '0';
                        last = first;
                        continue;
                    }
                    for (size_t j = 1; j < digits.size(); ++j)
                    {
                        std::string substr = line.substr(i, digits[j].length());
                        if (substr == digits[j])
                        {
                            first = j;
                            last = first;
                        }
                    }
                }
                else
                {
                    if (std::isdigit(line[i]))
                    {
                        last = line[i] - '0';
                        continue;
                    }
                    for (size_t j = 1; j < digits.size(); ++j)
                    {
                        std::string substr = line.substr(i, digits[j].length());
                        if (substr == digits[j])
                        {
                            last = j;
                        }
                    }
                }
            }
            sum += first * 10 + last;
            first = -1;
            last = -1;
        }
        mFile.clear();
        mFile.seekg(0, std::ios::beg);
        return std::to_string(sum);
    }
}