#include <utility>
#include <iostream>
#include <string>
#include <array>
#include <mutex>
#include <shared_mutex>
#include <memory>

std::shared_timed_mutex mut;

template <typename T>
T simpleTypeInfo(T t)
{
  if constexpr (std::is_integral_v<T>)
    {
      std::cout << "foo<integral T> " << t << '\n';
    }
  else
    {
      std::cout << "not integral \n";
    }
  return t;
}

int main()
{
  using namespace std::string_literals;
  std::pair myPair(42, "hello world"s); // deduced automatically!

  std::array<int, 3> arr1 {1, 2, 3};
  std::array arr2 {2,3,4};

  {
    std::tuple tuple1(1, 2, 3); // OK: deduction
    std::tuple<int,int,int> tuple2(1, 2, 3); // OK: all arguments are provided
    std::lock_guard lck(mut);
  }
  
  // control block and int might be in different places in memory
  std::shared_ptr<int> p(new int{10});
  
  // the control block and int are in the same contiguous memory section
  auto p2 = std::make_shared<int>(10);
 
  return 0;
}

