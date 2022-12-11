#include <iostream>
using namespace std;

void needInt(int i)
{
  cout << "int " << i << endl;
}

int main()
{
  cout << std::boolalpha << '\n';
  double d {1.234};
  cout << "double " << d << endl;
  needInt(d);

  bool b {true};
  cout << "bool: " << b << endl;
  needInt(b);
  return 0;
}
