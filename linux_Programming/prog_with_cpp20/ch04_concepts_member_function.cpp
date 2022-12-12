#include <concepts>
#include <compare>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct NotCopyable
{
 NotCopyable() = default;
 NotCopyable(const NotCopyable&) = delete; 
};

template<typename T>
struct MyVector
{
  void push_back(const T&) requires std::copyable<T> {}
};

int main()
{
  MyVector<int> vec1;
  vec1.push_back(2020);

  MyVector<NotCopyable> vec2;
  
  vec2.push_back(NotCopyable()); // Error because not copyable

  return 0;
}
