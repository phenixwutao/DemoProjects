#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int RomanToInteger(const string& s)
{
  map<char,int> values = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

  int total = 0;
  for(size_t i = 0; i < s.size(); ++i)
  {
    if ( i > 0 && values[s[i]] > values[s[i-1]])
    total += values[s[i]] - 2 * values[s[i-1]]; 
    else
    total += values[s[i]]; 
  }
  return total;
}

string IntegerToRoman(int num)
{
  string roman;
  const int radix[] = 
    {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  const string symbol[] = 
    {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  
  for(int i = 0; num >0; ++i)
  {
    int count = num / radix[i];
    num = num%(radix[i]);
    for (int j = count; j >0; --j)
    {
      roman += symbol[i];
    }
  }

  return roman;
}

int FindLastWordLength(const string& s)
{
  if (s.empty())
  return 0;
  else{
    auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
    auto last = find_if_not(first, s.rend(), ::isalpha);
    return std::distance(first, last);
  }

}

bool ValidParentheses(const string& s)
{
   // "([)]"
  string left = "([{";
  string right= ")]}";
  printf("-------------\n");
  stack<char> stk;
  auto printStack = [&](int id){
        std::cout << "printStack : " << id << ' ' << stk.top() << '\n';
  };

  for (auto c : s)
  {
    if(left.find(c) != string::npos)
    {
      stk.push(c);
      printStack(1);
    }
    else {
      if (stk.empty() || stk.top() != left[right.find(c)])
      {
        printStack(2);
        return false;
      }
      else {
        printStack(3);
        stk.pop();
      }
    }
  }
         printStack(4);
 return stk.empty();
}

int largestRectangleArea(vector<int> &height) {
  stack<int> s;
  height.push_back(0);
  int result = 0;
  for (int i = 0; i < height.size(); ) {
    if (s.empty() || height[i] > height[s.top()])
      s.push(i++);
    else {
      int tmp = s.top();
      s.pop();
      result = max(result,
                   height[tmp] * (s.empty() ? i : i - s.top() - 1));
    }
  }
  return result;
}

void merge(vector<int>& A, int m, vector<int>& B, int n)
{
  int ia = m - 1, ib = n - 1, icur = m + n - 1;
  while(ia >= 0 && ib >= 0) {
    A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
  }

  while(ib >= 0) {
    A[icur--] = B[ib--];
  }
}

vector<int> searchRange(vector<int>& nums, int target)
{
  // Search for first element <= target
  const int l = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
  // Search for first element > target
  const int u = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
  printf(" i = %d, u = %d\n", l, u);
  if (nums[l] != target) // not found
    return vector<int> { -1, -1 };
  else
    return vector<int> { l, u };
}

int searchInsert(vector<int> & nums, int target)
{
  return std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), target));
}


// generate a subset from a set
static void GenerateSubsets(const vector<int> &S, 
                    vector<int> &path, int step,
                    vector<vector<int> > &result)
{
  if (step == S.size()) {
    result.push_back(path);
    return;
  }

  // do notchoose S[step]
  GenerateSubsets(S, path, step + 1, result);

  // choose  S[step]
  path.push_back(S[step]);
  GenerateSubsets(S, path, step + 1, result);
  path.pop_back();
}

vector<vector<int> > GenerateSubsets(vector<int> &S)
{
  sort(S.begin(), S.end());
  vector<vector<int> > result;
  vector<int> path;
  GenerateSubsets(S, path, 0, result);
  return result;
}

template<typename T>
void printAll(const vector<vector<T>>& Sets)
{
  for(const auto& it : Sets)
  {
    for(const auto& value : it)
    {
      cout << value << ' ';
    }
    cout << '\n';
  }
}

vector<vector<int> > GenerateSubsets2(vector<int> &S)
{
  sort(S.begin(), S.end()); 
  vector<vector<int> > result(1);
  for (auto elem : S)
  {
    result.reserve(result.size() * 2);
    auto half = result.begin() + result.size();
    copy(result.begin(), half, back_inserter(result));
    for_each(half, result.end(), 
      [&elem](decltype(result[0]) &e) {
      e.push_back(elem);
      });
      // printf("----------- check: ---------\n");
      // printAll(result);
  }
  return result;
}

