#include <iostream>

int bss_mem = 0; // global memory: zero initialised
int data_mem = 4; // global memory: value initialised


alignas(0x1000) int ptra[42]; // allocate array with memory address alignment

int main()
{
  int stack_mem = 2; // stack memory
  std::cout << bss_mem << '\n';
  std::cout << data_mem << '\n';
  std::cout << stack_mem << '\n';

  alignas(0x10000) int ptrb[42]; // allocate array with memory address alignment
  // OS will allocate memory, the pointer is moved to align the int array.

  return 0;
}
