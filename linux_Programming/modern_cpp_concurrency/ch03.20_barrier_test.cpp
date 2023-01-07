#include <iostream>
#include <string>

#include <vector>

#include <thread>
#include <barrier>

int main()
{
  const auto workers = {"anil", "busara", "carl"};
  auto on_completion = []() noexcept
  {
    // locking not needed here, static variable is initialsed once since C++11
    static auto phase = "... done\n"
                        "Cleaning up...\n";
    std::cout << phase;
    phase = "... done\n";
  };

  std::barrier sync_point(std::ssize(workers), on_completion);

  auto work = [&](std::string name)
  {
    std::string product = "  " + name + " worked\n";
    std::cout << product; // ok, op<< call is atomic
    sync_point.arrive_and_wait();

    product = "  " + name + " cleaned\n";
    std::cout << product;
    sync_point.arrive_and_wait();

    product = "  " + name + " end here\n";
    std::cout << product;
  };

  std::cout << "Starting...\n";
  std::vector<std::thread> threads;
  for (auto const &worker : workers)
  {
    threads.emplace_back(work, worker);
  }
  std::cout << "workers size: " << workers.size() << '\n';
  for (auto &thread : threads)
  {
    thread.join();
  }
  return 0;
}