static void dfs(int n, int k, int start, int cur, vector<int> &path, vector<vector<int> > &result)
{
  if (cur == k) {
    result.push_back(path);
  }

  for (int i = start; i <= n; ++i)
  {
    path.push_back(i);
    dfs(n, k, i + 1, cur + 1, path, result);
    path.pop_back();
  }
}

vector<vector<int> > combination(int n, int k)
{
  vector<vector<int> > result;
  vector<int> path;
  dfs(n, k, 1, 0, path, result);
  return result;
}

int Fibonacci(int n)
{
  if (n>=1 && n<3)
    { return 1; }
  else if (n==0)
    return 0;
  else
    {
      int first = 1,second = 1,temp = 0;
      for (int i =0;i<n-2;i++)
      {temp = first + second;
      first = second;
      second = temp;}
      return temp;
    }
}

int Fib2(int n)
{
  if (n==0)
    return 0;
  else if (n>=1 && n <=2)
    return 1;
  else
  {
    int first = 1;
    int second = 1;
    int fib = 0;
    for (int i = 2; i < n; ++i)
    {
      // i  first  second fib
      // i+1       first  second  fib
      fib = first + second;
      first = second;
      second = fib;
    }
    return fib;
  }
}

int uniquePaths(int m, int n) {
  if (m < 1 || n < 1) return 0;
  if (m == 1 && n == 1) return 1;
  return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

class UniquePathsSolution
{
public:
  int uniquePaths(int m, int n)
  {
    f = vector<vector<int> >(m, vector<int>(n, 0)); // initialise f
    f[0][0] = 1;
    return dfs(m - 1, n - 1);
  }

private:
  vector<vector<int> > f; 

  int dfs(int x, int y)
  {
    if (x < 0 || y < 0) return 0;
    if (x == 0 && y == 0) return f[0][0];
    if (f[x][y] > 0) {
      return f[x][y];
    }
    else {
      return f[x][y] = dfs(x - 1, y) + dfs(x, y - 1);
    }
  }
};

// p204 max profit
int maxProfit(vector<int>& prices)
{
  if (prices.size() < 2) return 0;
  int profit = 0;
  int cur_min = std::numeric_limits<int>::max();
  for (int i = 0; i < prices.size(); ++i)
  {
    profit = max(profit, prices[i] - cur_min);
    cur_min = min(cur_min, prices[i]);
  }
  return profit;
}

// p205
int maxProfitMany(vector<int>& prices)
{
  int sum = 0;
  for(int i=1; i< prices.size(); ++i)
  {
    int diff = prices[i] - prices[i-1];
    if (diff >0) sum += diff;
  }
  return sum;
}

int main()
{
  std::cout << std::boolalpha ;
  std::cout << RomanToInteger("IV") << endl;
  std::cout << IntegerToRoman(1994) << endl;
  std::cout << FindLastWordLength("hello adam") << endl;
  std::cout << ValidParentheses("(]") << '\n';
  std::cout << ValidParentheses("([)]") << '\n';
  vector<int> hist = {2,1,5,6,2,3};
  std::cout << largestRectangleArea(hist) << '\n';
  vector<int> rrange = {5,7,7,8,6,8,10};
  searchRange(rrange, 8);

  vector<int> nums1 = {1,3,5,6};
  std::cout << searchInsert(nums1, 2) << '\n';

  vector<int> myset = {1,2,3};
  auto generatedSets = GenerateSubsets(myset);
  std::cout << generatedSets.size() << '\n';
  printAll(generatedSets);

  auto generatedSets2 = GenerateSubsets2(myset);

  auto combinedSet = combination(4,2);
  printAll(combinedSet);
  for(int i = 0; i < 10; ++i)
  {
    cout << Fib2(i) << ' ';
  }
    cout <<'\n';

  std::cout <<uniquePaths(3,7) << '\n';
  UniquePathsSolution uniquepathsol;
  std::cout << uniquepathsol.uniquePaths(3,7) << '\n';

  vector<int> prices = {7,1,5,3,6,4};
  std::cout << maxProfit(prices) << '\n';
  std::cout << maxProfitMany(prices) << '\n';
	return 0;
}
