#include <concepts>

#include <string>
#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>

#include <iostream>

#include <type_traits>

#include <compare>

using namespace std;
// page 192

struct ClassType
{
  constexpr ClassType(int a) {}
};

template<ClassType cl>
auto getClassType()
{
  return cl;
}

template<double d>
auto getDouble()
{
  return d;
}

template<int N>
class StringLiteral 
{
public:
  constexpr StringLiteral(const char (&str)[N])
  {
    std::copy(str, str + N, data);
  }

  char data[N];
};

template<StringLiteral str>
class ClassTemplate {};

template<StringLiteral str>
void FunctionTemplate()
{
  cout << str.data << endl;
}

int main()
{
  cout <<std::boolalpha;
  ClassTemplate<"string test"> cls;
  FunctionTemplate<"function test">();

  /* C++20 supports further floating-points as non-type template parameters. */
  
  return 0;
}
