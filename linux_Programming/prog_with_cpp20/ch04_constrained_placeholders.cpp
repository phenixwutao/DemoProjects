#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

// the concept std::integral can be used as return type
std::integral auto getIntegral(int v)
{
  return v;
}

int main()
{
  cout << std::boolalpha;

  vector vec {1,2,3,4,5};
  for(std::integral auto i : vec)
    cout << i << endl;

  std::integral auto b = true;
  cout << b << endl;

  std::integral auto integ = getIntegral(10);
  cout << integ << endl;

  auto integ1 = getIntegral(9.8);
  cout << integ1 << endl;
  
  return 0;
}
