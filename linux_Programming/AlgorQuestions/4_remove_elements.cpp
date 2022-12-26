#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      auto size = nums.size();
      if (size == 0 || size > 30000)
        return 0;

      int k=0;
      auto printnums = [&](){
        for(auto i : nums)
          std::cout << i << ' ';
        std:: cout << '\n';
        std::cout << "k= " << k << " nums[k]= " << nums[k] << '\n';;
      };

        for(int i=0;i<nums.size();i++){
            if(nums[k]!=nums[i]){
                k++;
                nums[k]=nums[i];
            }
            printnums();
        }
        k++;
        return k;        
    }

    int removeElements(vector<int>& nums, int val) {
      auto size = nums.size();
      int k=0;
      if ((size == 0) || (size > 100) || (val < 0) || (val > 100)) {
        return k;
      }

      for(int i= nums.size(); i>0; i--){
            if(val!=nums[i])
            {
              // k++;
              nums[k]=nums[i-1];
              k++;
            }
        }
      k++;
      return k;        
    }

int removeElements2(vector<int>& A, int elem) {
    int i = 0;
    auto n = A.size();

    auto printavec = [&]{
        for(auto v : A)
          std::cout << v << ' ';
        std:: cout << '\n';
        std::cout << "\t\t\ti= " << i << " n= " << n << '\n';;
    };
    while (i < n) {
        if (A[i] == elem) {
            A[i] = A[n - 1];
            n--;
        }
        else
            i++;
        printavec();
    }
    return n;
}

};


int main()
{
  /*
  Input: nums = [0,0,1,1,1,2,2,3,3,4]
  Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
  */

  /*
  Input: nums = [0,1,2,2,3,0,4,2], val = 2
  Output: 5, nums = [0,1,4,0,3,_,_,_]
  */
  Solution sol;
  std::vector nums2 = {0,1,2,2,3,0,4,2};
  for(auto i : nums2)
    std::cout << i << ' ';
  std::cout << std:: endl;

  std::cout << sol.removeElements2(nums2, 2) << std::endl;

  for(auto i : nums2)
    std::cout << i << ' ';
  std::cout << std:: endl;

  return 0;
}


