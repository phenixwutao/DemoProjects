#include <concepts>

#include <string>
#include <string_view>

#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>

#include <iostream>

#include <type_traits>

#include <compare>

using namespace std;

enum Color
  {
    red, green, blue
  };

std::string_view toString(Color col)
{
  switch(col)
    {
      using enum Color;
    case red: return "red";
    case green: return "green";
    case blue: return "blue";
    }
  return "unknown";
}

int main()
{
  cout <<std::boolalpha;
  using enum Color;
  std::cout << "toString(green): " << toString(green) << '\n';
  return 0;
}
