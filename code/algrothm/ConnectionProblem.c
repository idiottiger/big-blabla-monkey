#include <stdio.h>
#include <stdlib.h>

//quick search 
//quick union

#define N 100

char number[N];

void init_numbers();
void quick_search(int p, int q);
void quick_union(int p, int q);

int main(int argc, char const *argv[])
{

  init_numbers();
  int p,q;
  while(scanf("%d %d",&p,&q)==2){
    if(p >=0 && q >=0){
      quick_search(p,q);
    }else{
      exit(1);
    }
  }

  return 0;
}

void init_numbers(){
  int i;
  for (i = 0; i < N; ++i)
  {
    number[i] = i;
  }
}

void quick_search(int p, int q){
  if(number[p] != number[q]){
    int i;
    int j = number[p];
    for (i = 0; i < N; ++i)
    {
      if(number[i] == j){
        number[i] = number[q];
      }
    }
    printf("[%d-%d]\n",p,q);
  }else{
    printf("line \n");
  }
}