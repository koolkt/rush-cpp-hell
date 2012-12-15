#include <string>
#include <iostream>
#include "FunctionSignature.hpp" 

int	onefunction(const std::string & str)
{
    std::cout<< str << std::endl;
    return 1;
}
 
int		        main(int ac, char **av)
{
    FunctionSignature<int (const std::string& str)>::type f = &onefunction;
     
    f("coucou");
}
