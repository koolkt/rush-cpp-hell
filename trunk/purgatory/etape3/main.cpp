#include "Matcher.hpp"
#include <iostream>

int main(int ac, char** av)
{
  if (ac < 2)
    return -1;

  State state[8];
  FSA	fsa;
  Matcher matcher(fsa);

  state[0].addLink('m', "S1", MA);
  fsa.setInitialState(state[0]);

  state[1].addLink('e', "S2", MA);
  fsa.addState(state[1]);

  state[2].addLink('c', "S3", MA);
  fsa.addState(state[2]);

  state[3].addLink('h', "S4", MA);
  fsa.addState(state[3]);

  state[4].addLink('a', "S5", MA);
  fsa.addState(state[4]);

  state[5].addLink('n', "S6", MA);
  fsa.addState(state[5]);

  state[6].addLink('t', "S7", HR);
  fsa.addState(state[6]);

  std::cout << matcher.find(av[1]) <<std::endl;
  return 0;
}
