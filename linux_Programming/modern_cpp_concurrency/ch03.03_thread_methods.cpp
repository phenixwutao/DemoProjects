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
  cout << "hardware_concurrency " << thread::hardware_concurrency() << '\n';

  thread t1([]
            { cout << "t1 with id= " << this_thread::get_id() << '\n'; });

  thread t2([]
            { cout << "t2 with id= " << this_thread::get_id() << '\n'; });

  cout << "from main: t1 id " << t1.get_id() << '\n';
  cout << "from main: t2 id " << t2.get_id() << '\n';
  cout << "swap t1 and t2\n";
  swap(t1, t2);
  cout << "from main: t1 id " << t1.get_id() << '\n';
  cout << "from main: t2 id " << t2.get_id() << '\n';

  cout <<'\n';
  cout << "Main thread id= " << this_thread::get_id() << '\n';
  cout << "t1 joinable: " << t1.joinable() << '\n';
  t1.join();
  t2.join();

  cout << "t1 joinable: " << t1.joinable() << '\n';
  return 0;
}

