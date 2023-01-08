#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <memory> // smart pointers
#include <exception>

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <utility> // Date and time utilities
#include <atomic>
#include <future>
#include <semaphore>
#include <latch>
#include <barrier>

#include <chrono>
#include <functional> // std::function<>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

struct Div
{
  void operator()(std::promise<int> &&intPromise, int a, int b)
  {
    try
    {
      if (b == 0)
      {
        std::string errMess = std::string("Illegal division by zero: ") +
                              std::to_string(a) + "/" + std::to_string(b);
        throw std::runtime_error(errMess);
      }
      intPromise.set_value(a / b);
    }
    catch (...)
    {
      intPromise.set_exception(std::current_exception());
    }
  }
};

void executionDivision(int nom, int denom)
{
  std::promise<int> divPromise;
  std::future<int> divResult = divPromise.get_future();
  Div div;
  std::jthread divThread(div, std::move(divPromise), nom, denom);

  try {
    cout << nom << "/" << denom << "=" << divResult.get() << '\n';
  }
  catch(std::runtime_error& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  executionDivision(20,0);
  executionDivision(20,10);
  return 0;
}

