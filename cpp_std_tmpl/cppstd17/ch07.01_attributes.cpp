#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>

#include <map>

using namespace std;

void foo(int val, std::string msg)
{
  //cout << val << " , " << msg << '\n';
}

void foo2(int val, [[maybe_unused]] std::string msg)
{
}

[[maybe_unused]] int foo3()
{
  return 1;
}

[[nodiscard("it has a bug")]] int foo4()
{
  return 1;
}

void commentPlace(int place)
{
  switch (place) {
    case 1:
      std::cout << "very ";

   [[fallthrough]];
    case 2:
      std::cout << "well\n";
    break;

    default:
      std::cout << "OK\n";
    break;
  }
}

namespace [[deprecated]] MyLib
{
  int TSquare2(int x)
  {
    return x*x;
  }
}

enum class City { 
  Berlin = 0,
  NewYork = 1,
  Mumbai = 2, 
  Bombay [[deprecated]] = Mumbai,
};

int main()
{
  foo(1, "hello");
  foo2(2, "hello2");
  foo3();
  foo4();

  commentPlace(1);
  MyLib::TSquare2(2);
  City city = City::Bombay;
  
  return 0;
}

