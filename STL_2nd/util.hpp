#include <iostream>
#include <iterator>
#include <string>
using namespace std;

namespace LFen{
  template<typename T>
  void PrintAll(const T& coll, const string& message)
  {
    cout << message << endl;
    for(const auto& it : coll)
      {
      cout << it << ' ';
      }
    cout << endl;
  }
}
