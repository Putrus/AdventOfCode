#pragma once

#include "../../Decorator/inc/PuzzleDecorator.h"

#include <vector>
#include <string>
#include <variant>

struct Packet : std::variant<int, std::vector<Packet>>
{
   Packet(int val);
   Packet(std::vector<Packet> const& vec);

   friend bool operator<(Packet const& lhs, Packet const& rhs);
};

struct CompareVisitor
{
   bool operator()(int lhs, int rhs) const
   {
      return lhs < rhs;
   }

   bool operator()(std::vector<Packet> const& lhs, std::vector<Packet> const& rhs)
   {
      return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
   }

   bool operator()(int lhs, std::vector<Packet> const& rhs)
   {
      std::vector<Packet> p = { lhs };
      return (*this)(p, rhs);
   }

   bool operator()(std::vector<Packet> const& lhs, int rhs)
   {
      std::vector<Packet> p = { rhs };
      return (*this)(lhs, p);
   }
};

class DistressSignal final : public PuzzleDecorator
{
public:
   DistressSignal(std::shared_ptr<PuzzleComponent> puzzle);
   void calcAndPrintAnswers() override;

private:
   void loadInput(const char* input_path) override;
   void calcAndPrintAnswerToPart1() override;
   void calcAndPrintAnswerToPart2() override;
   Packet parse(std::string& s) const;

private:
   std::vector<std::pair<std::string, std::string>> pairs;
};