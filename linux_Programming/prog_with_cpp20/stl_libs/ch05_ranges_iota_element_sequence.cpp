#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

#include <ranges> // range filter P233

using namespace std;

int main()
{
  std::cout << std::boolalpha;

  std::vector<int> vec;
  std::vector<int> vec2;
  for (int i: std::views::iota(0, 10))
    vec.push_back(i);

  // creates an infinite data stream, starting with 0, incremented by 1. ask for 10 times
  for (int i: std::views::iota(0) | std::views::take(10))
    vec2.push_back(i);

  for (int i: vec2)
    std::cout << i << " ";
  cout << endl;
  
  std::cout << "vec == vec2: " << (vec == vec2) << '\n';

  for (int i: vec)
    std::cout << i << " ";
  cout << endl;
  
  return 0;
}
