#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <utility> // Date and time utilities
#include <atomic>
#include <future>

#include <chrono>
#include <functional> // std::function<>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

void function1(std::stop_token stopToken, const string& str)
{
  std::this_thread::sleep_for(1s);
  if (stopToken.stop_requested())
    std::cout << str << " : stop requested\n\n";
}

void function2(std::promise<void> prom, std::stop_token stopToken, const string& str)
{
  std::this_thread::sleep_for(1s);
  std::stop_callback cb(stopToken, [&str]()
                        { cout << str << " : Stop requested\n"; });
  prom.set_value();
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::stop_source stopSource;

  std::stop_token stpToken = stopSource.get_token();
  std::thread thr1(function1, stpToken, "std::thread");

  std::jthread jthr(function1, stpToken, "std::jthread");

  auto fut1 = std::async([stpToken]() {
                          std::this_thread::sleep_for(1s); 
                         if (stpToken.stop_requested())
                         {
                           cout << "std::async : Stop requested\n";
                         } 
                         });

  std::promise<void> prom;
  auto fut2 = prom.get_future();
  std::thread thr2(function2, std::move(prom), stpToken, "std::promise");
  stopSource.request_stop();

  if (stpToken.stop_requested())
    std::cout << "main: Stop requested\n";

  //std::this_thread::sleep_for(2s);
  thr1.join();
  thr2.join();
  return 0;
}

