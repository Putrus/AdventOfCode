#include "../inc/PuzzleDecorator.h"

#include <iostream>

namespace aoc2023
{
    PuzzleDecorator::PuzzleDecorator(std::unique_ptr<PuzzleComponent>&& puzzle)
        : mPuzzle(std::move(puzzle))
    {
    }

    void PuzzleDecorator::printAnswers(int day, const std::string& puzzleName)
    {
        std::cout << "--- Day " << day << ": " << puzzleName << " ---" << std::endl;
        loadInput(("Day" + std::to_string(day) + "/res/" + "day" + std::to_string(day) + "input.txt").c_str());

        std::cout << "Part 1: " << getPart1() << std::endl;
        std::cout << "Part 2: " << getPart2() << std::endl;

        mPuzzle->printAnswers();
    }
}