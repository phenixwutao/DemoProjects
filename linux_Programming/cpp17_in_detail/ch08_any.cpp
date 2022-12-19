// page 318
#include <iostream>
#include <variant>
#include <any>
#include <cassert>

#include <map>
#include <vector>

using namespace std;


struct MyType
{
  MyType(int x, int y) : a(x), b(y){}
  void Print() { std::cout << a << ", " << b << '\n'; }
  int a;
  int b;
};

int main()
{
  {
    std::any a(12);
    // set any value:
  
    a = std::string("Hello!");
    a = 16;
  
    // reading a value: std::any_cast<type>
    // we can read it as int
    std::cout << std::any_cast<int>(a) << '\n';
  
    // but not as string:
    try
      {
	std::cout << std::any_cast<std::string>(a) << '\n';
      }
    catch(const std::bad_any_cast& e)
      {
	std::cout << e.what() << '\n';
      }

    // reset and check if it contains any value:
    a.reset();
    if (!a.has_value())
      {
	std::cout << "a is empty!" << '\n';
      }
    
    // you can use it in a container:
    std::map<std::string, std::any> m;
    m["integer"] = 10;
    m["string"] = std::string("Hello World");
    m["float"] = 1.0f;

    // use structured binding with reference access:
    for (auto &[key, val] : m)
      {
	if (val.type() == typeid(int))
	  std::cout << "int: " << std::any_cast<int>(val) << '\n';
	else if (val.type() == typeid(std::string))
	  std::cout << "string: " << std::any_cast<std::string>(val) << '\n';
	else if (val.type() == typeid(float))
	  std::cout << "float: " << std::any_cast<float>(val) << '\n';
      }
  }

  // create any object
  {
    // default initialisation:
    std::any a;
    assert(!a.has_value());
    
    // initialisation with an object:
    std::any a2{10}; // int
    std::any a3{MyType{10, 11}};
    
    // in_place:
    std::any a4{std::in_place_type<MyType>, 10, 11};
    
    std::any a5{std::in_place_type<std::string>, "Hello World"};
    
    // make_any
    std::any a6 = std::make_any<std::string>("Hello World");
  }

  // change any value
  {
    std::any a;
    a = MyType(10, 11);
    a = std::string("Hello");
    a.emplace<float>(100.5f);
    a.emplace<std::vector<int>>({10, 11, 12, 13});
    a.emplace<MyType>(10, 11);
  }

  // read/access any value
  {
    std::any var = std::make_any<MyType>(10, 10);
    try
      {
	std::any_cast<MyType&>(var).Print();
	std::any_cast<MyType&>(var).a = 11; // read/write
	std::any_cast<MyType&>(var).Print();
	std::any_cast<int>(var); // throw!
      }
    catch(const std::bad_any_cast& e)
      {
	std::cout << e.what() << '\n';
      }
    
    int* p = std::any_cast<int>(&var);
    std::cout << (p ? "contains int... \n" : "doesn't contain an int...\n");
    
    if (MyType* pt = std::any_cast<MyType>(&var); pt)
      {
	pt->a = 12;
	std::any_cast<MyType&>(var).Print();
      }
  }
  return 0;
}
