#include <iostream>
using aligned_int alignas(0x1000) = int;

int main()
{
  // new nothrow: when new operator failed, it doesn't throw exception, just return nullptr
  auto ptr = new (std::nothrow) int[42];
  std::cout << "new (std::nothrow) int " << ptr << std::endl;
  delete[] ptr;

  auto ptr1 = new (std::nothrow) aligned_int[42];
  std::cout << "new (std::nothrow) aligned_int[] " << ptr1 << std::endl;
  delete[] ptr1;

  return 0;
}
