#include <stdio.h>
#include <stdlib.h>

class Test
{
public:
  Test(void){
    printf("test init\n");
  };
  ~Test(){
    printf("test release\n");
  };
  Test(const Test& test){
    printf("test copy \n");
  };

  const Test& operator=(const Test& test){
    printf("test assign\n");
  };
  int getSomething() const;
private:

};

class Test2
{
public:
  Test2(void){
    printf("test2 init\n");
  };
  ~Test2(){
    printf("test2 release\n");
  };
  Test2(const Test2& test){
    printf("test2 copy \n");
  };

  Test2& operator=(const Test2& test){
    printf("test2 assign\n");
  };
};


class Demo
{
public:
  Demo(void){
    printf("demo init\n");
  };
  ~Demo(){
    printf("demo release\n");
  };
  // Demo(const Demo& demo){
  //   printf("demo copy\n");
  //   test = demo.test; // 赋值操作
  // };
  Demo(const Demo& demo)
  :test(demo.test),test2(demo.test2){
    printf("demo copy\n");
  };
private:
  Test2 test2;
  Test test;
};


int main(int argc, char const *argv[])
{
  /* code */
  Demo demo;
  printf("-------------------------\n");
  Demo d2 = demo;
  printf("-------------------------\n");
  return 0;
}