#include <bitset>
#include "common.h"

/**
 *The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17. 
 *Find the sum of all the primes below two million.
**/

#define MAX_LMIT 2000000


//can use bitset<MAX_LMIT> 

long long calPrimeSum(long long limit);

int main(int argc, char const *argv[])
{ 
  cout << calPrimeSum(MAX_LMIT) << endl;
  cout << calPrimeSum2(MAX_LMIT) << endl;
  return 0;
}


long long calPrimeSum(long long limit){
  char* data = new char[limit+1]();
  long times;
  for(int i = 2; i <= limit/2; i++){
    times = limit / i;
    for(int j=2;j<=times;j++){
      data[i*j] = 1;
    }
  }
  long long sum = 0;
  for(int i=2;i<=limit;i++){
    if(data[i] == 0){
      sum+=i;
    }
  }
  delete[] data;
  return sum;
}

