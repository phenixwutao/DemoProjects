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

constexpr int square(int n)
{ return n*n; }

constinit auto staticA = square(5);

/*
* [1] With C++20, we get two new keywords: consteval and constinit.
* consteval produces a function that is executed at compile time, and
* constinit guarantees that the variable is initialized at compile time.
*
* [2] In contrast to constexpr in C++11, consteval guarantees that the
* function is executed at compile time.
*
* [3]  There are subtle differences between const, constexpr, and constinit. 
* const and constexpr create constant variables. 
* constexpr and constinit are executed at compile time.
*
*/