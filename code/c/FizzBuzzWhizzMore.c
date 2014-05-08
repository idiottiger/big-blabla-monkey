#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define DEFAULT_NUMBER 100
//int max: 2^32 , max length
#define MAX_LENGTH 10

#define STR_1 "Fizz"
#define STR_2 "Buzz"
#define STR_3 "Whizz"
#define STR_1_2 STR_1 STR_2
#define STR_2_3 STR_2 STR_3
#define STR_1_3 STR_1 STR_3
#define STR_1_2_3 STR_1 STR_2 STR_3


#define TEST_1(a) (i%a==0)
#define TEST_2(a,b) (TEST_1(a) && TEST_1(b))
#define TEST_3(a,b,c) (TEST_1(a) && TEST_1(b) && TEST_1(c))

#define PRINT(s) printf("%s\n", s)

char INT_STR[MAX_LENGTH];

int test_have_special_number(int special, int number);


int main(int argc, char const *argv[])
{

  int num = DEFAULT_NUMBER;

  printf("please input student number [%d-%d]\n",DEFAULT_NUMBER,INT_MAX);
  scanf("%d",&num);
  
  if(num < 0 || num < DEFAULT_NUMBER || num > INT_MAX){
    num = DEFAULT_NUMBER;
    printf("student number input error, use the default number:[%d]\n",num);
  }
  printf("student number is [%d]\n",num);

  int a = 0, b = 0 , c = 0;
  printf("please input three different special numbers [1-9]:\n");
  scanf("%d %d %d",&a,&b,&c);  

  //first check the value
  if(a<1 || a>9 || b<1 || b>9 || c<1 || c>9 || a==b || b==c || a==c){
    printf("input error \n");
    exit(1);
  }


  int i = 1;


  for (i = 1; i <= num; ++i){
    if(test_have_special_number(a,i)){
      PRINT(STR_1);
    }else if(TEST_3(a,b,c)){
      PRINT(STR_1_2_3);
    }else if(TEST_2(a,b)){
      PRINT(STR_1_2);
    }else if(TEST_2(b,c)){
      PRINT(STR_2_3);
    }else if(TEST_2(a,c)){
      PRINT(STR_1_3);
    }else if(TEST_1(a)){
      PRINT(STR_1);
    }else if(TEST_1(b)){
      PRINT(STR_2);
    }else if(TEST_1(c)){
      PRINT(STR_3);
    }else{
      printf("%d\n", i);
    }
  }

  return 0;
}


int test_have_special_number(int special,int number){
  if(number > special){
    sprintf(INT_STR,"%d",number);
    int i = -1, j = 0;
    while((j=INT_STR[++i])!='\0'){
      if(j-48 == special){
        return 1;
      }
    }
  }else{
    return 0;
  }
}