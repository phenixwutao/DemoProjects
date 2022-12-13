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

struct MyInt{
  int value;
  explicit MyInt(int v) : value(v){}
  auto operator <=>(const MyInt& rhs) const
  {
    return value <=> rhs.value;
  }
};

struct MyDouble
{
  double value;
  explicit constexpr MyDouble(double v) : value(v) {}
  auto operator <=> (const MyDouble& rhs) const = default;
};

template<typename T>
constexpr bool isLessThan(const T& lhs, const T& rhs)
{
  return lhs < rhs;
}

int main()
{
  cout << std::boolalpha;
  MyInt myint1(2011);
  MyInt myint2(2022);
  cout << "isLessThan(myint1, myint2) " << isLessThan(myint1, myint2) << endl;

  MyInt mydouble1(2011);
  MyInt mydouble2(2022);
  cout << "isLessThan(mydouble1, mydouble2) " << isLessThan(mydouble1, mydouble2) << endl;
  return 0;
}
