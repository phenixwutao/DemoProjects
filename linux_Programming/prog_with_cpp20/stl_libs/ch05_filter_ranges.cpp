#include <concepts>
#include <type_traits>

#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>
#include <compare>


using namespace std;

template<typename Func, typename Seq>
auto filter(Func func, const Seq& seq)
{
  typedef typename Seq::value_type value_type;
  std::vector<value_type> result{};
  for (auto i : seq | std::views::filter(func))
    result.push_back(i);
  return result;
}

int main()
{
  cout <<std::boolalpha;
  vector<int> myInts(50);
  std::iota(myInts.begin(), myInts.end(),1);
  auto res = filter([](int i){return (i%3) == 0;}, myInts);

  for(auto v: res)
    cout << v << ' ';
  cout << '\n';

  std::vector<std::string> myStrings{"Only", "for", "testing", "purposes"};
  auto res2 = filter([](const std::string& s){ return std::isupper(s[0]); }, myStrings);
  std::cout << "\n\n";

  for (auto word: res2) std::cout << word << '\n';
  std::cout << '\n';
  
  return 0;
}
