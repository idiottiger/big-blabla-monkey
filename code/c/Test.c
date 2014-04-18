#include <stdio.h>
#include <stdlib.h>

#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)>(y)?(x):(y)
#define SWAP(x,y) (x)^=(y);(y)^=(x);(x)^=(y)

int findSecondLarge(int array[], int start, int length);

int main(){
  int array[] = {20,12,3,19,23,6,11,2,8,28};
  int sLarge = findSecondLarge(array,0,2);
  printf("sLarge value is:%d\n", sLarge);
  int a = 100, b = 200;
  printf("before swap[a=%d,b=%d]\n", a, b);
  SWAP(a,b);
  printf("after swap[a=%d,b=%d]\n", a, b);
  return 0;
}

int findSecondLarge(int array[], int start, int length){
  if(length < 2){
    printf("the array length must bigger than 2\n");
    exit(1);
  }
  int end = start + length-1;
  int sLarge = MIN(array[start], array[start+1]);
  int mLarge = MAX(array[start], array[start+1]);
  int i,temp;
  for(i=start;i<=end;i++){
    temp = array[i];
    if(temp > mLarge){
      sLarge = mLarge;
      mLarge = temp;
    }else if(temp > sLarge){
      sLarge = temp;
    }else{
      continue;
    }
  }
  return sLarge;
}