#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>
#include <string>

struct HCAPosition
{
   int x;
   int y;
};

class HillClimbingAlgorithm final : public PuzzleDecorator
{
public:
   HillClimbingAlgorithm(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;
   int bfs(HCAPosition start_height_position);

private:
   std::vector<std::string> heightmap;
   HCAPosition start_position = {};
   HCAPosition goal_position = {};
};