#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>
#include <memory>
#include <atomic>

#include <map>

using namespace std;

template<typename T, typename...Args>
T create(Args&&... args)
{
  return T {std::forward<Args>(args)...};
}

class CopyOnly
{
public:
  CopyOnly() {}
  CopyOnly(int) {}
  CopyOnly(const CopyOnly&) = default;
  CopyOnly(CopyOnly&&) = delete;

};

CopyOnly getCopyOnly()
{
  return CopyOnly{};
}

int main()
{
  int i = create<int>(42);
  std::unique_ptr<int> up = create<std::unique_ptr<int>> (new int{42});
  std::atomic<int> ai = create<std::atomic<int>>(42);

  CopyOnly x = 42;
  return 0;
}

