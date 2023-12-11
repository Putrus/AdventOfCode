#include "../inc/Puzzles.h"

#include "../inc/PuzzleEmpty.h"

#include "../../../Day1/inc/Trebuchet.h"
#include "../../../Day2/inc/CubeConundrum.h"
#include "../../../Day3/inc/GearRatios.h"
#include "../../../Day4/inc/Scratchcards.h"
#include "../../../Day5/inc/IfYouGiveASeedAFertilizer.h"
#include "../../../Day6/inc/WaitForIt.h"
#include "../../../Day7/inc/CamelCards.h"
#include "../../../Day8/inc/HauntedWasteland.h"
#include "../../../Day9/inc/MirageMaintenance.h"
#include "../../../Day10/inc/PipeMaze.h"
#include "../../../Day11/inc/CosmicExpansion.h"

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
            case PuzzleName::GearRatios:
                mPuzzles = std::make_unique<GearRatios>(std::move(mPuzzles));
                break;
            case PuzzleName::Scratchcards:
                mPuzzles = std::make_unique<Scratchcards>(std::move(mPuzzles));
                break;
            case PuzzleName::IfYouGiveASeedAFertilizer:
                mPuzzles = std::make_unique<IfYouGiveASeedAFertilizer>(std::move(mPuzzles));
                break;
            case PuzzleName::WaitForIt:
                mPuzzles = std::make_unique<WaitForIt>(std::move(mPuzzles));
                break;
            case PuzzleName::CamelCards:
                mPuzzles = std::make_unique<CamelCards>(std::move(mPuzzles));
                break;
            case PuzzleName::HauntedWasteland :
                mPuzzles = std::make_unique<HauntedWasteland>(std::move(mPuzzles));
                break;
            case PuzzleName::MirageMaintenance:
                mPuzzles = std::make_unique<MirageMaintenance>(std::move(mPuzzles));
                break;
            case PuzzleName::PipeMaze:
                mPuzzles = std::make_unique<PipeMaze>(std::move(mPuzzles));
                break;
            case PuzzleName::CosmicExpansion:
                mPuzzles = std::make_unique<CosmicExpansion>(std::move(mPuzzles));
                break;
            }
        }
    }

    void Puzzles::printAnswers()
    {
        mPuzzles->printAnswers();
    }
}