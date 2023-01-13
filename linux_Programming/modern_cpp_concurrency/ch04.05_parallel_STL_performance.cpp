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
#include <cmath>

#include <condition_variable>

#include <algorithm>
#include <numeric>
#include <random>

using namespace std;
using namespace std::chrono_literals;

constexpr long long kSize = 250'000'000;

const double pi = std::acos(-1);

template <typename Func>
void getExecutionTime(const std::string &title, Func func)
{
  const auto start = std::chrono::steady_clock::now();
  func();
  const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - start;
  std::cout << title << ": " << dur.count() << " sec. " << '\n';
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::vector<double> randValues;
  randValues.reserve(kSize);

  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (long long i = 0; i < kSize; ++i)
    randValues.push_back(uniformDist(engine));

  std::vector<double> workVec(randValues);

  getExecutionTime("std::execution::seq", [workVec]() mutable
                   { std::transform(std::execution::seq, workVec.begin(), workVec.end(),
                                    workVec.begin(),
                                    [](double arg)
                                    { return std::tan(arg); }); });

  getExecutionTime("std::execution::par", [workVec]() mutable
                   { std::transform(std::execution::par, workVec.begin(), workVec.end(),
                                    workVec.begin(),
                                    [](double arg)
                                    { return std::tan(arg); }); });

  getExecutionTime("std::execution::par_unseq", [workVec]() mutable
                   { std::transform(std::execution::par_unseq, workVec.begin(), workVec.end(),
                                    workVec.begin(),
                                    [](double arg)
                                    { return std::tan(arg); }); });

  std::cout << '\n';
  return 0;
}
