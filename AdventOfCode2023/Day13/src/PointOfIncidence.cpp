#include "../inc/PointOfIncidence.h"

namespace aoc2023
{
    PointOfIncidence::PointOfIncidence(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void PointOfIncidence::printAnswers()
    {
        PuzzleDecorator::printAnswers(13, "Point of Incidence");
    }

    void PointOfIncidence::loadInput(const char* filename)
    {
    }

    std::string PointOfIncidence::getPart1()
    {
        return std::to_string(0);
    }

    std::string PointOfIncidence::getPart2()
    {
        return std::to_string(0);
    }
}