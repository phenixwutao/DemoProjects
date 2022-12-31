#include <iostream>
#include <iomanip>

#include <vector>

#include <thread>
#include <utility>
#include <atomic>

using namespace std;

template<typename ...Args>
auto build_array2(Args&&...args) -> 
  std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
  using CommonType = typename std::common_type<Args...>::type;
  return {std::array<CommonType>(args)...};
}


template< typename ... Args>
auto build_array(Args&&... args) -> 
  std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
using commonType = typename std::common_type<Args...>::type;
return {std::forward<commonType>(args)...};
}

int main(int argc, char *argv[])
{
  // auto data = build_array(1, 0u, 'a', 3.2f, false);
  auto data = build_array2(1, 3.2f);
  for(auto i: data)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}