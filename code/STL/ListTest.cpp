#include <iostream>
#include <list>

using namespace std;

typedef list<int> Int_List;

int main(int argc, char const *argv[])
{
  Int_List mlist;
  for (int i = 0; i < 10; ++i)
  {
    mlist.push_back(i*i-2);
  }

  //let's search
  Int_List::const_iterator it;
  for(it=mlist.begin();it!=mlist.end();++it){
    cout << *it << endl;
  }

  return 0;
}