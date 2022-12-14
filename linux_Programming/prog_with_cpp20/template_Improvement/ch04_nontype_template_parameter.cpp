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
// page 192

struct ClassType
{
  constexpr ClassType(int a) {}
};

template<ClassType cl>
auto getClassType()
{
  return cl;
}

template<double d>
auto getDouble()
{
  return d;
}

int main()
{
  cout <<std::boolalpha;
  
  auto c1 = getClassType<ClassType(2022)>();
  auto d1 = getDouble<5.5>();
  auto d2 = getDouble<6.5>();
  cout << d1 << " ,  " << d2 << endl;
  return 0;
}
