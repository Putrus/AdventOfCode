#include "Common/Decorator/inc/Puzzles.h"

int main()
{
    aoc2023::Puzzles puzzles({ aoc2023::PuzzleName::Trebuchet,
        aoc2023::PuzzleName::CubeConundrum,
        aoc2023::PuzzleName::GearRatios
        });
    puzzles.printAnswers();
    return 0;
}