#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <queue>
#include <vector>

namespace aoc2023
{
    class PipeMaze : public PuzzleDecorator
    {
    public:
        PipeMaze(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        struct Tile
        {
            int x;
            int y;
            int steps;
        };

        struct Pipe3
        {
            Pipe3(char sign)
            {
                grid[1][1] = '*';
                if (sign == '|')
                {
                    grid[0][1] = '*';
                    grid[2][1] = '*';
                }
                else if (sign == '-')
                {
                    grid[1][0] = '*';
                    grid[1][2] = '*';
                }
                else if (sign == 'L')
                {
                    grid[0][1] = '*';
                    grid[1][2] = '*';
                }
                else if (sign == 'J')
                {
                    grid[0][1] = '*';
                    grid[1][0] = '*';
                }
                else if (sign == '7')
                {
                    grid[2][1] = '*';
                    grid[1][0] = '*';
                }
                else if (sign == 'F')
                {
                    grid[2][1] = '*';
                    grid[1][2] = '*';
                }
                else
                {
                    grid[1][1] = '.';
                }
            }

            char grid[3][3] = { { '.', '.', '.' }, { '.', '.', '.' }, { '.', '.', '.' } };
        };

        bool checkNorth(std::queue<Tile>& toVisit, const Tile& vTile) const;
        bool checkSouth(std::queue<Tile>& toVisit, const Tile& vTile) const;
        bool checkWest(std::queue<Tile>& toVisit, const Tile& vTile) const;
        bool checkEast(std::queue<Tile>& toVisit, const Tile& vTile) const;

        Tile startTile = { 0, 0 };
        std::vector<std::string> maze;
        std::vector<std::vector<Pipe3>> bigMaze;
    };
}