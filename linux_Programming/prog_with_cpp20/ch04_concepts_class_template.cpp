#include <concepts>
#include <compare>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<std::regular T>
class MyVector {};

int main()
{
  MyVector<int> vec1;

  // template constraint failure: requires  regular<T> 
  MyVector<int&> vec2; 
  return 0;
}
