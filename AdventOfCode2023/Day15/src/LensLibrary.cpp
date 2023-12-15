#include "../inc/LensLibrary.h"

#include <algorithm>
#include <fstream>
#include <sstream>

namespace aoc2023
{
    LensLibrary::LensLibrary(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void LensLibrary::printAnswers()
    {
        PuzzleDecorator::printAnswers(15, "Lens Library");
    }

    void LensLibrary::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line))
        {
            std::replace(line.begin(), line.end(), ',', ' ');
            std::stringstream ss(line);
            std::string sequence;
            while (!ss.eof())
            {
                ss >> sequence;
                sequences.push_back(sequence);
            }
        }
        file.close();
    }

    std::string LensLibrary::getPart1()
    {
        long long sum = 0;
        for (const auto& sequence : sequences)
        {
            sum += static_cast<long long>(getHash(sequence));
        }
        return std::to_string(sum);
    }

    std::string LensLibrary::getPart2()
    {
        
        std::vector<std::vector<std::pair<std::string, int>>> boxes;
        for (int i = 0; i < 256; ++i)
        {
            std::vector<std::pair<std::string, int>> box;
            boxes.push_back(box);
        }

        for (const auto& sequence : sequences)
        {
            size_t equalSignPos = sequence.find('=');
            if (equalSignPos != std::string::npos)
            {
                std::pair<std::string, int> lens;
                lens.first = sequence.substr(0, equalSignPos);
                lens.second = stoi(sequence.substr(equalSignPos + 1));
                unsigned char hash = getHash(lens.first);
                auto findLens = std::find_if(boxes[hash].begin(), boxes[hash].end(), [lens](const auto& boxLens)
                    {
                        return boxLens.first == lens.first;
                    });
                if (findLens != boxes[hash].end())
                {
                    findLens->second = lens.second;
                }
                else
                {
                    boxes[hash].push_back(lens);
                }
            }
            else
            {
                std::string lens = sequence.substr(0, sequence.size() - 1);
                unsigned char hash = getHash(lens);
                auto findLens = std::find_if(boxes[hash].begin(), boxes[hash].end(), [lens](const auto& boxLens)
                    {
                        return boxLens.first == lens;
                    });
                if (findLens != boxes[hash].end())
                {
                    boxes[hash].erase(findLens);
                }
            }
        }

        size_t focusingPower = 0;
        for (size_t i = 0; i < boxes.size(); ++i)
        {
            for (size_t j = 0; j < boxes[i].size(); ++j)
            {
                focusingPower += (i + 1) * (j + 1) * boxes[i][j].second;
            }
        }

        return std::to_string(focusingPower);
    }

    unsigned char LensLibrary::getHash(const std::string& sequence) const
    {
        unsigned char hash = 0;
        for (char c : sequence)
        {
            hash += c;
            hash *= 17;
            hash %= 256;
        }
        return hash;
    }
}