#include "Edge.hpp"

Edge::Edge(char c)
  : c(c)
{}

Edge::Edge()
  : c(0)
{}

Edge::~Edge()
{}

bool Edge::operator==(Edge const& other) const
{
  return c == other.c;
}

bool Edge::operator<(Edge const& other) const
{
  return c < other.c;
}

bool Edge::operator()(char o) const
{
  return c == o;
}

char Edge::getChar() const
{
  return c;
}

void Edge::setChar(char d)
{
  c = d;
}
