#include "../inc/TheFloorWillBeLava.h"

#include <fstream>

namespace aoc2023
{
    TheFloorWillBeLava::TheFloorWillBeLava(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void TheFloorWillBeLava::printAnswers()
    {
        PuzzleDecorator::printAnswers(16, "The Floor Will Be Lava");
    }

    void TheFloorWillBeLava::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            contraption.push_back(line);
        }

        for (size_t i = 0; i < contraption.size(); ++i)
        {
            std::string row;
            for (size_t j = 0; j < contraption[i].size(); ++j)
            {
                row += '.';
            }
            energized.push_back(row);
        }
        file.close();
    }

    std::string TheFloorWillBeLava::getPart1()
    {
        std::vector<std::string> c;

        energize({ 0, 0, 1, 0 });
        return std::to_string(result);
    }

    std::string TheFloorWillBeLava::getPart2()
    {
        long long max = 0;
        for (int i = 0; i < static_cast<int>(contraption.size()); ++i)
        {
            energize({ 0, i, 1, 0 });
            if (result > max)
            {
                max = result;
            }
            energizedReset();
            energize({ static_cast<int>(contraption[i].size()) - 1, i, -1, 0 });
            if (result > max)
            {
                max = result;
            }
            energizedReset();
        }

        for (int j = 0; j < static_cast<int>(contraption[0].size()); ++j)
        {
            energize({ j, 0, 0, 1 });
            if (result > max)
            {
                max = result;
            }
            energizedReset();
            energize({ j, static_cast<int>(contraption.size()) - 1, 0, -1 });
            if (result > max)
            {
                max = result;
            }
            energizedReset();
        }
        return std::to_string(max);
    }

    void TheFloorWillBeLava::energize(Beam beam)
    {
        while (beam.x >= 0 && beam.x < energized[0].size() &&
            beam.y >= 0 && beam.y < energized.size() &&
            std::find_if(beamHistory.begin(), beamHistory.end(), [beam](const auto& beamH)
                {
                    return beamH.x == beam.x && beamH.y == beam.y &&
                        beamH.dx == beam.dx && beamH.dy == beam.dy;
                }) == beamHistory.end())
        {
            if (energized[beam.y][beam.x] != '#')
            {
                ++result;
            }
            energized[beam.y][beam.x] = '#';
            
            beamHistory.push_back(beam);
            if (beam.dx == 1)
            {
                if (contraption[beam.y][beam.x] == '|')
                {
                    energize({ beam.x, beam.y + 1, 0, 1 });
                    energize({ beam.x, beam.y - 1, 0, -1 });
                    return;
                }
                else if (contraption[beam.y][beam.x] == '/')
                {
                    beam.dx = 0;
                    beam.dy = -1;
                }
                else if (contraption[beam.y][beam.x] == '\\')
                {
                    beam.dx = 0;
                    beam.dy = 1;
                }
            }
            else if (beam.dx == -1)
            {
                if (contraption[beam.y][beam.x] == '|')
                {
                    energize({ beam.x, beam.y + 1, 0, 1 });
                    energize({ beam.x, beam.y - 1, 0, -1 });
                    return;
                }
                else if (contraption[beam.y][beam.x] == '/')
                {
                    beam.dx = 0;
                    beam.dy = 1;
                }
                else if (contraption[beam.y][beam.x] == '\\')
                {
                    beam.dx = 0;
                    beam.dy = -1;
                }
            }
            else if (beam.dy == 1)
            {
                if (contraption[beam.y][beam.x] == '-')
                {
                    energize({ beam.x + 1, beam.y, 1, 0 });
                    energize({ beam.x - 1, beam.y, -1, 0 });
                    return;
                }
                else if (contraption[beam.y][beam.x] == '/')
                {
                    beam.dx = -1;
                    beam.dy = 0;
                }
                else if (contraption[beam.y][beam.x] == '\\')
                {
                    beam.dx = 1;
                    beam.dy = 0;
                }
            }
            else if (beam.dy == -1)
            {
                if (contraption[beam.y][beam.x] == '-')
                {
                    energize({ beam.x + 1, beam.y, 1, 0 });
                    energize({ beam.x - 1, beam.y, -1, 0 });
                    return;
                }
                else if (contraption[beam.y][beam.x] == '/')
                {
                    beam.dx = 1;
                    beam.dy = 0;
                }
                else if (contraption[beam.y][beam.x] == '\\')
                {
                    beam.dx = -1;
                    beam.dy = 0;
                }
            }
            beam.x += beam.dx;
            beam.y += beam.dy;
        }
    }

    void TheFloorWillBeLava::energizedReset()
    {
        result = 0;
        beamHistory.clear();
        for (size_t i = 0; i < energized.size(); ++i)
        {
            for (size_t j = 0; j < energized[i].size(); ++j)
            {
                energized[i][j] = '.';
            }
        }
    }
}