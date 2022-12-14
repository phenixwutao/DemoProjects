#include <concepts>

#include <string>
#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>

#include <iostream>

#include <type_traits>

#include <compare>

using namespace std;
struct MyBool
{
  // this template constructor only allows bool as implicit conversion
  template<typename T>
  explicit(!std::is_same<T, bool>::value) MyBool(T t)
  {
    cout << "MyBool: " << t << endl;
  }
};

void needBool(MyBool b){ }

int main()
{
  cout <<std::boolalpha;

  MyBool myBool1(true);
  MyBool myBool2 = false;
  MyBool myBool3 {1.2};

  needBool(myBool1);
  needBool(true);
  needBool(myBool3);

  //needBool(5);
  //needBool("true"); 
  return 0;
}
