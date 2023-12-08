#include "../inc/HauntedWasteland.h"

#include <fstream>
#include <iostream>

namespace aoc2023
{
    HauntedWasteland::HauntedWasteland(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void HauntedWasteland::printAnswers()
    {
        PuzzleDecorator::printAnswers(8, "Haunted Wasteland");
    }

    void HauntedWasteland::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }
        file >> instruction;

        std::string node;
        std::string tmp;
        std::string left;
        std::string right;
        while (!file.eof())
        {
            file >> node >> tmp >> left >> right;
            left = left.substr(1, left.length() - 2);
            right = right.substr(0, right.length() - 1);
            network.insert({ node, { left, right } });
            if (node.back() == 'A')
            {
                startNodes.push_back(node);
            }
        }
        file.close();
    }

    std::string HauntedWasteland::getPart1()
    {
        int steps = 0;
        std::string currentNode = "AAA";
        while (currentNode != "ZZZ")
        {
            for (char c : instruction)
            {
                if (c == 'L')
                {
                    currentNode = network[currentNode].first;
                }
                else
                {
                    currentNode = network[currentNode].second;
                }
                ++steps;
            }
        }
        
        return std::to_string(steps);
    }

    std::string HauntedWasteland::getPart2()
    {
        std::vector<std::string> currentNodes = startNodes;
        size_t finished = 0;
        std::vector<long long> cycles;
        for (auto& currentNode : currentNodes)
        {
            long long steps = 0;
            while (currentNode.back() != 'Z')
            {
                if (instruction[steps % instruction.size()] == 'L')
                {
                    currentNode = network[currentNode].first;
                }
                else
                {
                    currentNode = network[currentNode].second;
                }

                ++steps;
            }
            cycles.push_back(steps);
        }
        
        long long lcm = cycles[0];
        for (size_t i = 1; i < cycles.size(); ++i)
        {
            long long commonLcm = std::max(lcm, cycles[i]);
            long long increaseNum = commonLcm;
            while (true)
            {
                if (commonLcm % lcm == 0 && commonLcm % cycles[i] == 0)
                {
                    break;
                }
                commonLcm += increaseNum;
            }
            lcm = commonLcm;
        }
        return std::to_string(lcm);
    }
}