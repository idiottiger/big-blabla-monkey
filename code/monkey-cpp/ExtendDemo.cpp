#include <stdio.h>

class Item
{
public:
  Item(void){
    printf("item init\n");
  };
  ~Item(){

  };

};

class Base
{
public:
  Base(void){
    print();
  };
  ~Base(){

  };

  virtual void print(){
    printf("base print \n");
  };

};

class Sub : public Base
{
public:
  Sub(void){
    print();
  };
  ~Sub(){
  };
  virtual void print(){
    printf("sub print \n");
  };
private:
  Item item;
};

int main(int argc, char const *argv[])
{
  Base b;
  printf("----------------------\n");
  Sub s;
  printf("----------------------\n");
  return 0;
}