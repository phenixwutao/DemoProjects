#include <iostream>
#include <string_view> // C++17 std
#include <any>         // std::any
#include <variant>     // std::variant (union)
#include <optional>    // std::optional

/******************************************
* GSL (Guideline Support Library)
******************************************/
//#include <gsl/gsl>

using namespace std;

class myclass
{
public:
  int val;
  myclass(int v) : val(v)
  {
    cout << "constructted" << endl;
  }
};

int main()
{
  // test string_view
  {
    string_view str("hello world");
    cout << str << endl;
    cout << str.front() << endl; // get first char
    cout << str.back() << endl; // get last char
    cout << str.at(1) << endl; // index
    cout << str.data() << endl; // get the underline array
    cout << "size " << str.size() << endl;
    cout << "max size " << str.max_size() << endl;
    cout << "empty " << str.empty() << endl;
  }
  
  // test change size
  {
    string_view str("hello world");
    str.remove_prefix(1);
    str.remove_suffix(1);
    cout << str << endl;
  }
  // test sub string
  {
    string_view str("hello world");
    cout << str.substr(0,5) << endl;
  }
  
  // test compare string
  {
    string_view str("Hello World");
    if (str.compare("Hello World") == 0)
      {
	cout << "Hello World" << endl;
      }
    cout << str.compare("Hello") << endl;
    cout << str.compare("World") << endl;
  }

  // test string find
  {
    std::string_view str("Hello this is a test of Hello World");
    std::cout << str.find("Hello") << '\n';
    std::cout << str.rfind("Hello") << '\n';
    std::cout << str.find_first_of("Hello") << '\n';
    std::cout << str.find_last_of("Hello") << '\n';
    std::cout << str.find_first_not_of("Hello") << '\n';
    std::cout << str.find_last_not_of("Hello") << '\n';
    cout << "find_last_of(\"Hello\") " << endl;
    std::cout << str.find_last_of("Hello") << '\n';
  }
  
  // test any and variant
  {
    auto myany = std::make_any<int>(42);
    cout << std::any_cast<int>(myany) << endl;

    myany = 4.2;
    cout << std::any_cast<double>(myany) << endl;

    struct mystruct {
      int data1;
    };
    myany = mystruct{42};
    cout << std::any_cast<mystruct>(myany).data1 << endl;
    
  }
  
  // test variant
  {
    std::variant<int, double> v = 4;
    cout << std::get<int>(v) << endl;
    v = 1.3;
    cout << std::get<double>(v) << endl;
  }

  // test optional
  {
    std::optional<myclass> o;
    cout << "myclass is created, but not constructed" << endl;
    if (o)
      {
	cout << "Attempt #1: " << o->val << endl;
      }
    o = myclass{5};
    if (o)
      {
	cout << "Attempt #2: " << o->val << endl;
      }    
  }
  
  // test 
  {
  }
  // test 
  {
  }
  // test 
  {
  }
  // test 
  {
  }
  // test 
  {
  }
  return 0;
}
