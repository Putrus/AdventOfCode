#include "../inc/ClumsyCrucible.h"

#include <fstream>
#include <unordered_set>
#include <queue>

namespace aoc2023
{
    HeatPoint operator+(const HeatPoint& lhs, const HeatPoint& rhs)
    {
        return { lhs.x + rhs.x, lhs.y + rhs.y };
    }

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
            heatMap.map.push_back(row);
        }
        file.close();
    }

    std::string ClumsyCrucible::getPart1()
    {
        std::unordered_set<Move, MoveHash> S;
        std::priority_queue<Move> Q;
        int bestLoss = 0;
   
        HeatPoint destination = { static_cast<int>(heatMap.map.size()) - 1,
            static_cast<int>(heatMap.map[heatMap.map.size() - 1].size()) - 1 };
        Q.push({ { 0, 0 }, { 0, 1 }, 0, 0 });
        Q.push({ { 0, 0 }, { 1, 0 }, 0, 0 });
        while (!Q.empty())
        {
            Move currentMove = Q.top();
            Q.pop();

            if (S.count(currentMove))
            {
                continue;
            }

            if (currentMove.position == destination)  
            {
                bestLoss = currentMove.loss;
                break;
            }

            S.insert(currentMove);

            Move leftMove;
            leftMove.direction = rotateLeft(currentMove.direction);
            leftMove.position = currentMove.position + leftMove.direction;
            if (heatMap.inBorders(leftMove.position))
            {
                leftMove.loss = currentMove.loss + heatMap.getLoss(leftMove.position);
                Q.push(leftMove);
            }

            Move rightMove;
            rightMove.direction = rotateRight(currentMove.direction);
            rightMove.position = currentMove.position + rightMove.direction;
            if (heatMap.inBorders(rightMove.position))
            {
                rightMove.loss = currentMove.loss + heatMap.getLoss(rightMove.position);
                Q.push(rightMove);
            }

            if (currentMove.straight < 2)
            {
                Move straightMove;
                straightMove.direction = currentMove.direction;
                straightMove.position = currentMove.position + straightMove.direction;
                if (heatMap.inBorders(straightMove.position))
                {
                    straightMove.loss = currentMove.loss + heatMap.getLoss(straightMove.position);
                    straightMove.straight = currentMove.straight + 1;
                    Q.push(straightMove);
                }
            }
        }

        return std::to_string(bestLoss);
    }

    std::string ClumsyCrucible::getPart2()
    {
        std::unordered_set<Move, MoveHash> S;
        std::priority_queue<Move> Q;
        int bestLoss = 0;

        HeatPoint destination = { static_cast<int>(heatMap.map.size()) - 1,
            static_cast<int>(heatMap.map[heatMap.map.size() - 1].size()) - 1 };
        Q.push({ { 0, 0 }, { 0, 1 }, 0, 0 });
        Q.push({ { 0, 0 }, { 1, 0 }, 0, 0 });
        while (!Q.empty())
        {
            Move currentMove = Q.top();
            Q.pop();

            if (S.count(currentMove))
            {
                continue;
            }

            if (currentMove.position == destination)
            {
                bestLoss = currentMove.loss;
                break;
            }

            S.insert(currentMove);

            if (currentMove.straight >= 3)
            {
                Move leftMove;
                leftMove.direction = rotateLeft(currentMove.direction);
                leftMove.position = currentMove.position + leftMove.direction;
                if (heatMap.inBorders(leftMove.position))
                {
                    leftMove.loss = currentMove.loss + heatMap.getLoss(leftMove.position);
                    Q.push(leftMove);
                }

                Move rightMove;
                rightMove.direction = rotateRight(currentMove.direction);
                rightMove.position = currentMove.position + rightMove.direction;
                if (heatMap.inBorders(rightMove.position))
                {
                    rightMove.loss = currentMove.loss + heatMap.getLoss(rightMove.position);
                    Q.push(rightMove);
                }
            }

            if (currentMove.straight < 9)
            {
                Move straightMove;
                straightMove.direction = currentMove.direction;
                straightMove.position = currentMove.position + straightMove.direction;
                if (heatMap.inBorders(straightMove.position))
                {
                    straightMove.loss = currentMove.loss + heatMap.getLoss(straightMove.position);
                    straightMove.straight = currentMove.straight + 1;
                    Q.push(straightMove);
                }
            }
        }

        return std::to_string(bestLoss);
    }

    HeatPoint ClumsyCrucible::rotateLeft(const HeatPoint& direction)
    {
        return { direction.y, -direction.x };
    }

    HeatPoint ClumsyCrucible::rotateRight(const HeatPoint& direction)
    {
        return { -direction.y, direction.x };
    }
}