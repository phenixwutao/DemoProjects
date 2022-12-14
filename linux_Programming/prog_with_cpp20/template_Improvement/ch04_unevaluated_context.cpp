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

int add1(int, int); // declaration

int add2(int a, int b) { return a + b; } // definition

int main()
{
  cout <<std::boolalpha;
  std::cout << "typeid(add1).name(): " << typeid(add1).name() << '\n';
  
  decltype(*add1) add = add2;
  std::cout << "add(2000, 20): " << add(2000, 20) << '\n';
  
  return 0;
}
