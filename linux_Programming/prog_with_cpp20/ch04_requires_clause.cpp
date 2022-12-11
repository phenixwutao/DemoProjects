#include <concepts>
#include <iostream>
using namespace std;

template<unsigned int i>
requires (i <= 20)
int sum(int j)
{
  return i+j;
}

// concepts are compile-time predicates
// using concepts as return types: 
template<typename T>
requires std::integral<T>
std::integral auto gcd(T a, T b)
{
  if (b == 0) return a;
  else
    return gcd(b, a%b);
}

std::integral auto gcd1(std::integral auto a, std::integral auto b)
{
  if (b == 0) return a;
  else
    return gcd(b, a%b);
}

int main()
{
  // if template parameter is greater than 20, it will cause compile error
  cout << sum<20>(2000) << endl;
  return 0;
}
