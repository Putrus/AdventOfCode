#pragma once

#include "PuzzleComponent.h"

#include <memory>
#include <vector>

namespace aoc2023
{
    enum class PuzzleName
    {
        Trebuchet = 0,
        CubeConundrum,
        GearRatios,
        Scratchcards,
        IfYouGiveASeedAFertilizer,
        WaitForIt,
        CamelCards,
        HauntedWasteland,
        MirageMaintenance,
        PipeMaze,
        CosmicExpansion,
        HotSprings,
        PointOfIncidence,
        ParabolicReflectorDish,
        LensLibrary,
        TheFloorWillBeLava,
        ClumsyCrucible,
        LavaductLagoon
    };

    class Puzzles final
    {
    public:
        Puzzles(const std::vector<PuzzleName>& puzzleNames);
        void printAnswers();

    private:
        std::unique_ptr<PuzzleComponent> mPuzzles;
    };
}