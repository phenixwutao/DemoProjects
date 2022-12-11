#include <iostream>
using namespace std;

alignas(0x1000) char buf[0x1000];
int main()
{
  auto ptr = new (buf) int;
  cout << "ptr  is " << ptr << endl;

  auto ptr1 = new (buf) int[20];
  cout << "ptr1 is " << ptr1 << endl;
  return 0;
}
