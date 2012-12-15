#include <string>
#include <iostream>
#include "Function.hpp"
#include <boost/bind.hpp>

class Test
{
public:
  Test(){}
  ~Test(){} 
  char	operator()(char c1) { return c1; }
};

int funct1(char c)
{
  std::cout << c << std::endl;
  return 0;
}
 
int main()
{
  Function<int (char)> f = &funct1;
  Function<int (char)> b = boost::bind(&funct1, _1);
  Test n;
  Function<char (char)> c = n;
 
  f('f');
  b('b');
  std::cout << c('o') << std::endl;
  return 0;
}
