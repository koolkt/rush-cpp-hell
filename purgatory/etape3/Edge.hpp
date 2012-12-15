#pragma once

class Edge
{
  char c;

public:
  Edge();
  Edge(char c);
  ~Edge();

  char getChar() const;
  void setChar(char d);

  bool operator==(Edge const& other) const;
  bool operator()(char o) const;
  bool operator<(Edge const& other) const;
};
