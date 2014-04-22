#ifndef __LOG_H__
  #define __LOG_H__

  #include <iostream>
  #include <string>

  using namespace std;

  template <typename T>
  void PRINT_ELEMENTS(const T& ct, const string& optstr=""){
    //must add the typename keyword
    typename T::const_iterator it;
    cout << optstr << "[";
    for (it=ct.begin();it!=ct.end();++it){
        cout << *it << ',';
    }
    cout << "]" << endl;
  }
#endif