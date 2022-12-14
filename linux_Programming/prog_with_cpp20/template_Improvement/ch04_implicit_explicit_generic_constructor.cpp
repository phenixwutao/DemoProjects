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

struct Implicit
{
  template<typename T>
  Implicit(T t)
  {
    cout << "Implicit: " << t << endl;
  }
};

struct Explicit
{
  template<typename T>
  explicit Explicit(T t)
  {
    cout << "Explicit: " << t << endl;
  }
};

int main()
{
  cout <<std::boolalpha;
  Implicit imp1 = "implicit";
  Implicit imp2("explicit");
  Implicit imp3 = 1998;
  Implicit imp4(1998);  

  //Explicit exp1 = "implicit"; // compile error
  Explicit exp2{"explicit"};
  //Explicit exp3 = 2011; // compile error
  Explicit exp4{2011};  
  return 0;
}
