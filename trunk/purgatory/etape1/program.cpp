#include "Machine.hpp"
#include <string>
#include <iostream>

bool machine(char input)
{
  eState	nextState;
  eAction	actionToDo;
  static std::string tokken = "";
  static eState currentState = S0;

  switch (input)
    {
    case 'm':
      nextState  = gStateTable [currentState][0];
      actionToDo = gActionTable[currentState][0];
      break;
    case 'e':
      nextState  = gStateTable [currentState][1];
      actionToDo = gActionTable[currentState][1];
      break;
    case 'c':
      nextState  = gStateTable [currentState][2];
      actionToDo = gActionTable[currentState][2];
      break;
    case 'h':
      nextState  = gStateTable [currentState][3];
      actionToDo = gActionTable[currentState][3];
      break;
    case 'a':
      nextState  = gStateTable [currentState][4];
      actionToDo = gActionTable[currentState][4];
      break;
    case 'n':
      nextState  = gStateTable [currentState][5];
      actionToDo = gActionTable[currentState][5];
      break;
    case 't':
      nextState  = gStateTable [currentState][6];
      actionToDo = gActionTable[currentState][6];
      break;
    default:
      nextState  = gStateTable [currentState][7];
      actionToDo = gActionTable[currentState][7];
      break;
    }

  switch (actionToDo)
    {
    case MA:
      tokken += input;
      break;
    case HR:
      tokken = "";
      currentState = S0;
      return true;
    case ACTION_ERROR:
      tokken = "";
      currentState = S0;
      return false;
    }

  currentState = nextState;
  return false;
}

int main(int ac, char** av)
{
  if (ac < 2)
    return -1;

  std::string str = av[1];
  for (unsigned int i = 0; i < str.length(); i++)
    {
      if (machine(str[i]))
	{
	  std::cout << "true" <<std::endl;
	  return 0;
	}
    }
  std::cout << "false" <<std::endl;
  return 0;
}
