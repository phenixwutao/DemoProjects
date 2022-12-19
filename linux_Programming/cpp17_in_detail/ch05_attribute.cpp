#include <iostream>

using namespace std;

static void impl1() { } // Compilers may warn about this

[[maybe_unused]] static void impl2() { } // Warning suppressed

void foo() {
  int x = 42; // Compilers may warn about this
  [[maybe_unused]] int y = 42; // Warning suppressed
}

enum class [[nodiscard]] ErrorCode {
  OK,
  Fatal,
  System,
  FileIssue
};


[[nodiscard]] int compute(){return 1;}

void test1()
{
  compute();
}

void test2()
{
  static_cast<void>(compute()); // fine
  
  [[maybe_unused]] auto ret = compute();
  auto ret2 = compute(); // warning: unused variable ret2
}

// deprecated with specification
namespace [[deprecated("use BetterUtils")]] GoodUtils
{
  void DoStuff() { }
}

namespace BetterUtils
{
  void DoStuff() { }
}

// deprecated with specification
enum class ColorModes
  {
    RGB [[deprecated("use RGB8")]],
    RGBA [[deprecated("use RGBA8")]],
    RGBA16F,
    RGB8,
    RGBA8
  };


// The feature simplifies the case where you want to use multiple attributes, like:
void f()
{
  [[using rpr: kernel, target(cpu,gpu)]]
  doTask();
}

// warning: function declared 'noreturn' has a 'return' statement
[[noreturn]] void MyFunc() noexcept
{
  return 3;
}

/*
 * All Attributes available in C++17: (page 71/90)
 * [[noreturn]]
 * [[carries_dependency]]
 * [[deprecated]]
 * [[deprecated("reason")]]
 * [[fallthrough]]
 * [[nodiscard]]
 * [[maybe_unused]]
 */
int main()
{
  GoodUtils::DoStuff();

  [[maybe_unused]] auto colMode = ColorModes::RGBA;
  
  return 0;
}

