#include "../inc/Puzzles.h"

#include "../inc/PuzzleEmpty.h"

#include "../../../Day2/inc/CubeConundrum.h"
#include "../../../Day1/inc/Trebuchet.h"

namespace aoc2023
{
    Puzzles::Puzzles(const std::vector<PuzzleName>& puzzleNames)
    {
        mPuzzles = std::make_unique<PuzzleEmpty>();
        for (auto const& puzzle_name : puzzleNames)
        {
            switch (puzzle_name)
            {
            case PuzzleName::Trebuchet:
                mPuzzles = std::make_unique<Trebuchet>(std::move(mPuzzles));
                break;
            case PuzzleName::CubeConundrum:
                mPuzzles = std::make_unique<CubeConundrum>(std::move(mPuzzles));
                break;
            }
        }
    }

    void Puzzles::printAnswers()
    {
        mPuzzles->printAnswers();
    }
}