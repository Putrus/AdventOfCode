#include "../inc/CosmicExpansion.h"

#include <fstream>
#include <cstdlib>

namespace aoc2023
{
    CosmicExpansion::CosmicExpansion(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void CosmicExpansion::printAnswers()
    {
        PuzzleDecorator::printAnswers(11, "Cosmic Expansion");
    }

    void CosmicExpansion::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            image.push_back(line);
        }
        file.close();

        for (size_t j = 0; j < image[0].size(); ++j)
        {
            bool expandColumn = true;
            for (size_t i = 0; i < image.size(); ++i)
            {
                if (image[i][j] != '.')
                {
                    expandColumn = false;
                    break;
                }
            }

            if (expandColumn)
            {
                expandedColumns.push_back(j);
            }
        }

        for (size_t i = 0; i < image.size(); ++i)
        {
            std::string line;
            bool expandRow = true;
            for (size_t j = 0; j < image[i].size(); ++j)
            {
                if (image[i][j] != '.')
                {
                    expandRow = false;
                }
            }

            if (expandRow)
            {
                expandedRows.push_back(i);
            }
        }
    }

    std::string CosmicExpansion::getPart1()
    {
        return std::to_string(getShortestPaths(2));
    }

    std::string CosmicExpansion::getPart2()
    {
        return std::to_string(getShortestPaths(1000000));
    }

    long long CosmicExpansion::getShortestPaths(int expansion)
    {
        std::vector<std::pair<long long, long long>> galaxies;
        for (size_t i = 0; i < image.size(); ++i)
        {
            for (size_t j = 0; j < image[i].size(); ++j)
            {
                if (image[i][j] == '#')
                {
                    galaxies.push_back({ i, j });
                }
            }
        }

        long long shortestPaths = 0;
        for (size_t i = 0; i < galaxies.size(); ++i)
        {
            for (size_t j = i + 1; j < galaxies.size(); ++j)
            {
                long long firstGalaxyRow = galaxies[i].first;
                long long secondGalaxyRow = galaxies[j].first;
                for (size_t row : expandedRows)
                {
                    if (row > galaxies[i].first && row < galaxies[j].first)
                    {
                        secondGalaxyRow += expansion - 1;
                    }
                }

                long long firstGalaxyCol = galaxies[i].second;
                long long secondGalaxyCol = galaxies[j].second;
                for (size_t col : expandedColumns)
                {
                    if (galaxies[i].second < galaxies[j].second &&
                        col > galaxies[i].second && col < galaxies[j].second)
                    {
                        secondGalaxyCol += expansion - 1;
                    }
                    else if (galaxies[i].second > galaxies[j].second &&
                        col > galaxies[j].second && col < galaxies[i].second)
                    {
                        firstGalaxyCol += expansion - 1;
                    }
                }

                long long path = (std::abs(firstGalaxyRow - secondGalaxyRow) +
                    std::abs(firstGalaxyCol - secondGalaxyCol));
                shortestPaths += path;
            }
        }
        return shortestPaths;
    }
}