#include <iostream>
#include <vector>
#include <array>
#include <atomic>
#include <utility>
using namespace std;

struct demo{
  bool isIntLockFree = std::atomic_bool{}.is_lock_free();
   //std::atomic<int>{}.is_lock_free()
};

int main()
{
  const auto func1 = []()
  {
    std::vector<int> vec;
    vec.push_back(1);
    return vec;
  }();

  // it is initialised exactly only once
  static constexpr std::array<int, 5> angles{-90,-45,0,45,90};

  static const int VALID_ID_EXTERNAL_ID = 10532; // old style
  static constexpr int VALID_ID_EXTERNAL_ID2 = 10532; // new style, standard

  return 0;
}