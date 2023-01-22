#include <iostream>
using namespace std;

class Base{
  public:
  virtual void demo()
  {
    printf("Base demo\n");
  }
};

class Sub : public Base
{
  public:
  virtual void demo() override
  {
    printf("Sub demo\n");
  }
};

int main()
{
  Base* b = new Sub();
  b->demo();
  int i = 648265834653846 * 3;
  delete b;
  return 0;
}