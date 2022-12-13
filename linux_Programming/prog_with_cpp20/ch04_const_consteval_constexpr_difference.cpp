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

// runs at run time
int sqrRunTime(int n)
{
  return n * n;
}

// runs at compile time
consteval int sqrCompileTime(int n)
{
  return n * n;
}

// run at compile time or run time
constexpr int sqrRunOrCompileTime(int n)
{
  return n * n;
}

int main()
{
  cout <<std::boolalpha;
  
  // constexpr int prod1 = sqrRunTime(100); //ERROR
  constexpr int prod2 = sqrCompileTime(100);
  constexpr int prod3 = sqrRunOrCompileTime(100);

  int x = 100;
  int prod4 = sqrRunTime(x);
  
  // int prod5 = sqrCompileTime(x); //ERROR x is not const
  int prod6 = sqrRunOrCompileTime(x);

  // more tests
  static_assert(sqrRunOrCompileTime(10) == 100); // compile time
 
  int arrayNewWithConstExpressiomFunction[sqrRunOrCompileTime(100)]; // compile time
 
  constexpr int prod = sqrRunOrCompileTime(100); // compile time

  int a = 100;
  int runTime = sqrRunOrCompileTime(a); // run time

  int runTimeOrCompiletime = sqrRunOrCompileTime(100); // run time or compile time

  int alwaysCompileTime = sqrCompileTime(100); // compile time
  
  return 0;
}
