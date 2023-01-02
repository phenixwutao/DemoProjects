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
#include <functional>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

void transferMoney(int id, double& amt)
{
  cout << "id " << id << ", amt " << amt << '\n';
}


class Sleeper
{
public:
  Sleeper(int& i_) : i(i_) {}
  void operator()(int k)
  {
    for (unsigned int j = 0; j < 5; ++j)
    {
      std::this_thread::sleep_for(100ms);
      i += k;
    }
    cout << "thread ID: " << std::this_thread::get_id() << '\n';
  }

private:
  int& i;
};


int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  string s = "C++11";
  thread t1([=](){ cout << "thread t1 " << s << '\n';});
  t1.join();

  thread t2([&](){ cout << "thread t2 " << s << '\n';});
  t2.join();

  int id = 3;
  double amt = 300;
  thread t3(transferMoney, id, std::ref(amt));
  t3.join();

  int valsleep = 1000;
  std::thread t4(Sleeper(valsleep), 5);
  t4.join();
  cout << "valsleep = " << valsleep << '\n';

  cout << "max threads: " <<std::thread::hardware_concurrency() << '\n';

  return 0;
}

