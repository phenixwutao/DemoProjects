#include <iostream>

using namespace std;

template<typename T = int>
class wrapper
{
public:
  wrapper(const T& v) : value(v) {}
  const T& get() const { return value; }

  template<typename U>
  U as() const
  {
    return static_cast<U>(value);
  }

private:
  T value;
};


class composition
{
public:

  // function template within class
  template<typename T>
  T add(const T& a, const T& b)
  {
    return a + b;
  }
};

int main()
{
  wrapper a(42);
  wrapper<double> b(4.5);
  auto b1 = b.get();
  auto b2 = b.as<int>();
  printf("b1= %f, b2= %d\n", b1, b2);
  wrapper c('a');
  wrapper<std::string> d("42");
  //wrapper e("42");

  composition cp;
  auto sum = cp.add<int>(3,4);
  cout << "sum is "<< sum << '\n';
  return 0;
}