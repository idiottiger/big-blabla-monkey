#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
#include "log.h"

using namespace std;

int main(int argc, char const *argv[])
{

  vector<int> buffer;
  for (int i = 0; i < 10; ++i)
  {
    buffer.push_back(i);
  }

  //the ostream_iterator need use the template type
  copy(buffer.begin(),buffer.end(),ostream_iterator<int>(cout,"_"));

  return 0;
}