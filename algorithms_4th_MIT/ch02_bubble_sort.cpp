#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;
using namespace LFen;


void bubble_sort(vector<int>& A, int n)
{
	for (int i=0; i < n ; ++i)
	{
		for(int j = n; j > i; --j)
		{
			if (A[j] < A[j-1])
				swap(A[j], A[j-1]);
		}
	}
}

int main(int argc, char* argv[])
{
  {
  std::vector<int> array = {5,2,4,6,1,3};
  int n = static_cast<int>(array.size());
  bubble_sort(array, n);
  PrintAll(array, "after sort");
  }

  return 0;
}

