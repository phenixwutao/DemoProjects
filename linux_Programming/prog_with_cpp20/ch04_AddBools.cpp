#include <iostream>
using namespace std;

template<typename T>
auto Add(T first, T second)
{
  return first + second;
}
template<>
auto Add<bool>(bool first, bool second)
{
  return static_cast<int>(first) + static_cast<int>(second);
}

int main()
{
  auto value = Add(true, false);
  cout << value << endl;
  return 0;
}
