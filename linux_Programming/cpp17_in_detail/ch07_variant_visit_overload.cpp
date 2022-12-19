#include <string>
#include <iostream>
#include <variant>
#include <vector>
#include <type_traits>

using namespace std;

struct MultiplyVisitor
{
  float mFactor;
  MultiplyVisitor(float factor) : mFactor(factor) { }
  
  void operator()(int& i) const {
    i *= static_cast<int>(mFactor);
  }
  
  void operator()(float& f) const {
    f *= mFactor;
  }
  
  void operator()(std::string& ) const {
    // nothing to do here...
  }
};

// helper struct
template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

int main()
{
  {
    // a generic lambda:
    auto PrintVisitor = [](const auto& t) { std::cout << t << '\n'; };
    std::variant<int, float, std::string> intFloatString { "Hello" };
    std::visit(PrintVisitor, intFloatString);
  }

  {
    auto PrintVisitor = [](const auto& t) { std::cout << t << '\n'; };
    auto TwiceMoreVisitor = [](auto& t) { t*= 2; };
    std::variant<int, float> intFloat { 20.4f };
    std::visit(PrintVisitor, intFloat);
    std::visit(TwiceMoreVisitor, intFloat);
    std::visit(PrintVisitor, intFloat);
  }

  {
    auto PrintVisitor = [](const auto& t) { std::cout << t << '\n'; };
    std::variant<int, float> intFloat { 20.4f };
    std::visit(MultiplyVisitor(0.5f), intFloat);
    std::visit(PrintVisitor, intFloat);
  }

  {
    std::variant<int, float, std::string> myVariant;
    std::visit(
	       overload {
		   [](const int& i) { std::cout << "int: " << i; },
		   [](const std::string& s) { std::cout << "string: " << s; },
		   [](const float& f) { std::cout << "float: " << f; }
		   },
	       myVariant
	       );
    
    auto PrintVisitor = [](const auto& t) { std::cout << " PrintVisitor " << t << '\n'; };
    std::visit(PrintVisitor, myVariant);
  }

  {
    std::variant<int, float, char> v1 { 's' };
    std::variant<int, float, char> v2 { 10 };
    std::visit(overload{
	[](int a, int b) { },
	  [](int a, float b) { },
	  [](int a, char b) { },
	  [](float a, int b) { },
	  [](float a, float b) { },
	  [](float a, char b) { },
	  [](char a, int b) { },
	  [](char a, float b) { },
	  [](char a, char b) { }
	  }, v1, v2);
  }
  return 0;
}

