#include <vector>
#include <algorithm>
#include <iostream>
#include "log.h"

using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> mVec;
  for (int i = 0; i < 10; ++i)
  {
    mVec.push_back(i);
  }

  PRINT_ELEMENTS(mVec,"int vec has:");

  return 0;
}
