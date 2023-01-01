#include <iostream>
#include <iomanip>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility>
#include <atomic>
#include <mutex>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

std::atomic<int> atom {0};
int somethingShared {0};

void WriteShared()
{
  somethingShared = 2011;
  atom.store(2, std::memory_order_release);
}

void readShared(int id)
{
  while ( !(atom.fetch_sub(1, std::memory_order_acquire) > 0) )
  {
    std::this_thread::sleep_for(100ms);
    cout << "readShared while loop " << id << '\n';
  }
  cout << "readShared somethingShared " << id << " : " << somethingShared << '\n';
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  thread t1 (WriteShared);
  thread t2(readShared, 2);
  thread t3(readShared, 3);

  t1.join();
  t2.join();
  t3.join();

  cout << "atom = " << atom << '\n';
  return 0;
}

