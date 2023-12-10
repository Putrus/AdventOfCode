#include "../inc/Scratchcards.h"

#include <fstream>

namespace aoc2023
{
    Scratchcards::Scratchcards(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void Scratchcards::printAnswers()
    {
        PuzzleDecorator::printAnswers(4, "Scratchcards");
    }

    void Scratchcards::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        std::string input;
        file >> input;
        while (!file.eof())
        {
            file >> input;

            std::vector<int> winning;
            std::vector<int> youHave;
            while (input != "|")
            {
                file >> input;
                if (input == "|")
                {
                    break;
                }
                winning.push_back(std::stoi(input));
            }

            while (input != "Card" && !file.eof())
            {
                file >> input;
                if (input == "Card")
                {
                    break;
                }
                youHave.push_back(std::stoi(input));
            }

            scratchcards.push_back({ winning, youHave });
        }
        file.close();
    }

    std::string Scratchcards::getPart1()
    {
        int result = 0;
        for (const auto& scratchcard : scratchcards)
        {
            int points = 0;
            for (int number : scratchcard.first)
            {
                for (int winning : scratchcard.second)
                {
                    if (number == winning)
                    {
                        if (points == 0)
                        {
                            points = 1;
                        }
                        else
                        {
                            points *= 2;
                        }
                    }
                }
            }
            result += points;
        }
        return std::to_string(result);
    }

    std::string Scratchcards::getPart2()
    {
        int result = 0;
        std::vector<int> cards = std::vector<int>(scratchcards.size(), 1);
        for (int i = 0; i < static_cast<int>(scratchcards.size()); ++i)
        {
            int quantity = 0;
            for (int number : scratchcards[i].first)
            {
                for (int winning : scratchcards[i].second)
                {
                    if (number == winning)
                    {
                        ++quantity;
                    }
                }
            }
            for (int k = 0; k < cards[i]; ++k)
            {
                for (int j = i + 1; j < i + 1 + quantity; ++j)
                {
                    ++cards[j];
                }
            }
        }

        for (int quantity : cards)
        {
            result += quantity;
        }

        return std::to_string(result);
    }
}