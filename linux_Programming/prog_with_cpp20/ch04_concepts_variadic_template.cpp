#include <concepts>
#include <compare>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<std::integral... Args>
bool all(Args... args)
{
  return (... && args);
}

template<std::integral... Args>
bool any(Args... args)
{
  return (... || args);
}

template<std::integral... Args>
bool none(Args... args)
{
  return not (... || args);
}

int main()
{
  cout << std::boolalpha << endl;
  cout << "all(5, true, false) " << all(5, true, false) << endl;
  cout << "any(5, true, false) " << any(5, true, false) << endl;
  cout << "none(5, true, false) " << none(5, true, false) << endl;

  return 0;
}
