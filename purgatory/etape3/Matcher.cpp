#include "Matcher.hpp"

Matcher::Matcher(FSA& fsa)
  : fsa(fsa)
{}

Matcher::~Matcher()
{}

bool Matcher::find(std::string const& str)
{
  State& currentState = fsa.getInitialState();

  for (unsigned int i = 0; i < str.length() + 1; i++)
    {
      Edge edge(str[i]);
      std::string nameNextState = currentState.getNextState(edge);
      if (nameNextState == "")
	nameNextState = fsa.getInitialState().getName();
      eAction actionToDo = currentState.getAction(edge);

      switch (actionToDo)
	{
	case MA:
	  break;
	case HR:
	  return true;
	case ACTION_ERROR:
	  break;
	}
      currentState = fsa[nameNextState];
    }
  return false;
}
