#include <iostream>
using namespace std;

void* operator new(std::size_t count)
{
  return malloc(count);
}

void* operator new[](std::size_t count)
{
  return malloc(count);
}

void operator delete[](void *ptr)
{
  return free(ptr);
}

int main()
{
  auto ptr = new int;
  delete ptr;
  cout << "ptr: " << ptr << endl;

  auto ptra = new int[5];
  delete[] ptra;
  cout << "ptra: " << ptra << endl;

  return 0;
}
