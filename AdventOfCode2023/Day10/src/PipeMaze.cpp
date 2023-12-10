#include "../inc/PipeMaze.h"

#include <fstream>
#include <stack>
#include <string>

namespace aoc2023
{
    PipeMaze::PipeMaze(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void PipeMaze::printAnswers()
    {
        PuzzleDecorator::printAnswers(10, "Pipe Maze");
    }

    void PipeMaze::loadInput(const char* filename)
    {
        std::fstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            maze.push_back(line);
            std::vector<Pipe3> bigLine;
            for (int i = 0; i < static_cast<int>(line.length()); ++i)
            {
                bigLine.push_back(Pipe3('.'));
                if (line[i] == 'S')
                {
                    startTile = { static_cast<int>(maze.size()) - 1, i, 0 };
                }
            }
            bigMaze.push_back(bigLine);
        }

        file.close();
    }

    std::string PipeMaze::getPart1()
    {
        std::vector<std::vector<int>> tiles(maze.size());
        for (auto& tilesRow : tiles)
        {
            for (size_t i = 0; i < maze[0].size(); ++i)
            {
                tilesRow.push_back(-1);
            }
        }

        std::queue<Tile> toVisit;
        toVisit.push(startTile);
        int farthest = 0;
        while (!toVisit.empty())
        {
            auto vTile = toVisit.front();
            toVisit.pop();
            if (tiles[vTile.x][vTile.y] != -1)
            {
                continue;
            }
            tiles[vTile.x][vTile.y] = vTile.steps;
            if (vTile.steps > farthest)
            {
                farthest = vTile.steps;
            }

            char pipe = maze[vTile.x][vTile.y];
            bigMaze[vTile.x][vTile.y] = Pipe3(pipe);
            if (pipe == 'S')
            {
                Pipe3& bigPipe = bigMaze[vTile.x][vTile.y];
                bigPipe.grid[1][1] = '*';
                if (checkNorth(toVisit, vTile))
                {
                    bigPipe.grid[0][1] = '*';
                }

                if (checkSouth(toVisit, vTile))
                {
                    bigPipe.grid[2][1] = '*';
                }
                
                if (checkWest(toVisit, vTile))
                {
                    bigPipe.grid[1][0] = '*';
                }

                if (checkEast(toVisit, vTile))
                {
                    bigPipe.grid[1][2] = '*';
                }
            }
            else if (pipe == '|')
            {
                checkNorth(toVisit, vTile);
                checkSouth(toVisit, vTile);
            }
            else if (pipe == '-')
            {
                checkWest(toVisit, vTile);
                checkEast(toVisit, vTile);
            }
            else if (pipe == 'L')
            {
                checkNorth(toVisit, vTile);
                checkEast(toVisit, vTile);
            }
            else if (pipe == 'J')
            {
                checkNorth(toVisit, vTile);
                checkWest(toVisit, vTile);
            }
            else if (pipe == '7')
            {
                checkSouth(toVisit, vTile);
                checkWest(toVisit, vTile);
            }
            else if (pipe == 'F')
            {
                checkSouth(toVisit, vTile);
                checkEast(toVisit, vTile);
            }
        }
        return std::to_string(farthest);
    }

    std::string PipeMaze::getPart2()
    {
        std::vector<std::string> helpMaze;
        for (const auto& line : bigMaze)
        {
            for (int i = 0; i < 3; ++i)
            {
                std::string helpLine;
                for (const auto& pipe : line)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        helpLine += pipe.grid[i][j];
                    }
                }
                helpMaze.push_back(helpLine);
            }
        }

        std::stack<std::pair<int, int>> toVisit;
        toVisit.push({ 0, 0 });
        while (!toVisit.empty())
        {
            auto currentPos = toVisit.top();
            toVisit.pop();
            helpMaze[currentPos.first][currentPos.second] = 'o';
            if (currentPos.first >= 1 &&
                helpMaze[currentPos.first - 1][currentPos.second] == '.')
            {
                toVisit.push({ currentPos.first - 1, currentPos.second });
            }

            if (currentPos.first < static_cast<int>(helpMaze.size()) - 1 &&
                helpMaze[currentPos.first + 1][currentPos.second] == '.')
            {
                toVisit.push({ currentPos.first + 1, currentPos.second });
            }

            if (currentPos.second >= 1 &&
                helpMaze[currentPos.first][currentPos.second - 1] == '.')
            {
                toVisit.push({ currentPos.first, currentPos.second - 1 });
            }

            if (currentPos.second < static_cast<int>(helpMaze[0].size()) - 1 &&
                helpMaze[currentPos.first][currentPos.second + 1] == '.')
            {
                toVisit.push({ currentPos.first, currentPos.second + 1 });
            }
        }

        int enclosed = 0;
        for (int i = 0; i < static_cast<int>(helpMaze.size()); i += 3)
        {
            for (int j = 0; j < static_cast<int>(helpMaze[i].size()); j += 3)
            {
                bool isEnclosed = true;
                for (int x = 0; x < 3; ++x)
                {
                    for (int y = 0; y < 3; ++y)
                    {
                        if (helpMaze[i + x][j + y] != '.')
                        {
                            isEnclosed = false;
                            break;
                        }
                    }
                }
                if (isEnclosed)
                {
                    ++enclosed;
                }
            }
        }

        return std::to_string(enclosed);
    }

    bool PipeMaze::checkNorth(std::queue<Tile>& toVisit, const Tile& vTile) const
    {
        if (vTile.x >= 1 &&
            (maze[vTile.x - 1][vTile.y] == '|' ||
            maze[vTile.x - 1][vTile.y] == 'F' ||
            maze[vTile.x - 1][vTile.y] == '7'))
        {
            toVisit.push({ vTile.x - 1, vTile.y, vTile.steps + 1 });
            return true;
        }
        return false;
    }

    bool PipeMaze::checkSouth(std::queue<Tile>& toVisit, const Tile& vTile) const
    {
        if (vTile.x <= static_cast<int>(maze.size()) - 1 &&
            (maze[vTile.x + 1][vTile.y] == '|' ||
            maze[vTile.x + 1][vTile.y] == 'L' ||
            maze[vTile.x + 1][vTile.y] == 'J'))
        {
            toVisit.push({ vTile.x + 1, vTile.y, vTile.steps + 1 });
            return true;
        }
        return false;
    }

    bool PipeMaze::checkWest(std::queue<Tile>& toVisit, const Tile& vTile) const
    {
        if (vTile.y >= 1 &&
            (maze[vTile.x][vTile.y - 1] == '-' ||
            maze[vTile.x][vTile.y - 1] == 'L' ||
            maze[vTile.x][vTile.y - 1] == 'F'))
        {
            toVisit.push({ vTile.x, vTile.y - 1, vTile.steps + 1 });
            return true;
        }
        return false;
    }

    bool PipeMaze::checkEast(std::queue<Tile>& toVisit, const Tile& vTile) const
    {
        if (vTile.y <= static_cast<int>(maze[0].size()) - 1 &&
            (maze[vTile.x][vTile.y + 1] == '-' ||
            maze[vTile.x][vTile.y + 1] == '7' ||
            maze[vTile.x][vTile.y + 1] == 'J'))
        {
            toVisit.push({ vTile.x, vTile.y + 1, vTile.steps + 1 });
            return true;
        }
        return false;
    }
}