#include <stdio.h>

#define STR_1 "Fizz"
#define STR_2 "Buzz"
#define STR_3 "Whizz"
#define STR_1_2 STR_1 STR_2
#define STR_2_3 STR_2 STR_3
#define STR_1_3 STR_1 STR_3
#define STR_1_2_3 STR_1 STR_2 STR_3

#define MAX(a,b) (a)>(b)?(a):(b)

#define TEST_1(a) (i%a==0)
#define TEST_2(a,b) (i%a==0 && i>a && i%b==0 && i>b)

#define PRINT(s) printf("%s\n", s)

int main(int argc, char const *argv[])
{
  int a = 0, b = 0 , c = 0;
  printf("please input three different special numbers [1-9]:\n");
  scanf("%d %d %d",&a,&b,&c);  
  //first check the value
  if(a<1 || a>9 || b<1 || b>9 || c<1 || c>9 || a==b || b==c || a==c){
    printf("input error \n");
    exit(1);
  }

  int num = 100;
  int i=1;

  int max_n = MAX(a,MAX(b,c));

  for (i = 1; i <= num; ++i){
    if(((i%10 == a || i/10 == a) && i>a) || (a == 1 && i == num)){
      PRINT(STR_1);
    }else if(i%a == 0 && i%b ==0 && i%c == 0 && i > max_n){
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