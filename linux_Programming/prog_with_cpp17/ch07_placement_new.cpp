#include <iostream>

char buf[0x1000];
int main()
{
  // new placement operator to allocate memory from an existing buffer
  // delete operator is NOT needed, because the memory to the object being allocated
  // is user-defined
  auto ptr = new (buf) int;
  std::cout << ptr << std::endl;

  //delete (ptr); // it will abort

  auto ptr1 = new (buf) int;
  auto ptr2 = new (buf+sizeof(int)) int;
  std::cout << ptr1 << '\n';
  std::cout << ptr2 << '\n';

  return 0;
}
