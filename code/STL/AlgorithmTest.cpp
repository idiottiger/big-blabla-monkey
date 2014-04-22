#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;

typedef vector<int> int_vector;
typedef vector<int>::iterator int_vector_it;

int main(int argc, char const *argv[])
{
  int_vector vec;
  //push some thing
  int length = 10;

  for (int i = 0; i < length; ++i)
  {
    if(i%2 == 0){
      vec.push_back(i*2-2);
    }else{
      vec.push_back(-i);
    }
  }

  cout << "print the vector as follow:" << endl;

  for (int i = 0; i < length; ++i)
  {
    cout << vec[i] << " ";
  }
  cout << endl;

  //let's use some algorithm
  int_vector_it max = max_element(vec.begin(),vec.end()-2);
  cout << "max value:" << *max << endl;

  int_vector_it min = min_element(vec.begin(),vec.end());
  cout << "min value:" << *min << endl;

  sort(vec.begin(),vec.end()-5);

  cout << "after sort, print  the vector as follow:" << endl;

  for (int i = 0; i < length; ++i)
  {
    cout << vec[i] << " ";
  }
  cout << endl;

  int_vector_it index = find(vec.begin(),vec.end(),10);
  cout << "find value 10 in pos:" << (index - vec.begin()) << endl;

  reverse(vec.begin(),index);

  cout << "after reverse, print  the vector as follow:" << endl;

  for (int i = 0; i < length; ++i)
  {
    cout << vec[i] << " ";
  }
  cout << endl;
  return 0;
}