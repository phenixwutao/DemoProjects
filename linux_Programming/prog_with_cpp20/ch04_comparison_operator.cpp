#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>
#include <iostream>

#include <type_traits>

using namespace std;

struct MyInt{
  int value;
  explicit MyInt(int v) : value(v){}
  bool operator< (const MyInt& rhs) const
  {
    return value < rhs.value;
  }
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
  cout << isLessThan(myint1, myint2) << endl;

  return 0;
}
