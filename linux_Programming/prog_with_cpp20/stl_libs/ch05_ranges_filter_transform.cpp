#include <concepts>

#include <string>
#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>

#include <algorithm>
#include <functional>

#include <iostream>

#include <type_traits>

#include <compare>

#include <ranges> // range filter P233

using namespace std;


int main()
{
  cout <<std::boolalpha;
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
  
  auto results = numbers // numbers is the range, filtered by views
    | std::views::filter( [](int n) { return n % 2 == 0; })
    | std::views::transform( [](int n){ return n * 2; });
  
  for (auto v: results)
    std::cout << v << " "; // 4 8 12
  cout << '\n';

  
  std::vector<int> myVec{-3, 5, 0, 7, -4};
  std::ranges::sort(myVec); // ranges sort the whole container
  for (auto v: myVec)
    std::cout << v << " "; // -4, -3, 0, 5, 7
  cout << endl;
  return 0;
}
