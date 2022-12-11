#include <iostream>
using namespace std;

class demo
{
public:
  void* operator new(std::size_t size, std::align_val_t al)
  {
    cout << "call demo::new align" << endl;
    return ::operator new(size, al);
  }

  void operator delete(void* ptr, std::align_val_t al)
  {
    cout << "call demo::delete align" << endl;
    ::operator delete(ptr, al);
  }

  void* operator new[](std::size_t size, std::align_val_t al)
  {
    cout << "call demo::new[] align" << endl;
    return ::operator new[](size, al);
  }

  void operator delete[](void* ptr, std::align_val_t al)
  {
    cout << "call demo::delete[] align" << endl;
    ::operator delete[](ptr, al);
  }
};

using aligned_myclass alignas(0x1000) = demo;

int main()
{
  auto ptr = new aligned_myclass;
  delete ptr;
  cout << "aligned ptr: " << ptr << endl;

  auto ptr2 = new aligned_myclass[5];
  delete[] ptr2;
  cout << "aligned ptr2: " << ptr2 << endl;
  return 0;
}
