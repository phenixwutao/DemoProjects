// page 205
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <execution>
#include <exception>
#include <chrono>
#include <numeric>
#include <cmath>

using namespace std;

template <typename TFunc> void RunAndMeasure(const char* title, TFunc func)
{
  const auto start = std::chrono::steady_clock::now();
  auto ret = func();
  const auto end = std::chrono::steady_clock::now();
  std::cout << title
	    << ": " << std::chrono::duration<double, std::milli>(end - start).count()
	    << " ms " << ret << '\n';
}


void Process(int a, int b) { }

int main( int argc, char* argv[])
{
  // test 1
  {
    const size_t vecSize = argc > 1 ? atoi(argv[1]) : 1'000'000;
    std::cout << vecSize << '\n';
    std::vector<double> vec(vecSize, 0.5);
    std::vector out(vec);
    RunAndMeasure("std::transform seq", [&vec, &out] {
      std::transform(std::execution::seq, vec.begin(), vec.end(), out.begin(),
		     [](double v) {
		       return std::sin(v)*std::cos(v);
		     }
		     );
      return out.size();
    });
    RunAndMeasure("std::transform par", [&vec, &out] {
      std::transform(std::execution::par, vec.begin(), vec.end(), out.begin(),
		     [](double v) {
		       return std::sin(v)*std::cos(v);
		     }
		     );
      return out.size();
    });
  }


  // test 2
  {
    const size_t vecSize = argc > 1 ? atoi(argv[1]) : 1000000;
    std::cout << vecSize << '\n';
    std::vector<double> vec(vecSize, 0.5);
    RunAndMeasure("std::accumulate", [&vec] {
      return std::accumulate(vec.begin(), vec.end(), 0.0);
    });
    
    RunAndMeasure("std::reduce, seq", [&vec] {
      return std::reduce(std::execution::seq,
			 vec.begin(), vec.end(), 0.0);
    });
    
    RunAndMeasure("std::reduce, par", [&vec] {
      return std::reduce(std::execution::par,
			 vec.begin(), vec.end(), 0.0);
    });
  }

  // test 3
  {
    std::vector<int> v(100);
    std::vector<int> w(100);

    // fill the range with sequentially increasing values, starting with value 0
    std::iota(v.begin(), v.end(), 0); 
    std::iota(w.begin(), w.end(), 0);
    
    std::vector<size_t> indexes(v.size());
    std::iota(indexes.begin(), indexes.end(), 0);
    std::for_each(std::execution::par, indexes.begin(), indexes.end(),
		  [&v, &w](size_t& id) {
		    Process(v[id], w[id]);
		  });
  }
  
  return 0;
}

