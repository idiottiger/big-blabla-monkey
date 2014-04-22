#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "log.h"

int main(int argc, char const *argv[])
{
  list<int> intVec;

  for (int i = 0; i < 6; ++i)
  {
    intVec.push_back(i);
    intVec.push_front(i);
  }

  PRINT_ELEMENTS(intVec,"list has:");

  //remove will return the new end position
  list<int>::iterator end = remove(intVec.begin(),intVec.end(),4);
  PRINT_ELEMENTS(intVec,"after remove:");

  copy(intVec.begin(),end,ostream_iterator<int>(cout," "));

  return 0;
}