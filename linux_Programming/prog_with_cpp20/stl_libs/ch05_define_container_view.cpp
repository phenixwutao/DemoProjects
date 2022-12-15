#include <concepts>

#include <string>
#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>

#include <iostream>

#include <type_traits>

#include <ranges>

using namespace std;

template<std::ranges::input_range Range>
requires std::ranges::view<Range>
class ContainerView : public std::ranges::view_interface<ContainerView<Range>>
{
private:
  Range range_ {};
  std::ranges::iterator_t<Range> begin_{std::begin(range_)};
  std::ranges::iterator_t<Range> end_{std::end(range_)};

public:
  ContainerView() = default;
  constexpr ContainerView(Range r) : range_(std::move(r)),
				     begin_(std::begin(r)),
				     end_(std::end(r))
  {
  }

  constexpr auto begin() const
  {
    return begin_;
  }

  constexpr auto end() const
  {
    return end_;
  }
};

template<typename Range>
ContainerView(Range&& range) -> ContainerView<std::ranges::views::all_t<Range>>;

int main()
{
  cout <<std::boolalpha;
  
  std::vector myVec {1,2,3,4,5,6,7,8,9};
  auto myContainerView = ContainerView(myVec);
  for(auto c : myContainerView)
    cout << c << ' ';
  cout << '\n';
  
  for (auto i : std::views::reverse(ContainerView(myVec)))
    std::cout << i << ' ';
  std::cout << '\n';

  for (auto i : ContainerView(myVec) | std::views::reverse)
    std::cout << i << ' ';
  std::cout << '\n';
  std::cout << std::endl;

  std::string myStr = "Only for testing purpose.";

  auto myContainerView2 = ContainerView(myStr);
  for (auto c: myContainerView2)
    std::cout << c << " ";
  std::cout << '\n';

  for (auto i : std::views::reverse(ContainerView(myStr)))
    std::cout << i << ' ';
  std::cout << '\n';

  for (auto i : ContainerView(myStr) | std::views::reverse)
    std::cout << i << ' ';
  std::cout << '\n';
  return 0;
}
