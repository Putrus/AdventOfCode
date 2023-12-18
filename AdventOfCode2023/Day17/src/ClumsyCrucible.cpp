#include "../inc/ClumsyCrucible.h"

#include <fstream>
#include <set>

namespace aoc2023
{
    ClumsyCrucible::ClumsyCrucible(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void ClumsyCrucible::printAnswers()
    {
        PuzzleDecorator::printAnswers(17, "Clumsy Crucible");
    }

    void ClumsyCrucible::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::vector<int> row;
            for (char c : line)
            {
                row.push_back(c - '0');
            }
            map.push_back(row);
        }
        file.close();
    }

    std::string ClumsyCrucible::getPart1()
    {
        std::vector<std::vector<int>> d;
        std::vector<std::vector<std::pair<int, int>>> p;
        std::set<std::pair<int, int>> Q;
        std::set<std::pair<int, int>> S;
        for (int i = 0; i < static_cast<int>(map.size()); ++i)
        {
            std::vector<int> rowD;
            std::vector<std::pair<int, int>> rowP;
            for (int j = 0; j < static_cast<int>(map[i].size()); ++j)
            {
                rowD.push_back(std::numeric_limits<int>::max());
                rowP.push_back({ -1, -1 });
                Q.insert({ i, j });
            }
            d.push_back(rowD);
            p.push_back(rowP);
        }

        S.insert(*Q.begin());
        Q.erase(std::make_pair<int, int>(0, 0));
        d[0][0] = map[0][0];
        while (!Q.empty())
        {
            
        }


        return std::to_string(0);
    }

    std::string ClumsyCrucible::getPart2()
    {
        return std::to_string(0);
    }
}