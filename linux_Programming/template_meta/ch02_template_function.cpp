#include <iostream>

using namespace std;

template<typename T>
T myadd(T a, T b)
{
  return a + b;
}

class foo
{
private:
  int value;
public:
  explicit foo(const int v) : value (v) {}
  explicit operator int() const
  {
    return value;
  }

  foo& operator+(const foo& rhs)
  {
    value += rhs.value;
    return (*this);
  }
};

template<typename Input, typename Predicate>
int mycount_if(Input start, Input end, Predicate p)
{
  int total = 0;
  for(Input i = start; i != end; ++i)
  {
    if(p(*i))
      total++;
  }
  return total;
}

int main()
{  
  auto sum1 = myadd<int>(1,2);
  auto sum2 = myadd<>(1,2); // compiler deduce the parameter type
  auto sum3 = myadd(1,2); // compiler deduce the parameter type
  cout << "sum1 " << sum1 << ", sum2 " << sum2 << " , sum3 "<< sum3 << '\n';
  auto sum4 = myadd<double>(1.0, 1.3);
  cout << "sum4 " << sum4 << '\n';

  auto foo2 = myadd<foo>(foo(3),foo(4));

  int arr[] = {1,2,3,5,8,11};
  auto findOddNumber = [](const int i) { return i%2 == 1; };
  auto total = mycount_if(std::begin(arr), std::end(arr),  findOddNumber);
  cout << "total: " << total << '\n';
  return 0;
}