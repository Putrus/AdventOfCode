#include "Common/Decorator/inc/Puzzles.h"

int main()
{
    aoc2023::Puzzles puzzles({
        //aoc2023::PuzzleName::Trebuchet,
        //aoc2023::PuzzleName::CubeConundrum,
        //aoc2023::PuzzleName::GearRatios,
        //aoc2023::PuzzleName::Scratchcards,
        //aoc2023::PuzzleName::IfYouGiveASeedAFertilizer,
        //aoc2023::PuzzleName::WaitForIt,
        //aoc2023::PuzzleName::CamelCards,
        //aoc2023::PuzzleName::HauntedWasteland,
        //aoc2023::PuzzleName::MirageMaintenance,
        aoc2023::PuzzleName::PipeMaze
        });
    puzzles.printAnswers();
    return 0;
}