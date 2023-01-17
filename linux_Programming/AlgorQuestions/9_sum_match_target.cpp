#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
	vector<int> match;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = nums.size() - 1; j > i; j--)
		{
			if (nums[i] + nums[j] == target)
			{
				match.push_back(i);
				match.push_back(j);
				break;
			}
		}
	}
	return match;
}

// performance is worse here
vector<int> twoSum2(vector<int> &nums, int target)
{
	vector<int> match;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i+1; j < nums.size(); ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				match.push_back(i);
				match.push_back(j);
				break;
			}
		}
	}
	return match;
}

int main()
{
	vector<int> nums = {2, 7, 11, 15};
	auto matches = twoSum(nums, 9);
	for(auto i : matches)
		cout << i << ' ';
	cout << '\n';

	int v1 = 9999999 + 9999;
	cout << v1 << '\n';
	return 0;
}
