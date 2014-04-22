#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "log.h"

using namespace std;

int main(int argc, char const *argv[])
{

  vector<int> iv1;

  for (int i = 0; i < 10; ++i){
    iv1.push_back(i);
  }

  PRINT_ELEMENTS(iv1,"iv1 has:");

  vector<int> iv2;
  iv2.push_back(11);

  copy(iv1.begin(),iv1.end(), back_inserter(iv2));
  PRINT_ELEMENTS(iv2,"iv2 has:");

  //if use vecotor, cann't use front_inserter
  //vector<int> iv3;
  list<int> iv3;
  copy(iv1.begin(),iv1.end(),front_inserter(iv3));
  PRINT_ELEMENTS(iv3,"iv3 has:");

  vector<int> iv4;
  iv4.push_back(100);
  iv4.push_back(200);
  iv4.push_back(300);
  iv4.push_back(400);
  copy(iv1.begin(),iv1.end(),inserter(iv4,iv4.begin()+1));
  PRINT_ELEMENTS(iv4,"iv4 has:");
  return 0;
}