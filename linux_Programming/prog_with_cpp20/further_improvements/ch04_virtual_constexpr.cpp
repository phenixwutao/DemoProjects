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

struct X1 {
  virtual int f() const = 0;
};

struct X2: public X1
{
  constexpr int f() const override { return 2; }
};

struct X3: public X2
{
  int f() const override { return 3; }
};

struct X4: public X3
{
  constexpr int f() const override { return 4; }
};

int main()
{
  cout <<std::boolalpha;
  X1* x1 = new X4;
  std::cout << "x1->f(): " << x1->f() << '\n';

  X4 x4;
  X1& x2 = x4;
  std::cout << "x2.f(): " << x2.f() << '\n';
  return 0;
}
