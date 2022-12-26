#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int max_profit(vector<int>& nums)
    {
      if (nums.size() ==0 || nums.size() > 100000)
        return 0;

      int maxProfit = 0;
      int minPrice = std::numeric_limits<int>::max();
      for(int i=0; i < nums.size(); ++i)
      {
        minPrice = min(minPrice, nums[i]);
        maxProfit = max(maxProfit, (nums[i] - minPrice));
      }
      return maxProfit;
    }

    int max_profit2(vector<int>& nums)
    {
      if (nums.size() ==0 || nums.size() > 100000)
        return 0;

      int maxProfit = 0;
      int minPrice = std::numeric_limits<int>::max();
      for(int i=0; i < nums.size(); ++i)
      {
        if(nums[i] < minPrice) minPrice = nums[i];
        else
          maxProfit = max(maxProfit, nums[i]-minPrice);
      }
      return maxProfit;
    }
};


int maxProfit(vector<int> &prices) {
    int maxPro = 0;
    int minPrice = std::numeric_limits<int>::max();
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}

int main()
{
  /*
  Input: prices = [7,1,5,3,6,4]
  Output: 5
  */
  Solution sol;
  std::vector<int> nums = {7,1,5,3,6,4};
  std::cout << sol.max_profit2(nums) << '\n';

  std::vector<int> nums2 = {7,6,4,3,1};
  std::cout << sol.max_profit2(nums2) << '\n';

  std::vector<int> nums3 = {2,4,1};
  std::cout << sol.max_profit2(nums3) << '\n';

  printf("-----------------------\n");
  std::vector<int> nums4 = {7,1,5,3,6,4};
  std::vector<int> nums5 = {7,6,4,3,1};
  std::vector<int> nums6 = {2,4,1};
  std::cout << maxProfit(nums4) << '\n';
  std::cout << maxProfit(nums5) << '\n';
  std::cout << maxProfit(nums6) << '\n';
  return 0;
}


