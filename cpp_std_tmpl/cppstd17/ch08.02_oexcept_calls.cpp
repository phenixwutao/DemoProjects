#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>

#include <map>

using namespace std;

template<typename T1, typename T2>
void call(T1 op1, T2 op2)
{
  op1();
  op2();
}

void f1()
{
  printf("call f1()\n");
}

void f2() noexcept
{
  printf("call f2() noexcept\n");
}

int main()
{
  call(f1, f2);
  return 0;
}

