#include <iostream>
#include <type_traits> // static_assert
#include <utility> // pair utility
#include <tuple>

using namespace std;

namespace X
{
  namespace Y
  {
    namespace Z
    {
      auto message = "nested XYZ Hello world";
    }
  }
}

namespace A::B::C {
      auto message = "nested ABC Hello world";
}

// inline variable
inline auto msg_inline = "Hello World Inline";

int main()
{
  // chapter 4 code example 1
  {
    if (auto i = 42; i >0)
      {
	cout << "if hellow world" << endl;
      }

    switch(auto j = 42)
      {
      case 42:
	cout << "switch hello world" << endl;
	break;

      default:
	break;
      }
  }

  // chapter 4 code example 2
  {
    constexpr const auto val = true;
    if(val)
      {
	cout << "constexpr hello world " << endl;
      }
  }

  // chapter 4 code example 3
  {
    // if the expression is not const, then compiler will throw error
    if constexpr (constexpr const auto i = 42; i > 0)
		   {
		     cout << "if constexpr hello world " << endl;		     
		   }
  }

  // chapter 4 code example 4
  {
    constexpr const int i = 42;
    // static_assert ensures that certain compile-time assumptions are true
    // compile error: static assertion failed: the answer if not equal to 42
    static_assert(i == 42, "the answer failed on static_assert");
  }

  // chapter 4 code example 5
  {
    // nested namespaces
    cout << X::Y::Z::message << endl;
    cout << A::B::C::message << endl;
  }
  
  // chapter 4 code example 6
  {
    auto give_me_pair = []() -> std::pair<const char*, int> // specify return type
    {
      return {"the answer is ", 42};
    };
    
    //std::pair<const char*, int> pair = give_me_pair();
    auto pair = give_me_pair();
    cout << std::get<0>(pair) << " " << std::get<1>(pair) << endl;
  }

  // chapter 4 code example 7
  {
    auto give_me_pair = []() -> std::pair<const char*, int> // specify return type
    {
      return {"the answer is ", 42};
    };
    
    // use structures binding:
    auto [msg, answer] = give_me_pair();
    cout << "structured binding: " << msg << " => " << answer << endl;
  }

  // chapter 4 code example 8
  {
    struct mystruct
    {
      const char* msg;
      int answer;
    };
    auto give_me_mystructure = []() -> std::pair<const char*, int>
    {
      return {"struct msg is", 42};
    };
    auto [msg, answer] = give_me_mystructure();
    cout << "give_me_mystructure " << msg << " ," << answer << endl;

    cout << msg_inline << endl;
  }

  // chapter 4 code example 0
  {
  }
  return 0;
}

