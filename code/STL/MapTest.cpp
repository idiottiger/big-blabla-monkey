#include <map>
#include <iostream>

using namespace std;

#ifdef USE_MULTI_MAP
  #define __MAP multimap
#else
  #define __MAP map
#endif

int main(int argc, char const *argv[])
{
  
  //init c++11 
  __MAP<int,string> content = {
    {1,"Tomky"},
    {10,"Kengiy"},
    {2,"Homkey"}
  };

  //insert 
  content.insert(pair<int,string>(2,"Tonio")); //if use map, it existed, cann't insert 

  //check and insert
  __MAP<int,string>::iterator it;
  it = content.find(1);

  if(it != content.end()){ //iterator need check is end or not
    cout << "id i existed, let's remove it and add it" << endl;    
    content.erase(it);
  }
  content.insert(pair<int,string>(1,"Abckuiui"));


  pair<int,string> item(3,"Monky");
  content.insert(item);

  //print
  //map<int,string>::iterator it;
  for (it=content.begin();it!=content.end();it++){
    cout <<"id:" << it->first <<" value:" << it->second << endl;
  }

  

  return 0;
}