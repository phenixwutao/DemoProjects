#include <map>
#include <iostream>
#include <string>
using namespace std;


int main()
{
  // constexpr lambda function
  auto SimpleLambda = [] (int n) constexpr { return n; };
  static_assert(SimpleLambda(3) == 3, "");
  
  return 0;
}

