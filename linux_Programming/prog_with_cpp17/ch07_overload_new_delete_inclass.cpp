#include <iostream>
using namespace std;

class demo
{
public:
  void* operator new(std::size_t size)
  {
    cout << "call demo::new" << endl;
    return ::operator new(size);
  }

  void operator delete(void* ptr)
  {
    cout << "call demo::delete" << endl;
    ::operator delete(ptr);
  }

  void* operator new[](std::size_t size)
  {
    cout << "call demo::new[]" << endl;
    return ::operator new[](size);
  }

  void operator delete[](void* ptr)
  {
    cout << "call demo::delete[]" << endl;
    ::operator delete[](ptr);
  }
};

int main()
{
  auto ptr = new demo;
  delete ptr;
  cout << "ptr: " << ptr << endl;

  auto ptr2 = new demo[5];
  delete[] ptr2;
  cout << "ptr2: " << ptr2 << endl;
  return 0;
}
