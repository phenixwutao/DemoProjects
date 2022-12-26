#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>
using namespace std;

    bool containsDuplicate(vector<int>& nums)
    {
      std::unordered_set<int> checker;
      for(auto i : nums)
      {
        auto it = checker.emplace(i);
        if (it.second == false)
        {
          return true;
        }
      }
      return false;
    }



int main()
{
  /*
  Input: prices = [7,1,5,3,6,4]
  Output: 5
  */
  std::cout << std::boolalpha;
  std::vector<int> nums1 = {1,2,3,1};
  std::vector<int> nums2 = {1,2,3,4};
  std::vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};
  std::cout << containsDuplicate(nums1) << '\n';
  std::cout << containsDuplicate(nums2) << '\n';
  std::cout << containsDuplicate(nums3) << '\n';
  return 0;
}


