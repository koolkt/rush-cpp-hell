#pragma once

#include <string>
#include <map>
#include "Edge.hpp"

enum eAction
  {
    MA,
    HR,
    ACTION_ERROR
  };

class State
{
  std::string	name;
  bool		isFinal;
  std::map<Edge const, std::string const&> link;
  std::map<std::string const, eAction> actionMap;
public:
  State();
  ~State();

  std::string const&	getName() const;
  bool			getIsFinal() const;
  void			setIsFinal(bool);
  void			addLink(Edge const edge, std::string const& name, eAction action);
  void			delLink(Edge const edge);
  std::string const	getNextState(Edge const&);
  eAction		getAction(Edge const&);

private:
  static int stateNumber;
  static std::string nextName;
  static std::string const& getNextName();
};
