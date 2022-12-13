#include <concepts>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>
#include <iostream>

#include <type_traits>

#include <compare> // three-way comparison operator

using namespace std;

struct Strong
{
  std::strong_ordering operator<=>(const Strong&) const = default;
};

struct Weak
{
  std::weak_ordering operator<=>(const Weak&) const = default;
};

struct Partial
{
  std::partial_ordering operator<=>(const Partial&) const = default;
};

struct StrongWeakPartial
{
  Strong s;
  Weak w;
  Partial p;
  auto operator<=>(const StrongWeakPartial&) const = default;
};

int main()
{
  StrongWeakPartial a1, a2;
  cout << std::boolalpha;
  cout << "(a1 == a2) " << (a1 <a2) << endl;
  return 0;
}
