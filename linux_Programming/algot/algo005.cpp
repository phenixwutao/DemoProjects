#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

template<typename Impl>
class Interface{
  public:
  void process()
  {
    impl().process();
  }
  private:
  Impl& impl()
  {
    return *(static_cast<Impl*>(this));
  }
};

// In CRTP, a class X is derived from a base class 
// which is template specialization of class X itself
class Impl: public Interface<Impl>
{
  public:
  void process(){}
};

void do_work(Interface<Impl>* obj)
{
  obj->process();
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> anagMap;
  for (auto& s: strs) {
    string tmp=s;
    sort(tmp.begin(), tmp.end());
    anagMap[tmp].push_back(s); // the same key, push back multiple strings
  }

  vector<vector<string>> res;
  for (auto& x: anagMap) {
    res.push_back(x.second);
  }
  return res;
}

vector<int> FindMissingNumbers(vector<vector<int>>& grid)
{
  vector<int> res;
  int row = grid.size();
  int col = grid[0].size();
  for(int i = 0; i < col; ++i)
  {
    int sum = 45;
    for(int j = 0; j < row; ++j)
    {
      sum -= grid[i][j];
    }
    // remaining value of sum is the missing one
    res.push_back(sum);
  }
  return res;
}

int main()
{
  Interface<Impl>* obj = new Impl;
  do_work(obj);
  delete obj;

  vector<int> vec = {1,1,1,1,1,1,1,1,1,1};
  //vec.size(); //10
  vec[0] = 2;
  // remove(vec.begin(), vec.end(), 2);
  // cout << vec.size() << '\n'; // ?? what is vec.size() here
  vec.erase(remove(vec.begin(), vec.end(), 2), vec.end());
  cout << vec.size() << '\n';

  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto output = groupAnagrams(strs);
  for(int i = output.size()-1; i >=0; --i)
  {
    for(auto& it : output[i])
    {
      cout << it << ' ';
    }
    cout << '\n';
  }

	return 0;
}
