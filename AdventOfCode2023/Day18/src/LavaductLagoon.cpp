#include "../inc/LavaductLagoon.h"

#include <fstream>
#include <iostream>
#include <stack>

namespace aoc2023
{
    LavaductLagoon::LavaductLagoon(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void LavaductLagoon::printAnswers()
    {
        PuzzleDecorator::printAnswers(18, "Lavaduct Lagoon");
    }

    void LavaductLagoon::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        while (!file.eof())
        {
            Dig dig;
            file >> dig.direction >> dig.meters;
            std::string color;
            file >> color;
            Dig dig2;
            dig2.meters = hexToInt(color.substr(2, 5));

            if (color[7] == '0')
            {
                dig2.direction = 'R';
            }
            else if (color[7] == '1')
            {
                dig2.direction = 'D';
            }
            else if (color[7] = '2')
            {
                dig2.direction = 'L';
            }
            else if (color[7] == '3')
            {
                dig2.direction = 'U';
            }
            else
            {
                std::cerr << "Something wrong with dig direction" << std::endl;
            }
            
            digs.push_back(dig);
            digs2.push_back(dig2);
        }
        file.close();
    }

    std::string LavaductLagoon::getPart1()
    {
        std::pair<int, int> currentPos = { 0, 0 };
        int maxRow = 0;
        int minRow = 0;
        int maxCol = 0;
        int minCol = 0;
        for (const auto& dig : digs)
        {
            if (dig.direction == 'R')
            {
                currentPos.second += dig.meters;
            }
            else if (dig.direction == 'L')
            {
                currentPos.second -= dig.meters;
            }
            else if (dig.direction == 'D')
            {
                currentPos.first += dig.meters;
            }
            else
            {
                currentPos.first -= dig.meters;
            }

            maxRow = std::max(maxRow, currentPos.first);
            minRow = std::min(minRow, currentPos.first);
            maxCol = std::max(maxCol, currentPos.second);
            minCol = std::min(minCol, currentPos.second);
        }

        std::vector<std::string> terrain;
        for (int i = minRow - 1; i < maxRow + 2; ++i)
        {
            std::string row;
            for (int j = minCol - 1; j < maxCol + 2; ++j)
            {
                row += '.';
            }
            terrain.push_back(row);
        }

        currentPos = { 1 - minRow, 1 - minCol };
        for (const auto& dig : digs)
        {
            if (dig.direction == 'R')
            {
                for (int i = 0; i < dig.meters; ++i)
                {
                    terrain[currentPos.first][currentPos.second] = '#';
                    ++currentPos.second;
                }
            }
            else if (dig.direction == 'L')
            {
                for (int i = 0; i < dig.meters; ++i)
                {
                    terrain[currentPos.first][currentPos.second] = '#';
                    --currentPos.second;
                }
            }
            else if (dig.direction == 'D')
            {
                for (int i = 0; i < dig.meters; ++i)
                {
                    terrain[currentPos.first][currentPos.second] = '#';
                    ++currentPos.first;
                }
            }
            else
            {
                for (int i = 0; i < dig.meters; ++i)
                {
                    terrain[currentPos.first][currentPos.second] = '#';
                    --currentPos.first;
                }
            }
        }

        std::stack<std::pair<int, int>> stack;
        stack.push({ 0, 0 });
        while (!stack.empty())
        {
            auto cell = stack.top();
            stack.pop();
            terrain[cell.first][cell.second] = '*';
            if (cell.first > 0 &&
                terrain[cell.first - 1][cell.second] != '#' &&
                terrain[cell.first - 1][cell.second] != '*')
            {
                stack.push({ cell.first - 1, cell.second });
            }

            if (cell.first < static_cast<int>(terrain.size()) - 1 &&
                terrain[cell.first + 1][cell.second] != '#' &&
                terrain[cell.first + 1][cell.second] != '*')
            {
                stack.push({ cell.first + 1, cell.second });
            }

            if (cell.second > 0 &&
                terrain[cell.first][cell.second - 1] != '#' &&
                terrain[cell.first][cell.second - 1] != '*')
            {
                stack.push({ cell.first, cell.second - 1 });
            }

            if (cell.second < static_cast<int>(terrain[cell.first].size()) - 1 &&
                terrain[cell.first][cell.second + 1] != '#' &&
                terrain[cell.first][cell.second + 1] != '*')
            {
                stack.push({ cell.first, cell.second + 1 });
            }
        }

        long long result = 0;
        for (const auto& row : terrain)
        {
            for (char c : row)
            {
                if (c == '.' || c == '#')
                {
                    ++result;
                }
            }
        }

        return std::to_string(result);
    }

    std::string LavaductLagoon::getPart2()
    {
  
        return std::to_string(0);
    }

    int LavaductLagoon::hexToInt(const std::string& hex) const
    {
        int result = 0;
        for (int i = 0; i < static_cast<int>(hex.size()); ++i)
        {
            int power = std::pow(16, static_cast<int>(hex.size()) - i - 1);
            if (hex[i] >= 'a')
            {
                result += power * (hex[i] - 'a' + 10);
            }
            else
            {
                result += power * (hex[i] - '0');
            }
        }

        return result;
    }
}