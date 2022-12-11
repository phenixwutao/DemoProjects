#include <iostream>

int main()
{
  // for demo purpose discouraged by Core C++ guidelines
  char buffer[0x2000];
  auto ptr1 = reinterpret_cast<uintptr_t>(buffer);
  auto ptr2 = ptr1 - (ptr1% 0x1000) + 0x1000;
  std::cout << std::hex << std::showbase;
  std::cout << ptr1 << '\n';
  std::cout << ptr2 << '\n';

  return 0;
}
