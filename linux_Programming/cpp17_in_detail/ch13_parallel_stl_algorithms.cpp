// page 205
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <execution>
#include <exception>

using namespace std;

int main()
{
  {
    try
      {
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::for_each(std::execution::par, v.begin(), v.end(),
		      [](int& i) {
			try {
			std::cout << i << '\n';
			if (i == 5)
			  throw std::runtime_error("something wrong... !");
			}
			catch(...)
			  {
			    std::cout << "catch any error!\n";
			  }
		      });
      }
    catch (const std::bad_alloc& e)
      {
	std::cout << "Error in execution: " << e.what() << '\n';
      }
    // handle runtime_error cannot catch the exception within lambda function
    catch (const std::runtime_error& e)
      {
	std::cout << "Error in execution: " << e.what() << '\n';
      }
    catch (const std::exception& e) // will not happen
      {
	std::cout << "catch exception: " << e.what() << '\n';
      }
    catch (...)
      {
	std::cout << "catch any error!\n";
      }
  }

  {
    std::vector<int> v(100);
    std::iota(v.begin(), v.end(), 0);
    std::for_each(std::execution::par, v.begin(), v.end(),
		  [](int& i) { i += 10; });
    std::for_each_n(std::execution::par, v.begin(), v.size()/2,
		    [](int& i) { i += 10; });
    
  }

  {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto sum = std::accumulate(v.begin(), v.end(), /*init*/ 0);
    cout << "std::accumulate sum is " << sum << '\n';
  }

  {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto sum = std::reduce(std::execution::par, v.begin(), v.end(), 0);
    cout << "std::reduce sum is " << sum << '\n';
  }

  {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto sumTransformed = std::transform_reduce(std::execution::par,
						v.begin(),
						v.end(),
						0,
						std::plus<int>{},
						[](const int& i) { return i * 2; }
						);
    cout << "std::transform_reduce sum is " << sumTransformed << '\n';
  }
  return 0;
}

