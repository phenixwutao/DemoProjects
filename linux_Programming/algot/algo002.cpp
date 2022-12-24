#include <iostream>
using namespace std;

unsigned long fib(unsigned long n)
{
  // unsigned long prevfib = 0;
  // unsigned long currfib = 0;
  // 0  1    2   3   4   5
  // 1  1    2   3   5   6
  //    prev cur new
  unsigned long val = 0;
  if (n <= 0) return 1;
  
  for (unsigned long i = 0, prevfib = 1, currfib = 1; i < n; ++i)
  {
    int newfib = prevfib + currfib;
    val = prevfib;
    //printf("i %lu  prevfib %lu, currfib %lu, newfib %lu\n", i, prevfib, currfib, newfib);
    prevfib = currfib;
    currfib = newfib;
    //printf("i %lu  prevfib %lu, currfib %lu, newfib %lu\n", i, prevfib, currfib, newfib);
  }
  return val;
}


int main()
{
  for (unsigned long i =0; i <=8; ++i)
    std::cout << "fib(" <<i << "): " << fib(i) << '\n';
	return 0;
}
