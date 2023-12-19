#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    struct HeatPoint
    {
        int x;
        int y;

        bool operator==(const HeatPoint& other) const
        {
            return x == other.x && y == other.y;
        }

        HeatPoint& operator+=(const HeatPoint& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }
    };

    HeatPoint operator+(const HeatPoint& lhs, const HeatPoint& rhs);

    struct HeatPointHash
    {
        size_t operator()(const HeatPoint& point) const
        {
            return std::hash<int>()(point.x) ^ std::hash<int>()(point.y);
        }
    };

    struct HeatMap
    {
        std::vector<std::vector<int>> map;

        int getLoss(const HeatPoint& position) const
        {
            return map[position.x][position.y];
        }

        bool inBorders(const HeatPoint& position) const
        {
            return position.x >= 0 && position.x < static_cast<int>(map.size()) &&
                position.y >= 0 && position.y < static_cast<int>(map[position.x].size());
        }
    };

    struct Move
    {
        HeatPoint position;
        HeatPoint direction;
        int loss;
        int straight = 0;

        bool operator==(const Move& other) const
        {
            return position == other.position && direction == other.direction && straight == other.straight;
        }

        bool operator<(const Move& other) const
        {
            return loss > other.loss;
        }
    };

    struct MoveHash
    {
        size_t operator()(const Move& move) const
        {
            size_t seed = 0;
            seed ^= HeatPointHash()(move.position) + 0x933779b9 + (seed << 6) + (seed >> 2);
            seed ^= HeatPointHash()(move.direction) + 0x933779b9 + (seed << 6) + (seed >> 2);
            seed ^= std::hash<int>()(move.straight) + 0x933779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

    class ClumsyCrucible : public PuzzleDecorator
    {
    public:
        ClumsyCrucible(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        HeatPoint rotateLeft(const HeatPoint& direction);
        HeatPoint rotateRight(const HeatPoint& direction);

        HeatMap heatMap;
    };
}