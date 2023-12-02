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
                if (last != ',' && last != ';')
                {
                    break;
                }

                color = color.substr(0, color.length() - 1);
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

                if (last == ';')
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
        return std::string();
    }

    std::string CubeConundrum::getPart2()
    {
        return std::string();
    }
}