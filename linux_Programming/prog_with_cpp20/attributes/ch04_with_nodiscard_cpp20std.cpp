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

struct MyType
{
  [[nodiscard("Implicit destroying of temporary MyInt")]]MyType(int, bool) {}
};

template<typename T, typename ... Args>
[[nodiscard("You have memory leak")]]
T* create(Args&& ... args)
{
  return new T(std::forward<Args>(args)...);
}

enum class [[nodiscard("Do not ignore error code")]] ErrorCode
  {
    Okay, Warning, Critical, Fatal
  };

ErrorCode errorProneFunction()
{
  return ErrorCode::Fatal;
}

int main()
{
  cout <<std::boolalpha;
  int* val = create<int>(5);
  delete val;

  create<int>(6);
  errorProneFunction();

  MyType(7, true);
  return 0;
}
