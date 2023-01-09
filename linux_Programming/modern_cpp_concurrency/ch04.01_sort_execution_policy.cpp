#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <memory> // smart pointers
#include <exception>

#include <execution> // parallel execution policy

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
  std::vector<int> v = {1,2,9,4,8,6,7,5,3};

  auto printVector = [&v]() {
    for(auto i : v)
      cout << i << ' ';
    cout << '\n';
  };

  std::sort(v.begin(), v.end());
  printVector();

  v = {1, 2, 9, 4, 8, 6, 7, 5, 3};
  std::sort(std::execution::seq, v.begin(), v.end());
  printVector();

  v = {1, 2, 9, 4, 8, 6, 7, 5, 3};
  std::sort(std::execution::par, v.begin(), v.end());
  printVector();

  v = {1, 2, 9, 4, 8, 6, 7, 5, 3};
  std::sort(std::execution::unseq, v.begin(), v.end());
  printVector();

  v = {1, 2, 9, 4, 8, 6, 7, 5, 3};
  std::sort(std::execution::par_unseq, v.begin(), v.end());
  printVector();

  // check execution policy:
  std::cout << "sequenced_policy: "
            << std::is_execution_policy<std::execution::sequenced_policy>() << '\n';
  std::cout << "parallel_policy: "
            << std::is_execution_policy<std::execution::parallel_policy>() << '\n';
  std::cout << "unsequenced_policy: "
            << std::is_execution_policy<std::execution::unsequenced_policy>() << '\n';
  std::cout << "parallel_unsequenced_policy: "
            << std::is_execution_policy<std::execution::parallel_unsequenced_policy>() << '\n';
  return 0;
}

