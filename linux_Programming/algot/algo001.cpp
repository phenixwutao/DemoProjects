#include <iostream>
using namespace std;

class Test {
};

class Test2 {
public:
  virtual ~Test2(){}
};

class TestS {
  char a;
  static int b;
};


class Test3 {
public:
  Test3(const Test2& obj){}
};

class Base {
public:
  virtual void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base {
private:
  void f() { cout << "Derived::f()" << endl; }
};

int main()
{
  {
    Test t;
    Test2 t2;
    cout << sizeof(Test) << ", sizeof(char): " << sizeof(char) << '\n';
    cout << sizeof(t) << '\n';
    Test2 *tp;
    cout << sizeof(Test2) << '\n';
    cout << sizeof(t2) << '\n';
    cout << "sizeof(Test2*) " << sizeof(Test2*) << '\n';
    cout << "sizeof(TestS) " << sizeof(TestS) << '\n';

    // compile error: if user-defined copy-ctor is supplied, default constructor is not defined by the compiler
    //Test3 t3;
  }

  {
  	const char* p = "Test";
  	std::cout << *p++ << std::endl;
  }

  {
    // Compile error: In C++ a non-const reference cannot bind to a temporary object.
    // auto testfunc = [](std::string& s){};
    // testfunc("test");
  }

  {
    // access control is checked at compiler time
    Base* p = new Derived();
    p->f();

    Derived d1;
    Base& b1 = d1;
    b1.f();
  }
	return 0;
}
