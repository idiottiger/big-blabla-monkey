#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Object
{
public:
  int number;
  char* value;
  Object(void);
  ~Object();

  Object(const Object&);
};

Object::Object(void){
  number = 100;
  value = new char[100];
  strcpy(value,"hello world");
  printf("object init ...\n");
}

Object::~Object(){
  printf("object release ...\n");
}

// Object::Object(const Object& obj){  
//   printf("object copy ...\n");
//   number = obj.number+10;
// }

void testCopyMethod(Object obj){
  printf("copy method \n");
}

int main(){
  Object obj1;
  printf("*******************\n");
  Object obj2 = obj1;
  printf("*******************\n");
  printf("number:%d\n", obj2.number);
  printf("location:%d,%d\n", &*obj1.value,&*obj2.value);
  delete obj1.value;
  obj1.value = 0;
  printf("location:%d\n",&*obj2.value);
  return 0;
}
