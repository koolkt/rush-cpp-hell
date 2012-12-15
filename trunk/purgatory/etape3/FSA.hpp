#pragma once

#include <list>
#include "State.hpp"

class FSA
{
  State* initialState;
  std::list<State*> stateList;

public:
  FSA();
  ~FSA();

  State& getInitialState();
  void setInitialState(State&);
  void addState(State&);
  State& operator[](std::string const& name);
};
