#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>
#include <string>

enum class Direction
{
   Left = 0,
   Right,
   Up,
   Down
};

class TreetopTreeHouse final : public PuzzleDecorator
{
public:
   TreetopTreeHouse(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;
   bool checkVisibleHorizontal(size_t x, size_t y, size_t start, size_t end);
   bool checkVisibleVertical(size_t x, size_t y, size_t start, size_t end);
   size_t calcScenicScore(size_t x, size_t y);
   size_t getTreesCanSee(int y, int x, Direction direction);

private:
   std::vector<std::string> grid;
};
