#include <iostream>
#include <iomanip>
#include <string>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility> // Date and time utilities
#include <atomic>

#include <chrono>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::jthread noninterruptable([]()
                                { int counter(0);
                                while(counter < 10){
                                  std::this_thread::sleep_for(0.2s);
                                  std::cerr << "noninterruptable " << counter << '\n';
                                  ++counter;
                                } });

  std::jthread interrutable([](std::stop_token stop_token)
                            { int counter{0};
                            while(counter < 10)
                            {
                              std::this_thread::sleep_for(0.2s);
                              if (stop_token.stop_requested()) {
                                cerr << "interruptable: Stop on request!\n";
                                return;
                              }
                              std::cerr << "interruptable " << counter << '\n';
                            } });

  this_thread::sleep_for(1s);
  cerr << "Main thread trying to interrupt both threads\n";
  noninterruptable.request_stop();
  interrutable.request_stop();

  return 0;
}

