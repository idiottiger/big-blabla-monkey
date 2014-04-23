#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Func{
public:
  Func(){
    
  };
  void operator() (const T& t) const{
    cout << t << endl;
  };
};


template <int value>
void fun1(int& element){
  element += value;
}

int main(int argc, char const *argv[])
{

  vector<int> mVec;
  for (int i = 0; i < 10; ++i)
  {
    mVec.push_back(i);
  }

  for_each(mVec.begin(),mVec.end(),Func<int>());

  int i = 10;
  fun1<100>(i);
  cout << "i=" << i << endl;
  return 0;
}