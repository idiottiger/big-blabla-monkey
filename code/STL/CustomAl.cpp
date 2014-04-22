#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include "log.h"

using namespace std;

void just_print(int value);
int square(int value);
bool findFirstBiggerThanTwo(int value);

int main(int argc, char const *argv[])
{
  vector<int> intVec;
  for (int i = 0; i < 10; ++i)
  { 
    intVec.push_back(i);
  }

  for_each(intVec.begin(),intVec.end(),just_print);

  vector<int> buffer;
  transform(intVec.begin(),intVec.end(),back_inserter(buffer),square);

  PRINT_ELEMENTS(buffer,"buffer has:");

  //test find_if
  vector<int>::iterator pos = find_if(intVec.begin(),intVec.end(),findFirstBiggerThanTwo);

  if(pos == intVec.end()){
    printf("findFirstBiggerThanTwo no found \n");  
  }else{
    printf("findFirstBiggerThanTwo pos:%d",pos-intVec.begin());  
  }
  

  return 0;
}

void just_print(int value){
  printf("value:%d\n",value);
}

int square(int value){
  return value*value;
}

bool findFirstBiggerThanTwo(int value){
  return value > 2;
}