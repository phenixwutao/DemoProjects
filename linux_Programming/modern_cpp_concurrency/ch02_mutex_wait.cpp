#include <iostream>
#include <iomanip>

#include <thread>
#include <utility>
#include <atomic>

using namespace std;

std::mutex mut;

void workOnResource()
{
  mut.lock();
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  mut.unlock();
}

int main(int argc, char *argv[])
{
  std::thread t1(workOnResource);
  std::thread t2(workOnResource);
  t1.join();
  t2.join();
  return 0;
}

