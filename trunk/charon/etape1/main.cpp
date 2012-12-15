#include <string>
#include <iostream>
#include "FunctionSignature.hpp" 

int	onefunction(const std::string & str, int i, int j)
{
    std::cout<< str << std::endl;
    return 1;
}
 
int		        main(int ac, char **av)
{
  FunctionSignature<int (const std::string& str, int, int)>::type f = &onefunction;
     
  f("coucou", 1 , 2);
}
