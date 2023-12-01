#include "../inc/DistressSignal.h"

#include <fstream>
#include <iostream>

Packet::Packet(int val) : variant(val)
{}

Packet::Packet(std::vector<Packet> const& vec) : variant(vec)
{}

bool operator<(Packet const& lhs, Packet const& rhs)
{
   return std::visit(CompareVisitor(), lhs, rhs);
}

DistressSignal::DistressSignal(std::shared_ptr<PuzzleComponent> puzzle) : PuzzleDecorator(puzzle)
{}

void DistressSignal::calcAndPrintAnswers()
{
   calcAndPrintAnswersTemplate(13, "Distress Signal");
   puzzle->calcAndPrintAnswers();
}

void DistressSignal::loadInput(const char* input_path)
{
   std::ifstream input(input_path);
   std::string first, second, line;
   while (std::getline(input, line))
   {
      if (line.empty())
      {
         pairs.push_back({ first, second });
         first.clear();
         second.clear();
         continue;
      }
      if (first.empty())
      {
         first = line;
         continue;
      }
      if (second.empty())
      {
         second = line;
         continue;
      }
   }
   input.close();
}

void DistressSignal::calcAndPrintAnswerToPart1()
{
   int sum = 0;
   for (int index = 0; index < pairs.size(); ++index)
   {
      Packet first = parse(pairs[index].first);
      Packet second = parse(pairs[index].second);
      if (first < second)
      {
         sum += index + 1;
      }
   }
   std::cout << sum << std::endl;
}

void DistressSignal::calcAndPrintAnswerToPart2()
{}

Packet DistressSignal::parse(std::string& s) const
{
   if ((s[0] == '[' && s[1] == ']') || s.empty())
   {
      s = s.substr(2);
      std::vector<Packet> empty_packet;
      return empty_packet;
   }

   if (s[0] == '[')
   {
      std::vector<Packet> vec;
      while (s[0] != ']')
      {
         s = s.substr(1);
         vec.push_back(parse(s));
      }
      s = s.substr(1);
      return vec;
   }
   size_t comma_pos = s.find(',');
   size_t bracket_pos = s.find(']');
   if (comma_pos < bracket_pos || comma_pos == std::string::npos)
   {
      Packet ret(0);
      if (comma_pos == std::string::npos)
      {
         ret = stoi(s.substr(0, bracket_pos));
         s = s.substr(bracket_pos);
      }
      else
      {
         ret = stoi(s.substr(0, comma_pos));
         s = s.substr(comma_pos);
      }
      return ret;
   }
   else if(comma_pos > bracket_pos || bracket_pos == std::string::npos)
   {
      Packet ret = stoi(s.substr(0, bracket_pos));
      s = s.substr(bracket_pos, s.length() - bracket_pos);
      return ret;
   }
   
   return stoi(s);
}
