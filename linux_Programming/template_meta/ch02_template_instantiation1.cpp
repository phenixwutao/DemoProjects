#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct control
{};

template <typename T>
struct button : public control<T>
{};

void show(button<int>* ptr)
{
    control<int>* c = ptr;
}


template <typename T>
struct StaticStruct
{
  static T data;
};

template<typename T>
T StaticStruct<T>::data = 0;

namespace ns
{
  template <typename T>
  struct wrapper
  {
    T value;
  };

  template struct wrapper<int>; // [1]
}

template struct ns::wrapper<double>; // [2]

namespace ns
{
  template <typename T>
  T add(T const a, T const b)
  {
    return a + b;
  }

  template int add(int, int); // [3]
}

template double ns::add(double, double); // [4]


template <typename T>
class foo
{
  struct bar {};

  T f(bar const arg)
  {
    return {};
  }
};

template int foo<int>::f(foo<int>::bar); //[5] explicit instantiation definition even as private


int main()
{
  button<int>* p1 = new button<int>();
  show(p1);
  delete p1;

  StaticStruct<int> s1;
  StaticStruct<double> s2;
  StaticStruct<double> s3;
  cout << "s1= " << s1.data << '\n';
  cout << "s2= " << s2.data << '\n';
  cout << "s3= " << s3.data << '\n';

  s2.data = 10;
  s3.data = 8;
  cout << "s1= " << s1.data << '\n'; // type int instantiation is 0
  cout << "s2= " << s2.data << '\n'; // type double instantiation is 8
  cout << "s3= " << s3.data << '\n'; // type double instantiation is 8
  return 0;
}
