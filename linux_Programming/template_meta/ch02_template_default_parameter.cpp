#include <iostream>

template <typename T = int, typename U>
class bar { }; // error for class template

template <typename T = int, typename U>
void func() {} // OK for function template

using namespace std;


/********************************************************************************************
* A template may have multiple declarations (but only one definition). The default template
* arguments from all the declarations and the definition are merged (the same way they
* are merged for default function arguments).
********************************************************************************************/
template <typename T, typename U = double>
struct foo;

template <typename T = int, typename U>
struct foo;

template <typename T, typename U>
struct foo
{
  T a;
  U b;
};

// it is equivalent to
template <typename T = int, typename U = double>
struct foo
{
  T a;
  U b;
};


// the right-most type parameter must have a default value
template <typename T = int, typename U>
struct foo; // error, U does not have a default argument

template <typename T, typename U = double>
struct foo;


// error: re-definition of the default parameter
template <typename T = int> // declaration
struct foo;

template <typename T = int> // error redefinition
struct foo {};


int main()
{
  return 0;
}