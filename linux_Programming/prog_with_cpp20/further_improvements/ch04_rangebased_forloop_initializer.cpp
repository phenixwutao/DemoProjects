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


int main()
{
  cout <<std::boolalpha;
  for (auto vec = std::vector{1,2,3}; auto v : vec)
    {
      cout << v << " ";
    }
  cout << "\n";

  // std::initializer_list
  for (auto initList = {1,3,5}; auto e : initList)
    {
      e *= e;
      cout << e << " "; 
    }
  cout << '\n';
  using namespace std::string_literals;
  for(auto str = "Hello World"s; auto c: str)
    {
      cout << c << ' ';
    }
  cout << '\n';
  return 0;
}
