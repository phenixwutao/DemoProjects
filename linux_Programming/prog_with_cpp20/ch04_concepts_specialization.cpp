#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
struct Vector{
  Vector()
  {
    cout << "Vector<T>" << endl;
  }
};

template <std::regular Reg>
struct Vector<Reg>
{
  Vector()
  {
    cout << "Vector<std::regular>" << endl;    
  }
};

int main()
{
  // compile choose most specialized one: Vector<std::regular>
  Vector<int> vec1;

  // compile choose most specialized one: Vector<T>
  Vector<int&> vec2; // int& is not regular one

  return 0;
}
