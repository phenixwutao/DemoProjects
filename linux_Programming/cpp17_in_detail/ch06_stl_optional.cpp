#include <optional>
#include <iostream>
#include <vector>
#include <complex>
#include <utility>

using namespace std;

class UserName
{
public:
  UserName() : mName("Default") { }
private:
  std::string mName;
};

struct Point
{
  Point(int a, int b) : x(a), y(b) { }
  int x;
  int y;
};

std::optional<std::string> CreateString1()
{
  std::string str {"Hello Super Awesome Long String"};
  return {str}; // this one will cause a copy
  // return str; // this one moves
}

std::optional<std::string> CreateString2()
{
  std::string str {"Hello Super Awesome Long String"};
  //return {str}; // this one will cause a copy
  return str; // this one moves
}

int main()
{
  // empty:
  std::optional<int> oEmpty;
  std::optional<float> oFloat = std::nullopt;
  
  // direct:
  std::optional<int> oInt(10);
  std::optional oIntDeduced(10); // deduction guides
  
  // make_optional
  auto oDouble = std::make_optional(3.0);
  auto oComplex = std::make_optional<std::complex<double>>(3.0, 4.0);
  
  // in_place
  std::optional<std::complex<double>> o7{std::in_place, 3.0, 4.0};
  
  // will call vector with direct init of {1, 2, 3}
  std::optional<std::vector<int>> oVec(std::in_place, {1, 2, 3});
  
  // copy from other optional:
  auto oIntCopy = oInt;


  std::optional<UserName> u0; // empty optional
  std::optional<UserName> u1{}; // also empty
  
  // optional with default constructed object:
  std::optional<UserName> u2{UserName()};

  std::optional<UserName> opt{std::in_place}; // more efficient construction

  auto opt1 = std::make_optional<UserName>();
  auto opt2 = std::make_optional<Point>(0, 0);
  std::optional<UserName> opt3{std::in_place};
  std::optional<Point>    opt4{std::in_place, 0, 0};
 
  return 0;
}

