#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <memory> // smart pointers
#include <exception>

#include <execution> // parallel execution policy
#include <stdexcept>

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

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::vector<int> myvec{1,2,3,4,5};
  try
  {
    // can catch exception if without execution policy
    std::for_each(myvec.begin(), myvec.end(), [](int)
                  { throw std::runtime_error("without execution policy"); });
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  try
  {
    // can NOT catch exception if with execution policy
    std::for_each(std::execution::seq, myvec.begin(), myvec.end(),
                  [](int) { throw std::runtime_error("With execution policy"); });
  }
  catch(const std::runtime_error& e)
  {
    std::cerr << e.what() << '\n';
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
  catch(...)
  {
    std::cout << "catch all exceptions\n";
  }
  return 0;
}

