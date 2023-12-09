#include "../inc/MirageMaintenance.h"

#include <fstream>
#include <sstream>
#include <iostream>
namespace aoc2023
{
    MirageMaintenance::MirageMaintenance(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void MirageMaintenance::printAnswers()
    {
        PuzzleDecorator::printAnswers(9, "MirageMaintenance");
    }

    void MirageMaintenance::loadInput(const char* filename)
    {
        std::fstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::deque<long long> history;
            std::stringstream ss(line);
            long long value;
            while (!ss.eof())
            {
                ss >> value;
                history.push_back(value);
            }
            histories.push_back(history);
        }
        file.close();
    }

    std::string MirageMaintenance::getPart1()
    {
        long long sum = 0;
        for (const auto& history : histories)
        {
            sum += getExtrapolatedValue(history);
        }
        return std::to_string(sum);
    }

    std::string MirageMaintenance::getPart2()
    {
        long long sum = 0;
        for (const auto& history : histories)
        {
            sum += getExtrapolatedBackwardValue(history);
        }
        return std::to_string(sum);
    }

    long long MirageMaintenance::getExtrapolatedValue(const std::deque<long long>& sequence)
    {
        bool allZeros = true;
        for (const auto& value : sequence)
        {
            if (value != 0)
            {
                allZeros = false;
                break;
            }
        }
        if (allZeros)
        {
            return 0;
        }
        else
        {
            std::deque<long long> newSequence;
            for (size_t i = 1; i < sequence.size(); ++i)
            {
                newSequence.push_back(sequence[i] - sequence[i - 1]);
            }

            return sequence[sequence.size() - 1] + getExtrapolatedValue(newSequence);
        }
    }

    long long MirageMaintenance::getExtrapolatedBackwardValue(const std::deque<long long>& sequence)
    {
        bool allZeros = true;
        for (const auto& value : sequence)
        {
            if (value != 0)
            {
                allZeros = false;
                break;
            }
        }
        if (allZeros)
        {
            return 0;
        }
        else
        {
            std::deque<long long> newSequence;
            for (size_t i = sequence.size() - 1; i > 0; --i)
            {
                newSequence.push_front(sequence[i] - sequence[i - 1]);
            }

            return sequence[0] - getExtrapolatedBackwardValue(newSequence);
        }
    }
}