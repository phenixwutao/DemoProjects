#include <iostream>
#include <iomanip>
#include <string>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility> // Date and time utilities
#include <atomic>

#include <chrono>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

std::atomic<int> count = {0};

void add()
{
	for(int n = 0; n < 1000; ++n)
	{
		// std::shared_ptr is using memory_order_relaxed for reference counting
		// the order of increment does not matter, but not apply to decrement
		// add() algorithm is lock-free and wait-free
		count.fetch_add(1, std::memory_order_relaxed);
	}
}


int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  auto start1 = std::chrono::steady_clock::now();

  vector<thread> v;
  for(int i = 0; i <10; ++i)
  {
  	v.emplace_back(std::thread{add});
  }

  for(auto& t : v)
  {
  	t.join();
  }
  cout << "final count is: " << count << '\n';
  auto end1 = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end1-start1;
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

  return 0;
}

