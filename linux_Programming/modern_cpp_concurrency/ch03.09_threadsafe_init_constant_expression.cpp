#include <iostream>
#include <iomanip>
#include <string>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <utility> // Date and time utilities
#include <atomic>

#include <chrono>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

class MyDouble
{
private:
  double val1;
  double val2;
public:
  constexpr MyDouble(double v1, double v2) : val1(v1), val2(v2) {}
  constexpr double getSum() const { return val1 + val2; }
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  constexpr double MyStatVal = 2.0;
  constexpr MyDouble MyStatic(10.6, MyStatVal);
  constexpr double sum_val = MyStatic.getSum();
  return 0;
}

