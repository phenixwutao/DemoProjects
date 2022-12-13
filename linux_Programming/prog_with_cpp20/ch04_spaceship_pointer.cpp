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

struct A
{
  vector<int>* pointerToVector = nullptr;

  ~A()
  {
    delete pointerToVector;
    pointerToVector = nullptr;
  }

  auto operator <=> (const A&) const = default;
};

int main()
{
  std::cout << std::boolalpha;
  A a1 {new std::vector<int>()};
  A a2 {new std::vector<int>()};
  cout << "(a1 == a2) " << (a1 == a2) << endl;
  return 0;
}
