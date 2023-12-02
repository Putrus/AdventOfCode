#include "../inc/CubeConundrum.h"

#include <fstream>
#include <sstream>

namespace aoc2023
{
    CubeConundrum::CubeConundrum(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void CubeConundrum::printAnswers()
    {
        PuzzleDecorator::printAnswers(2, "Cube Conundrum");
    }

    void CubeConundrum::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string tmp;
        std::string color;
        int amount;
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream ss(line);
            ss >> tmp >> tmp;
            std::vector<Cubes> cubes;
            Cubes set;
            while (!ss.eof())
            {
                ss >> amount;
                ss >> color;
                if (color.empty())
                {
                    break;
                }

                char last = color[color.length() - 1];
                if (last == ',' || last == ';')
                {
                    color = color.substr(0, color.length() - 1);
                }

                if (color == "red")
                {
                    set.red += amount;
                }
                else if (color == "green")
                {
                    set.green += amount;
                }
                else if (color == "blue")
                {
                    set.blue += amount;
                }
                else
                {
                    throw std::runtime_error("Wrong color!");
                }

                if (last != ',')
                {
                    cubes.push_back(set);
                    set = { 0, 0, 0 };
                }
            }
            games.push_back(cubes);
        }
        file.close();
    }

    std::string CubeConundrum::getPart1()
    {
        int result = 0;
        for (size_t i = 0 ; i < games.size(); ++i)
        {
            bool valid = true;
            for (const auto& cubes : games[i])
            {
                if (cubes.red > 12 || cubes.green > 13 || cubes.blue > 14)
                {
                    valid = false;
                    break;
                } 
            }
            if (valid)
            {
                result += i + 1;
            }
        }
        return std::to_string(result);
    }

    std::string CubeConundrum::getPart2()
    {
        int result = 0;
        for (size_t i = 0; i < games.size(); ++i)
        {
            Cubes minimum;
            for (const auto& cubes : games[i])
            {
                if (cubes.red > minimum.red)
                {
                    minimum.red = cubes.red;
                }

                if (cubes.green > minimum.green)
                {
                    minimum.green = cubes.green;
                }

                if (cubes.blue > minimum.blue)
                {
                    minimum.blue = cubes.blue;
                }
            }
            result += minimum.red * minimum.green * minimum.blue;
        }
        return std::to_string(result);
    }
}