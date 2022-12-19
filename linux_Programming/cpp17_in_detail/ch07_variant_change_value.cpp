#include <string>
#include <iostream>
#include <variant>
#include <vector>

using namespace std;

// monostate for default initialisation:
class NotSimple
{
public:
  NotSimple(int, float) { }
};


class MyType
{
public:
  MyType() { std::cout << "MyType::MyType\n"; }
  ~MyType() { std::cout << "MyType::~MyType\n"; }
};
class OtherType
{
public:
  OtherType() { std::cout << "OtherType::OtherType\n"; }
  ~OtherType() { std::cout << "OtherType::~OtherType\n"; }
};


int main()
{
  {
    // default initialisation: (the first type has to have a default ctor)
    std::variant<int, float> intFloat;
    std::cout << intFloat.index() << ", val: " << std::get<int>(intFloat) << '\n';

    // std::variant<NotSimple, int> cannotInit; // error
    // std::monostate allows you to build a variant with "no-value"
    // so it can behave similarly to std::optional
    std::variant<std::monostate, NotSimple, int> okInit;
    std::cout << okInit.index() << '\n';

    // pass a value:
    std::variant<int, float, std::string> intFloatString { 10.5f };
    std::cout << intFloatString.index()
	      << ", value " << std::get<float>(intFloatString) << '\n';
    // ambiguity
    // double might convert to float or int, so the compiler cannot decide
    //std::variant<int, float, std::string> intFloatString { 10.5 };
  
    // ambiguity resolved by in_place
    variant<long, float, std::string> longFloatString {
      std::in_place_index<1>, 7.6 // double!
    };
    std::cout << longFloatString.index() << ", value "
	      << std::get<float>(longFloatString) << '\n';
  
    // in_place for complex types
    std::variant<std::vector<int>, std::string> vecStr {
      std::in_place_index<0>, { 0, 1, 2, 3 }
    };
    std::cout << vecStr.index() << ", vector size "
	      << std::get<std::vector<int>>(vecStr).size() << '\n';
  
    // copy-initialize from other variant:
    std::variant<int, float> intFloatSecond { intFloat };
    std::cout << intFloatSecond.index() << ", value "
	      << std::get<int>(intFloatSecond) << '\n';

    // in-place to specify the index
    std::variant<int, float> intFloat3 { std::in_place_index<0>, 10.5f };

    // in-place to specify the type
    std::variant<int, float> intFloat4 { std::in_place_type<int>, 10.5f };
  }


  {
    // Change Variant
    std::variant<int, float, std::string> intFloatString { "Hello" };
    std::string s = std::get<2>(intFloatString);
    cout << "s= " << s << '\n';
    
    intFloatString = 10; // we're now an int
    int testint = std::get<0>(intFloatString);
    cout << "testint= " << testint << '\n';

    if (const auto intPtr = std::get_if<0>(&intFloatString))
      std::cout << "int=" << *intPtr << '\n';
    
    intFloatString.emplace<2>(std::string("Hello")); // we're now string again
    
    // std::get returns a reference, so you can change the value:
    std::get<std::string>(intFloatString) += std::string(" World");
    
    intFloatString = 10.1f;
    
    if (auto pFloat = std::get_if<float>(&intFloatString); pFloat)
      *pFloat *= 2.0f;
  }

  {
    std::variant<MyType, OtherType> v;
    v = OtherType();
  }
 
  return 0;
}

