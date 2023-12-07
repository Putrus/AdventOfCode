#include "../inc/CamelCards.h"

#include <algorithm>
#include <fstream>
#include <map>

#include <iostream>

namespace aoc2023
{
    CamelCards::CamelCards(std::unique_ptr<PuzzleComponent>&& puzzle) : PuzzleDecorator(std::move(puzzle))
    {
    }

    void CamelCards::printAnswers()
    {
        PuzzleDecorator::printAnswers(7, "Camel Cards");
    }

    void CamelCards::loadInput(const char* filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }
        
        std::string cards;
        long long bid;
        while (!file.eof())
        {
            file >> cards >> bid;
            hands.push_back({ cards, bid });
        }
        hands.erase(hands.begin() + hands.size() - 1);
        file.close();
    }

    std::string CamelCards::getPart1()
    {
        std::map<char, int> strengths =
        {
            { '2', 0 }, { '3', 1 }, { '4', 2 }, { '5', 3 },
            { '6', 4 }, { '7', 5 }, { '8', 6 }, { '9', 7 },
            { 'T', 8 }, { 'J', 9 }, { 'Q', 10 }, { 'K', 11 },
            { 'A', 12 } };
        std::sort(hands.begin(), hands.end(),
            [this, &strengths](const auto& lhs, const auto& rhs)
            {
                int lhsType = getType(lhs.first);
                int rhsType = getType(rhs.first);
                bool areEqual = lhsType == rhsType;
                if (areEqual)
                {
                    for (size_t i = 0; i < lhs.first.size(); ++i)
                    {
                        if (strengths[lhs.first[i]] == strengths[rhs.first[i]])
                        {
                            continue;
                        }
                        else
                        {
                            return strengths[lhs.first[i]] < strengths[rhs.first[i]];
                        }
                    }
                }
                return lhsType < rhsType;
            });

        long long totalWinnings = 0;
        for (long long rank = 0; rank < static_cast<long long>(hands.size()); ++rank)
        {
            totalWinnings += hands[rank].second * (rank + 1);
        }
        return std::to_string(totalWinnings);
    }

    std::string CamelCards::getPart2()
    {
        std::map<char, int> strengths =
        {
            { '2', 0 }, { '3', 1 }, { '4', 2 }, { '5', 3 },
            { '6', 4 }, { '7', 5 }, { '8', 6 }, { '9', 7 },
            { 'T', 8 }, { 'J', -1 /* joker */ }, {'Q', 10}, {'K', 11},
            { 'A', 12 } };

        std::sort(hands.begin(), hands.end(),
            [this, &strengths](const auto& lhs, const auto& rhs)
            {
                int lhsType = getTypeJoker(lhs.first);
                int rhsType = getTypeJoker(rhs.first);
                bool areEqual = lhsType == rhsType;
                if (areEqual)
                {
                    for (size_t i = 0; i < lhs.first.size(); ++i)
                    {
                        if (strengths[lhs.first[i]] == strengths[rhs.first[i]])
                        {
                            continue;
                        }
                        else
                        {
                            return strengths[lhs.first[i]] < strengths[rhs.first[i]];
                        }
                    }
                }
                return lhsType < rhsType;
            });

        long long totalWinnings = 0;
        for (long long rank = 0; rank < static_cast<long long>(hands.size()); ++rank)
        {
            totalWinnings += hands[rank].second * (rank + 1);
        }
        return std::to_string(totalWinnings);
    }

    int CamelCards::getType(const std::string& hand)
    {
        std::map<char, int> map;
        for (char c : hand)
        {
            if (map.find(c) == map.end())
            {
                map.insert({ c, 1 });
            }
            else
            {
                ++map.at(c);
            }
        }

        if (map.size() == 1)
        {
            return 6;
        }
        else if (map.size() == 2)
        {
            if (map.begin()->second == 4 || map.begin()->second == 1)
            {
                return 5;
            }
            else
            {
                return 4;
            }
        }
        else if (map.size() == 3)
        {
            if (std::find_if(map.begin(), map.end(), [](const auto& element)
                {
                    return element.second == 3;
                }) != map.end())
            {
                return 3;
            }
            else
            {
                return 2;
            }
        }
        else if (map.size() == 4)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int CamelCards::getTypeJoker(const std::string& hand)
    {
        std::map<char, int> strengths =
        {
            { '2', 0 }, { '3', 1 }, { '4', 2 }, { '5', 3 },
            { '6', 4 }, { '7', 5 }, { '8', 6 }, { '9', 7 },
            { 'T', 8 }, { 'J', -1 /* joker */ }, {'Q', 10}, {'K', 11},
            { 'A', 12 } };

        std::map<char, int> map;
        for (char c : hand)
        {
            if (map.find(c) == map.end())
            {
                map.insert({ c, 1 });
            }
            else
            {
                ++map.at(c);
            }
        }

        if (map.find('J') != map.end())
        {
            std::pair<char, int> bestCard = { 'A', 0 };
            for (const auto& card : map)
            {
                if (card.first != 'J')
                {
                    if (card.second > bestCard.second)
                    {
                        bestCard = card;
                    }
                    else if (card.second == bestCard.second &&
                        strengths[card.first] > strengths[bestCard.first])
                    {
                        bestCard = card;
                    }
                }
            }

            if (map.size() != 1)
            {
                map.at(bestCard.first) += map.at('J');
            }
            else
            {
                map.insert({ 'A', map.at('J') });
            }
            map.erase(map.find('J'));
        }

        if (map.size() == 1)
        {
            return 6;
        }
        else if (map.size() == 2)
        {
            if (map.begin()->second == 4 || map.begin()->second == 1)
            {
                return 5;
            }
            else
            {
                return 4;
            }
        }
        else if (map.size() == 3)
        {
            if (std::find_if(map.begin(), map.end(), [](const auto& element)
                {
                    return element.second == 3;
                }) != map.end())
            {
                return 3;
            }
            else
            {
                return 2;
            }
        }
        else if (map.size() == 4)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}