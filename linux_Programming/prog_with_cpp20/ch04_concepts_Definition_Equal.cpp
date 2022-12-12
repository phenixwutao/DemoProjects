#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

#include <type_traits>

using namespace std;

template<typename T>
concept Equal = requires (T a, T b)
{
  {a == b} -> std::convertible_to<bool>;
  {a != b} -> std::convertible_to<bool>;
};

bool areEqual(Equal auto a, Equal auto b) { return a == b; }

struct WithoutEqual 
{
  bool operator == (const WithoutEqual& other) = delete;
};

struct WithoutUnequal
{
  bool operator != (const WithoutUnequal& other) = delete;
};

int main()
{
  cout << std::boolalpha;
  cout << "areEqual(1,5) " << areEqual(1,5) << endl;

  // bool res = areEqual(WithoutEqual(), WithoutEqual()); // fail to compile
  // bool res2 = areEqual(WithoutUnequal(), WithoutUnequal()); // fail to compile
  return 0;
}
