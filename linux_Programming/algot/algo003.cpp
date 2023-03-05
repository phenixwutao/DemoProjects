#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

  void plusMinus(vector<int> arr) {
    if (arr.empty())
    return;
    
std::cout.precision(6);
std::cout.fill('0');
std::cout.width(8);

int pos_count = 0;
int neg_count = 0;
int zero_count = 0;
for(size_t i = 0; i < arr.size(); ++i)
{
    if(arr[i]>0)
    pos_count++;
    else if(arr[i]<0)
    neg_count++;
    else
    zero_count++;    
  printf("arr[%d]=%d  pos %d  neg %d\n",i, arr[i], pos_count, neg_count);
}
double sum = (pos_count+neg_count+zero_count);
printf("sum %d\n", sum);
if(pos_count>0)
std::cout << static_cast<double>(pos_count/sum) << '\n';

if(neg_count>0)
std::cout << static_cast<double>(neg_count/sum) << '\n';

if(zero_count>0)
std::cout << static_cast<double>(zero_count/sum) << '\n';

}

void staircase(int n) {
    std::cout.width(n);
    char hash = '#';
    std::cout.fill(' ');
    for(int i = 0; i <n; ++i)
    {
        std::string mess;
        for(int j = 0; j <= i; ++j)
        {
        mess += hash;
        //printf("j %d i %d mess %s\n", j , i, mess.c_str());
        //std::cout << mess << '\n';
        }
        std::cout << mess << '\n';
    }
}


void miniMaxSum(vector<unsigned long long int> arr) {
    vector<unsigned long long int> sums;
    unsigned long long int sum = std::accumulate(arr.begin(), arr.end(), 0);
    unsigned long long int sum2 = 0;
    for(auto i = 0 ; i < arr.size(); ++i)
    {
      sum += arr[i];
    }
    printf("sum2 %llu\n", sum2);

    for(auto i = 0 ; i < arr.size(); ++i)
    {
      printf("sum %lld arri %lld\n", sum, arr[i]);
        sums.push_back(sum-arr[i]);
    }
    std::sort(sums.begin(), sums.end());
    std::cout << *sums.begin() << " " << *(--sums.end()) << '\n';
}

string timeConversion(string s) {
string newhour = s;
string strpm = s.substr(8,2);

bool isAM = ((strpm == "AM" || strpm == "am"));
bool isPM = ((strpm == "PM" || strpm == "pm"));

    string hour = s.substr(0,2);
    int whour = stoi(hour);
    if (isPM && whour <12)
        whour = whour + 12;
    else if(isAM && whour >=12)
        whour = whour - 12;

    char chour3[3]{};
    sprintf(chour3, "%.2d", whour);
    string hour2 = chour3;
    string strmin = s.substr(2,6);
    newhour = hour2 + strmin;

return newhour;
}

int stringConstruction(string s)
{
    const auto wsize = s.size();
    vector<int> cost(wsize);
    for(size_t i=0; i < s.size(); ++i)
    {
        static string child;
        child += s[i];
        string searchstr = s;
        printf("child %s, searchstr %s\n", child.c_str(), searchstr.c_str());
        auto posfind = searchstr.find(child);
        if(posfind != std::string::npos)
        cost[i]++;
    }
    return std::accumulate(cost.begin(), cost.end(), 0);
}

int maxProfit(vector<int>& prices)
{
  int minsofar = numeric_limits<int>::max();
  int maxprofit = 0;
  for(auto& p : prices)
  {
    maxprofit = max(maxprofit, (p - minsofar));
    minsofar = min(minsofar, p);
  }
  return maxprofit;
}

int maxProfit2(vector<int>& prices)
{
  int min_so_far = numeric_limits<int>::max();
  vector<int> profit_first_trade(prices.size(), 0);
  int max_profit = 0;
  for (size_t i = 0; i < prices.size(); ++i)
  {
    min_so_far = min(min_so_far, prices[i]);
    max_profit = max(max_profit, prices[i] - min_so_far);
    profit_first_trade[i] = max_profit;
  }
  printf("max profit first trade: %d\n", max_profit);

  int max_so_far = numeric_limits<int>::min();
  for(size_t i = prices.size()-1; i>0; --i)
  {
    max_so_far = max(max_so_far, prices[i]);
    max_profit = max(max_profit, max_so_far - prices[i] + profit_first_trade[i-1]);
  }
  printf("max profit second trade: %d\n", max_profit);
  return max_profit;
}

string convertToTitle(int n)
{
  string col;
  string prefix;
  if (n>0 && n <=26)
  {
    col += 'A' + n-1;
    prefix = col;
  }
  else
  while(n >= 26)
  {
    col += 'A' + n%26-1;
    n = n/26;
  }
  return col;
}

int diagnalDiff(vector<vector<int>>& arr)
{
  int diasum1 = 0;
  int diasum2 = 0;
  const auto count = arr.size();
  for(size_t i = 0; i < arr.size(); ++i)
  {
    const auto& it = arr[i];
    for(size_t j = 0; j < it.size(); ++j)
    {
      if (i == j)
        diasum1 += it[j];
      if(i+j+1 == count)
        diasum2 += it[j];
    }
  }
  printf("diasum1 %d, diasum2 %d\n", diasum1, diasum2);
  return abs(diasum1 - diasum2);
}


vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> anagMap;
  for (auto& s: strs) {
    string tmp=s;
    sort(tmp.begin(), tmp.end());
    anagMap[tmp].push_back(s);
  }

  vector<vector<string>> res;
  for (auto& x: anagMap) {
    res.push_back(x.second);
  }
  return res;
}

int main()
{
  vector<int> arr = {-4, 3, -9, 0, 4, 1};
  //plusMinus(arr);
  staircase(6);

  vector<unsigned long long int> arr2 = {256741038, 623958417, 467905213, 714532089, 938071625};
  //vector<unsigned long long int> arr2 = {256741038, 256741039, 256741040};
  miniMaxSum(arr2);

  std:: cout << timeConversion("12:01:09AM") << endl;
  std:: cout << timeConversion("09:01:06AM") << endl;
  std:: cout << timeConversion("12:01:07PM") << endl;
  std:: cout << timeConversion("09:01:06PM") << endl;

  std::string s("abab");
  std::cout << stringConstruction(s) << '\n';

  vector<int> prices = {7,1,5,3,6,4};
  cout << maxProfit(prices) << '\n';

  vector<int> prices2 = {3,3,5,0,0,3,1,4};
  cout << maxProfit2(prices2) << '\n';

  for (int i = 1; i < 53; ++i)
  {
    cout << convertToTitle(i) << '\n';
  }
  vector<vector<int>> arr4;
  vector<int> vec1 = {11,2,4};
  arr4.push_back(vec1);
  vec1 = {4,5,6};
  arr4.push_back(vec1);
  vec1 = {10,8,-12};
  arr4.push_back(vec1);
  cout << diagnalDiff(arr4) << '\n';

	return 0;
}
