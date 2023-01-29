#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>

#include <map>

using namespace std;

class C
{
private:
  std::string name;
public:
  void foo()
  {
    // C++17: capture *this
    auto l1 = [*this] { std::cout << name << '\n'; };
  }
};


int main()
{
  auto squared3 = [](auto val) constexpr
  {
    return val*val;
  };

  auto squared4 = [](auto val) constexpr
  {
    // C++17, 20 ERROR: static variable in compile-time context
    // it works C++23
    static int i = 0;
    return val*val;
  };

  // compile-time lambda calls
  auto squared1 = [](auto val) constexpr {
    return val*val;
    };

// compile-time initialization
  constexpr auto squared2 = [](auto val) {
    return val*val;
    };

  constexpr auto squared5 = [](auto val) constexpr {
  return val*val;
  };

  return 0;
}

