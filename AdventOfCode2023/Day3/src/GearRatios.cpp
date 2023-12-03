#include "../inc/GearRatios.h"

#include <fstream>
#include <iostream>
#include <map>

namespace aoc2023
{
    GearRatios::GearRatios(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void GearRatios::printAnswers()
    {
        PuzzleDecorator::printAnswers(3, "Gear Ratios");
    }

    void GearRatios::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            schematic.push_back(line);
        }
        file.close();
    }

    std::string GearRatios::getPart1()
    {
        int result = 0;

        for (int i = 0; i < static_cast<int>(schematic.size()); ++i)
        {
            const std::string& line = schematic[i];
            std::string number;
            for (int j = 0; j < static_cast<int>(line.length()); ++j)
            {
                if (std::isdigit(line[j]))
                {
                    number += line[j];
                }
                else if (!number.empty())
                {
                    if (checkAdjacency(i, j - 1, number.length()))
                    {
                        result += std::stoi(number);
                    }
                    number = "";
                }
            }
            if (!number.empty())
            {
                if (checkAdjacency(i, schematic[i].length() - 1, number.length()))
                {
                    result += std::stoi(number);
                }
            }
        }
        return std::to_string(result);
    }

    std::string GearRatios::getPart2()
    {
        int result = 0;
        std::map<GearRatios::POINT, std::vector<int>> gear;

        for (int i = 0; i < static_cast<int>(schematic.size()); ++i)
        {
            const std::string& line = schematic[i];
            std::string number;
            for (int j = 0; j < static_cast<int>(line.length()); ++j)
            {
                if (std::isdigit(line[j]))
                {
                    number += line[j];
                }
                else if (!number.empty())
                {
                    auto pair = getAdjacency(i, j - 1, number.length());
                    if (pair.second == '*')
                    {
                        gear[pair.first].push_back(std::stoi(number));
                    }
                    number = "";
                }
            }
            if (!number.empty())
            {
                auto pair = getAdjacency(i, schematic[i].length() - 1, number.length());
                if (pair.second == '*')
                {
                    gear[pair.first].push_back(std::stoi(number));
                }
            }
        }

        return std::to_string(result);
    }

    bool GearRatios::checkAdjacency(int x, int y, size_t length)
    {
        for (int j = y + 1; j >= y - static_cast<int>(length); --j)
        {   
            if (checkSymbol(x - 1, j) ||
                checkSymbol(x + 1, j))
            {
                return true;
            }
        }

        if (checkSymbol(x, y + 1) ||
            checkSymbol(x, y - static_cast<int>(length)))
        {
            return true;
        }

        return false;
    }

    bool GearRatios::checkSymbol(int i, int j)
    {
        if (i < 0 || i >= static_cast<int>(schematic.size()) ||
            j < 0 || j >= static_cast<int>(schematic[i].length()))
        {
            return false;
        }
        return schematic[i][j] != '.' && !std::isdigit(schematic[i][j]);
    }

    std::pair<GearRatios::POINT, char> GearRatios::getAdjacency(int x, int y, size_t length)
    {
        for (int j = y + 1; j >= y - static_cast<int>(length); --j)
        {
            char s1 = getSymbol(x - 1, j);
            if (s1 != '.')
            {
                return { { x - 1, j }, s1 };
            }
            char s2 = getSymbol(x + 1, j);
            if (s2 != '.')
            {
                return { { x + 1, j }, s2 };
            }
        }

        char s1 = getSymbol(x, y + 1);
        if (s1 != '.')
        {
            return { { x, y + 1 }, s1 };
        }
        char s2 = getSymbol(x, y - static_cast<int>(length));
        if (s2 != '.')
        {
            return { { x, y - static_cast<int>(length) }, s1 };
        }

        return { { 0, 0 }, '.' };
    }

    char GearRatios::getSymbol(int i, int j)
    {
        if (i < 0 || i >= static_cast<int>(schematic.size()) ||
            j < 0 || j >= static_cast<int>(schematic[i].length()) ||
            std::isdigit(schematic[i][j]))
        {
            return '.';
        }
        return schematic[i][j];
    }
}