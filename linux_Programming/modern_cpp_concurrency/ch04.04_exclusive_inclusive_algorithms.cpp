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

#include <algorithm>
#include <numeric>

using namespace std;
using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::vector<int> v{1, 2, 3, 4, 5};
  auto res1 = std::accumulate(v.begin(), v.end(), 1, [](int a, int b)
                 { return a * b; });
  cout << "res1 " << res1 << '\n';
  auto res2 = std::reduce(std::execution::par, v.begin(), v.end(), 1, [](int a, int b)
                          { return a * b; });
  cout << "res2 " << res2 << '\n';

  // test for_each_n
  cout <<"for_each_n\n";
  std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::for_each_n(std::execution::par, intVec.begin(), 5, [](int &arg)
                  { arg *= arg; });
  for (auto &v : intVec)
    cout << v << ' ';
  cout <<'\n';

  // test exclusive_scan and inclusive_scan
  std::vector<int> resVec  {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::exclusive_scan(std::execution::par, resVec.begin(), resVec.end(),
                      resVec.begin(), 1, 
                      [](int fir, int sec)
                      { return fir * sec; });
  std::cout << "exclusive_scan: ";
  for (auto v: resVec) std::cout << v << " ";
  std::cout << '\n';

  {
    std::vector<int> resVec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::exclusive_scan(resVec.begin(), resVec.end(), resVec.begin(), 1,
                        [](int fir, int sec)
                        { return fir * sec; });

    std::cout << "exclusive_scan: ";
    for (auto v : resVec)
      std::cout << v << " ";
    std::cout << '\n';
  }

  // inclusive_scan
  std::vector<int> resVec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::inclusive_scan(resVec2.begin(), resVec2.end(), resVec2.begin(),
                      [](int fir, int sec)
                      { return fir * sec; });
  std::cout << "inclusive_scan: ";
  for (auto v: resVec2) std::cout << v << " ";
  std::cout << '\n';

  // transform_exclusive_scan and transform_inclusive_scan
  std::vector<int> resVec3{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> resVec4(resVec3.size());
  std::transform_exclusive_scan(
      std::execution::par,            // execution policy
      resVec3.begin(), resVec3.end(), // start, end range
      resVec4.begin(), 0,             // result range and init value
      [](auto fir, int sec)
      { return fir + sec; },          // binary operation
      [](auto arg)
      { return arg * arg; });         // unary operation

  std::cout << "transform_exclusive_scan: ";
  for (auto v : resVec4)
    std::cout << v << " ";
  std::cout << '\n';

  std::vector<std::string> strVec{"Only", "for", "testings", "purpose"};
  std::vector<int> resVec5(strVec.size());

  std::transform_inclusive_scan(
      std::execution::par,
      strVec.begin(), strVec.end(),
      resVec5.begin(),
      [](auto fir, auto sec) { return fir + sec; },
      [](auto s) { return s.length(); },
      static_cast<std::size_t>(0));

  std::cout << "transform_inclusive_scan: ";
  for (auto v : resVec5)
    std::cout << v << " ";
  std::cout << "\n\n";

  // reduce and transform_reduce
  std::vector<std::string> strVec2{"Only", "for", "testing", "purpose"};

  std::string res = std::reduce(std::execution::par,
                                strVec2.begin() + 1, strVec2.end(), strVec2[0],
                                [](auto fir, auto sec)
                                { return fir + ":" + sec; });

  std::cout << "reduce: " << res << '\n';

  auto res7 = std::transform_reduce(
      std::execution::par,
      strVec2.begin(), strVec2.end(), static_cast<std::size_t>(0),
      [](auto a, auto b) { return a + b; },
      [](std::string s)  { return s.length(); });

  std::cout << "transform_reduce: " << res7 << '\n';
  std::cout << '\n';

  return 0;
}

