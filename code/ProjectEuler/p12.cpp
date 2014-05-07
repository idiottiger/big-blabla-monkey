#include "common.h"
#include <math.h>

//http://projecteuler.net/problem=12

long long findTriangle(int divisors); 

int main(int argc, char const *argv[])
{ 
  cout << findTriangle(500) << endl;
  return 0;
}

long long findTriangle(int divisors){ 
  int divi_num = 0;
  long long sum = 1;

  int i = 1;
  while(true){
    for (int j = 1; j <= sum; ++j)
    {
      if(sum%j == 0){
        if(j < sum/j){
          divi_num+=2;
        }else if(j == sum/j){
          divi_num+=1;
        }else{
          break;
        }
      }
    }

    if(divi_num > divisors){
      return sum;
    }

    printf("index:%d,divi:%d \n",i,divi_num);
    ++i;
    sum+=i;
    divi_num = 0;
  }

}