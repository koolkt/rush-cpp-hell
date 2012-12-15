#pragma once

#include <string>
#include "FSA.hpp"

class Matcher
{
  FSA& fsa;

public:
  Matcher(FSA& fsa);
  ~Matcher();
  bool find(std::string const& str);
};
