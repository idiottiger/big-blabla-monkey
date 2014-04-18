#include <stdio.h>

class A
{
public:
  A(){
    printf("A init\n");
  };
  virtual ~A(){
    printf("A release \n");
  }
};

class B
{
public:
  B(){
    printf("B init\n");
  };
  virtual ~B(){
    printf("B release \n");
  }
};

class C : public A, public B{
  public:
    C(){
      printf("C init\n");
    };
   virtual ~C(){
      printf("C release \n");
    }
};

int main(){
  C* c = new C();
  printf("------------------\n");
  delete c;
  printf("------------------\n");
  A* a = new C();
  printf("------------------\n");
  delete a;
  return 0;
}