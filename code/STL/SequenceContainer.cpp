#include <vector>
#include <array>
#include <deque>
#include <list>
#include <set>

#include <iostream>

using namespace std;

#ifdef USE_MULTI_SET
  #define __SET multiset
#else
  #define __SET set
#endif


int main(int argc, char const *argv[])
{

  __SET<string> str_set{
    "Tomomy","Kignry","Kenk"
  };
  str_set.insert("Tom");
  str_set.insert("Flank");
  str_set.insert("Adobu");
  str_set.insert("Benkhu");

  __SET<string>::iterator it = str_set.begin();
  str_set.insert(it,"Hello");
  str_set.insert(it,"Hello");

  
  for(it = str_set.begin();it!=str_set.end();it++){
    cout << *it << endl;
  }

  return 0;
}