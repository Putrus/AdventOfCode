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
#include "../../../Day12/inc/HotSprings.h"
#include "../../../Day13/inc/PointOfIncidence.h"
#include "../../../Day14/inc/ParabolicReflectorDish.h"
#include "../../../Day15/inc/LensLibrary.h"
#include "../../../Day16/inc/TheFloorWillBeLava.h"
#include "../../../Day17/inc/ClumsyCrucible.h"
#include "../../../Day18/inc/LavaductLagoon.h"

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
            case PuzzleName::HotSprings:
                mPuzzles = std::make_unique<HotSprings>(std::move(mPuzzles));
                break;
            case PuzzleName::PointOfIncidence:
               mPuzzles = std::make_unique<PointOfIncidence>(std::move(mPuzzles));
               break;
            case PuzzleName::ParabolicReflectorDish:
                mPuzzles = std::make_unique<ParabolicReflectorDish>(std::move(mPuzzles));
                break;
            case PuzzleName::LensLibrary:
                mPuzzles = std::make_unique<LensLibrary>(std::move(mPuzzles));
                break;
            case PuzzleName::TheFloorWillBeLava:
                mPuzzles = std::make_unique<TheFloorWillBeLava>(std::move(mPuzzles));
                break;
            case PuzzleName::ClumsyCrucible:
                mPuzzles = std::make_unique<ClumsyCrucible>(std::move(mPuzzles));
                break;
            case PuzzleName::LavaductLagoon:
                mPuzzles = std::make_unique<LavaductLagoon>(std::move(mPuzzles));
                break;
            }
        }
    }

    void Puzzles::printAnswers()
    {
        mPuzzles->printAnswers();
    }
}