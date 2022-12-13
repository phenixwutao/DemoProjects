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

struct MyDouble
{
  double value;

  // constexpr expression
  explicit constexpr MyDouble(double v) : value(v) {}

  auto operator<=> (const MyDouble&) const = default;
};

// compiler-generated constexpr three-way comparison operator
template<typename T>
constexpr bool isLessThan(const T& lhs, const T& rhs)
{
  return lhs < rhs;
}

int main()
{
  cout <<std::boolalpha ;
  constexpr MyDouble mydoub1(2011);
  constexpr MyDouble mydoub2(2013);

  constexpr auto res = isLessThan(mydoub1, mydoub2);
  cout << "res = " << res << endl;

  return 0;
}
