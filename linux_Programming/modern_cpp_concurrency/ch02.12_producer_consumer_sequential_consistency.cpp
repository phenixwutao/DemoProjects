#include <iostream>
#include <iomanip>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

std::string work;
std::atomic<bool> ready {false};

void consumer()
{
  while(!ready.load()) {}
  cout << work << '\n';
}

void producer()
{
  work = "done";
  ready = true;
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  
  std::thread t1(producer);
  std::thread t2(consumer);
  t1.join();
  t2.join();

  return 0;
}

