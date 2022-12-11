#include <thread>
#include <iostream>
#include <memory>

// test code for memory map allocation with shared pointer

int main()
{
  auto ptr1 = std::make_shared<myclass1>();
  auto ptr2 = std::make_shared<myclass2>();
  ptr1->m = ptr2; // weak pointer doesn't increment counter, doesn't access ownership
  ptr2->m = ptr1;

  // covert unique pointer to shared pointer
  auto pp = make_unique<int>();
  shared_ptr<int> p2 = std::move(pp);
  p2 = 4;
  return 0;
}
