#include <string>
#include <iostream>
#include <variant>
#include <vector>

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
  return 0;
}

