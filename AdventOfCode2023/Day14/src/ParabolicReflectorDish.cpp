#include "../inc/ParabolicReflectorDish.h"

#include <fstream>

namespace aoc2023
{
    ParabolicReflectorDish::ParabolicReflectorDish(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void ParabolicReflectorDish::printAnswers()
    {
        PuzzleDecorator::printAnswers(14, "Parabolic Reflector Dish");
    }

    void ParabolicReflectorDish::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            platform.push_back(line);
        }
        file.close();
    }

    std::string ParabolicReflectorDish::getPart1()
    {
        std::vector<std::string> p = platform;
        long long totalLoad = 0;
        for (int i = 0; i < static_cast<int>(p.size()); ++i)
        {
            for (int j = 0; j < static_cast<int>(p[i].size()); ++j)
            {
                if (p[i][j] == 'O')
                {
                    int newPos = i;
                    for (int k = i - 1; k >= 0; --k)
                    {
                        if (p[k][j] == '.')
                        {
                            newPos = k;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (newPos != i)
                    {
                        p[newPos][j] = 'O';
                        p[i][j] = '.';
                    }
                    totalLoad += (static_cast<long long>(p.size()) - newPos);
                }
            }
        }
        return std::to_string(totalLoad);
    }

    std::string ParabolicReflectorDish::getPart2()
    {
        std::vector<std::vector<std::string>> states;
        states.push_back(platform);

        std::vector<std::string> p = platform;
        int equalState = 0;
        for (int i = 0; i < 1000000000; ++i)
        {
            cycle(p);
            equalState = getEqualState(states, p);
            states.push_back(p);
            if (equalState != -1)
            {
                break;
            }
        }
        
        int cycleSize = (static_cast<int>(states.size()) - equalState - 1);
        int tiltsLeft = (1000000000 - states.size() + 1) % cycleSize;
        for (int i = 0; i < tiltsLeft; ++i)
        {
            cycle(p);
        }

        long long totalLoad = 0;
        for (size_t i = 0; i < p.size(); ++i)
        {
            for (size_t j = 0; j < p[i].size(); ++j)
            {
                if (p[i][j] == 'O')
                {
                    totalLoad += (static_cast<long long>(p.size()) - i);
                }
            }
        }

        return std::to_string(totalLoad);
    }

    void ParabolicReflectorDish::tiltNorth(std::vector<std::string>& platform) const
    {
        for (int i = 1; i < static_cast<int>(platform.size()); ++i)
        {
            for (int j = 0; j < static_cast<int>(platform[i].size()); ++j)
            {
                if (platform[i][j] == 'O')
                {
                    int newPos = i;
                    for (int k = i - 1; k >= 0; --k)
                    {
                        if (platform[k][j] == '.')
                        {
                            newPos = k;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (newPos != i)
                    {
                        platform[newPos][j] = 'O';
                        platform[i][j] = '.';
                    }
                }
            }
        }
    }

    void ParabolicReflectorDish::tiltWest(std::vector<std::string>& platform) const
    {
        for (int i = 0; i < static_cast<int>(platform.size()); ++i)
        {
            for (int j = 1; j < static_cast<int>(platform[i].size()); ++j)
            {
                if (platform[i][j] == 'O')
                {
                    int newPos = j;
                    for (int k = j - 1; k >= 0; --k)
                    {
                        if (platform[i][k] == '.')
                        {
                            newPos = k;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (newPos != j)
                    {
                        platform[i][newPos] = 'O';
                        platform[i][j] = '.';
                    }
                }
            }
        }
    }

    void ParabolicReflectorDish::tiltSouth(std::vector<std::string>& platform) const
    {
        for (int i = static_cast<int>(platform.size()) - 2; i >= 0; --i)
        {
            for (int j = 0; j < static_cast<int>(platform[i].size()); ++j)
            {
                if (platform[i][j] == 'O')
                {
                    int newPos = i;
                    for (int k = i + 1; k < static_cast<int>(platform.size()); ++k)
                    {
                        if (platform[k][j] == '.')
                        {
                            newPos = k;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (newPos != i)
                    {
                        platform[newPos][j] = 'O';
                        platform[i][j] = '.';
                    }
                }
            }
        }
    }

    void ParabolicReflectorDish::tiltEast(std::vector<std::string>& platform) const
    {
        for (int i = 0; i < static_cast<int>(platform.size()); ++i)
        {
            for (int j = static_cast<int>(platform[i].size()) - 2; j >= 0; --j)
            {
                if (platform[i][j] == 'O')
                {
                    int newPos = j;
                    for (int k = j + 1; k < static_cast<int>(platform.size()); ++k)
                    {
                        if (platform[i][k] == '.')
                        {
                            newPos = k;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (newPos != j)
                    {
                        platform[i][newPos] = 'O';
                        platform[i][j] = '.';
                    }
                }
            }
        }
    }

    void ParabolicReflectorDish::cycle(std::vector<std::string>& platform) const
    {
        tiltNorth(platform);
        tiltWest(platform);
        tiltSouth(platform);
        tiltEast(platform);
    }

    bool ParabolicReflectorDish::areEqual(const std::vector<std::string>& p1, const std::vector<std::string>& p2) const
    {
        if (p1.size() != p2.size())
        {
            return false;
        }

        for (size_t i = 0; i < p1.size(); ++i)
        {
            if (p1[i] != p2[i])
            {
                return false;
            }
        }
        return true;
    }

    int ParabolicReflectorDish::getEqualState(const std::vector<std::vector<std::string>>& states,
        const std::vector<std::string>& platform) const
    {
        for (int i = 0; i < static_cast<int>(states.size()); ++i)
        {
            if (areEqual(states[i], platform))
            {
                return i;
            }
        }

        return -1;
    }

}