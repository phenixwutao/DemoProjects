#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates2(vector<int>& nums) {
      auto size = nums.size();
      if (size == 0 || size > 30000)
        return 0;

        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[k]!=nums[i]){
                k++;
                nums[k]=nums[i];
            }
        }
        k++;
        return k;        
    }

    int removeDuplicates(vector<int>& nums) {
      int index = 1;
      while (index < nums.size())
      {
        if (nums[index-1] == nums[index])
        {
          nums.erase(nums.begin() + index);
        }
        else
        {
          index++;
        }
      }
      return nums.size();
    }

};


int main()
{
  /*
  Input: nums = [0,0,1,1,1,2,2,3,3,4]
  Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
  */
  std::vector nums = {0,0,1,1,1,2,2,3,3,4};
  Solution sol;
  std::cout << sol.removeDuplicates(nums) << std::endl;
  for(auto i : nums)
    std::cout << i << ' ';
  std::cout << std:: endl;
  return 0;
}


