#include <iostream>

using namespace std;

class DemoClass
{
public:
  DemoClass();
  DemoClass(int v);
  ~DemoClass();

  DemoClass(const DemoClass& cls);

  DemoClass& operator= (const DemoClass& cls);
  //why use DemoClass, not DemoClass&, because + will return a new object
  DemoClass operator+ (const DemoClass& cls);

  bool operator== (const DemoClass& another);
  bool operator!= (const DemoClass& another);

  // why add the friend ??/
  friend ostream& operator<< (ostream& out,const DemoClass& cls);

  void print(){
    cout << "value:" << value << endl;
  };

  int getValue() const{
    return value;
  };

private:
  int value;
};


DemoClass::DemoClass():value(0){
  cout << "init" << endl;
}

DemoClass::DemoClass(int v):value(v){
  cout << "init with:" << value << endl;
}

DemoClass::~DemoClass(){
  cout << "release" << endl;
}

DemoClass::DemoClass(const DemoClass& cls):value(cls.value){
  cout << "copy " << endl;
}

DemoClass& DemoClass::operator= (const DemoClass& cls){
  cout << "op =" << endl;
  if(this != &cls){
    value = cls.value;
  }
  return *this;
}

DemoClass DemoClass::operator+ (const DemoClass& cls){
  cout << "op +" << endl;
  DemoClass result = *this;
  result.value = value + cls.value;
  return result;
}

bool DemoClass::operator== (const DemoClass& another){
  cout << "op == " << endl;
  return value == another.value;
}

bool DemoClass::operator!= (const DemoClass& another){
  cout << "op != " << endl;
  return !(*this == another); 
}

//here don't add the class name 
// ostream& DemoClass::operator<< (ostream& out, const DemoClass& cls){
ostream& operator<< (ostream& out, const DemoClass& cls){
  out << "value is:" << cls.getValue();
  return out;
}


int main(int argc, char const *argv[])
{
  DemoClass dc1(100);
  cout << "********************************" << endl;
  DemoClass dc2 = dc1;
  cout << "********************************" << endl;
  DemoClass dc3 = dc1+dc2;
  cout << "********************************" << endl;
  dc1.print();
  dc2.print();
  dc3.print();
  cout << "********************************" << endl;
  cout << (dc1!=dc2) << endl;
  cout << "********************************" << endl;
  cout << dc1 << endl;
  return 0;
}