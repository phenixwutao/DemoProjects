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

/*
 * constinit can be applied to variables with static storage duration or thread storage duration.
 * [1] Global (namespace) variables, static variables, or static class members have
 * static storage duration. These objects are allocated when the program starts,
 * and are deallocated when the program ends.
 *
 * [2] thread_local variables have thread storage duration. Thread-local data is
 * created for each thread that uses this data. thread_local data exclusively
 * belongs to the thread. They are created at its first usage and its lifetime is bound
 * to the lifetime of the thread it belongs to. Often thread-local data is called
 * thread_local storage.
 */

consteval int sqr(int n)
{
return n * n;
}

constexpr auto res1 = sqr(5);
constinit auto res2 = sqr(5);

int main()
{
  cout <<std::boolalpha;
  std::cout << "sqr(5): " << res1 << '\n';
  std::cout << "sqr(5): " << res2 << '\n';

  /*
   * constinit ensures for this kind of variable (static storage duration or
   * thread storage duration) that it is initialized at compile time.
   * constinit does not imply constness.
   */
  constinit thread_local auto res3 = sqr(5);
  std::cout << "sqr(5): " << res3 << '\n';

 return 0;
}
