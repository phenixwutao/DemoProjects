#include <array>
#include <iostream>
#include <mutex>

using namespace std;

int main()
{
  std::mutex first_mutex;
  std::mutex second_mutex;
  {
    std::lock(first_mutex, second_mutex);
    std::lock_guard<std::mutex> lock_one(first_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> lock_two(second_mutex, std::adopt_lock);
  }

  {
    std::scoped_lock lck(first_mutex, second_mutex);
  }
  return 0;
}

