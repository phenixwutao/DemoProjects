#include <iostream>

int bss_mem = 0; // global memory: zero initialised
int data_mem = 4; // global memory: value initialised

int main()
{
  int stack_mem = 2; // stack memory
  std::cout << bss_mem << '\n';
  std::cout << data_mem << '\n';
  std::cout << stack_mem << '\n';
  return 0;
}
