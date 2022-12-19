// page 228
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>
#include <execution>
#include <exception>
#include <chrono>
#include <numeric>
#include <cmath>
#include <string_view>


using namespace std;

/***************************************
 * original template code has a bug:
template <typename Policy, typename Iter, typename Func>
std::size_t CountIf(Policy policy, Iter first, Iter last, Func predicate)
{
  return std::transform_reduce(policy,
			       first,
			       last,
			       std::size_t(0),
			       std::plus<std::size_t>{},
			       [&predicate](const Iter::value_type& v) {
				 return predicate(v) ? 1 : 0;
			       });
}
***************************************/

template <typename Policy, typename Iter, typename Func>
std::size_t CountIf(Policy policy, Iter first, Iter last, Func predicate)
{
  return std::transform_reduce(policy,
			       first,
			       last,
			       std::size_t(0),
			       std::plus<std::size_t>{},
			       [&predicate](const auto& v) {
				 return predicate(v) ? 1 : 0;
			       });
}


int main( int argc, char* argv[])
{
  // test 1
  {
    std::vector<int> v(100);
    std::iota(v.begin(), v.end(), 0);
    auto NumEven = CountIf(std::execution::par, v.begin(), v.end(),
			   [](int i) { return i % 2 == 0; } );
    std::cout << NumEven << '\n';
  }


  // test 2
  {
    std::string_view sv = "Hello Programming World";
    auto NumSpaces = CountIf(std::execution::seq, sv.begin(), sv.end(),
			     [](char ch) { return ch == ' '; } );
    std::cout << NumSpaces << '\n';
  }

  // test 3
  {
    std::map<std::string, int> CityAndPopulation{
      {"Cracow", 765000},
      {"Warsaw", 1745000},
      {"London", 10313307},
      {"New York", 18593220},
      {"San Diego", 3107034} };
    auto NumCitiesLargerThanMillion = CountIf(std::execution::seq,
					      CityAndPopulation.begin(), CityAndPopulation.end(),
					      [](const std::pair<const std::string, int>& p) {
						return p.second > 1000000;
					      } );
    std::cout << NumCitiesLargerThanMillion << '\n';
  }
  
  return 0;
}

