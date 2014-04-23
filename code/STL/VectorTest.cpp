#include <iostream>
#include <vector>
#include <stdio.h>
#include "log.h"

using namespace std;

//vector function list:
//  capacity
//  reserve
//  assign
//  

int main(int argc, char const *argv[])
{
  vector<int> mVec;
  mVec.reserve(100);
  printf("size:%d,capacity:%d,max_size:%d\n", mVec.size(),mVec.capacity(),mVec.max_size());
  mVec.push_back(10);
  printf("after insert size:%d,capacity:%d,max_size:%d\n", mVec.size(),mVec.capacity(),mVec.max_size());
  for (int i = 0; i < 100; ++i)
  {
    mVec.push_back(i);
  }
  printf("end size:%d,capacity:%d,max_size:%d\n", mVec.size(),mVec.capacity(),mVec.max_size());

  //c++ 11 
  //mVec.shrink_to_fit();
  //printf("after shrink size:%d,capacity:%d,max_size:%d\n", mVec.size(),mVec.capacity(),mVec.max_size());

  vector<int> v1;
  for (int i = 0; i < 100; ++i)
  {
    v1.push_back(i);
  }
  PRINT_ELEMENTS(v1, "vector 1 has: ");
  printf("current capacity is:%d\n", v1.capacity());
  v1.assign(4,100);
  PRINT_ELEMENTS(v1, "after assign , vector 1 has: ");
  printf("after assign capacity is:%d\n", v1.capacity());
  return 0;
}