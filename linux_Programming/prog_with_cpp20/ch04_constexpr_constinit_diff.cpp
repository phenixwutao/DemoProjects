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

// constexpr and constinit initialized at compile time
constexpr int constexprVal = 1000;
constinit int constinitVal = 1000;

int incrementMe(int val){ return ++val;}

int main()
{
  cout <<std::boolalpha;
  
  auto val = 1000;
  const auto res = incrementMe(val);
  std::cout << "res: " << res << '\n';

  // std::cout << "res: " << ++res << '\n'; //ERROR
  
  // std::cout << "++constexprVal: " << ++constexprVal << '\n'; //ERROR
  
  std::cout << "++constinitVal: " << ++constinitVal << '\n';

  constexpr auto localConstexpr = 1000; 

  // constinit does not initialise local variable
  // constinit auto localConstinit = 1000; // ERROR
  return 0;
}
