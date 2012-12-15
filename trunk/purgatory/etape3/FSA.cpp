#include "FSA.hpp"

FSA::FSA()
  : initialState(0)
{}

FSA::~FSA()
{}

void FSA::addState(State& state)
{
  stateList.push_back(&state);
}

State& FSA::operator[](std::string const& name)
{
  std::list<State*>::iterator it;
  for (it = stateList.begin(); it != stateList.end(); it++)
    if (name == (*it)->getName())
      return **it;
  throw std::string("invalid name: " + name);
}

void FSA::setInitialState(State& state)
{
  initialState = &state;
}

State& FSA::getInitialState()
{
  return *initialState;
}
