#include "toString.hpp"
#include "State.hpp"

int State::stateNumber = 0;
std::string State::nextName = "";

State::State()
  : name(getNextName()),
    isFinal(false)
{}

State::~State() 
{}

std::string const&	State::getNextName()
{
  nextName = "S" + toString(stateNumber++);
  return nextName;
}

std::string const&	State::getName() const
{
  return name;
}

bool			State::getIsFinal() const
{
  return isFinal;
}

void			State::setIsFinal(bool b)
{
  isFinal = b;
}

void			State::addLink(Edge const edge, std::string const& name, eAction action)
{
  link.insert(std::pair<Edge const, std::string const&>(edge, name));
  actionMap[name] = action;
}

void			State::delLink(Edge const edge)
{
  link.erase(edge);
}

std::string const	State::getNextState(Edge const& edge)
{
  std::map<Edge const, std::string const&>::iterator it = link.find(edge);
  if (it == link.end())
    return "";
  return it->second;
}

eAction			State::getAction(Edge const& edge)
{
  std::map<Edge const, std::string const&>::iterator it = link.find(edge);
  if (it == link.end())
    return ACTION_ERROR;
  return actionMap[it->second];
}
