#pragma once

#include "../../Common/Decorator/inc/PuzzleDecorator.h"

#include <vector>

namespace aoc2023
{
    class ParabolicReflectorDish : public PuzzleDecorator
    {
    public:
        ParabolicReflectorDish(std::unique_ptr<PuzzleComponent>&& puzzle);
        void printAnswers() override;

    protected:
        virtual void loadInput(const char* filename) override;
        virtual std::string getPart1() override;
        virtual std::string getPart2() override;

    private:
        void tiltNorth(std::vector<std::string>& platform) const;
        void tiltWest(std::vector<std::string>& platform) const;
        void tiltSouth(std::vector<std::string>& platform) const;
        void tiltEast(std::vector<std::string>& platform) const;
        void cycle(std::vector<std::string>& platform) const;
        bool areEqual(const std::vector<std::string>& p1, const std::vector<std::string>& p2) const;
        int getEqualState(const std::vector<std::vector<std::string>>& states,
            const std::vector<std::string>& platform) const;

        std::vector<std::string> platform;
    };
}