#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;
using namespace LFen;

void insertion_sort_asc(vector<int>& A, int n)
{
	int i, key, j;
	for (i=1; i<n; ++i)
	{
		PrintAll(A, "check");
		key = A[i];
		j = i-1;

		// move items [0, i-1]   0,...j, j+1
		// 0 1 2 3 4 5
		// 5 2 4 6 1 3
		while(j >= 0 && A[j] > key)
		{
			A[j+1] = A[j];
			j = j-1;
		}
		A[j+1] = key;
	}
}

void insertion_sort_desc(vector<int>& A, int n)
{
	int i, key, j;
	for (i=1; i<n; ++i)
	{
		PrintAll(A, "check");
		key = A[i];
		j = i-1;

		// move items [0, i-1]   0,...j, j+1
		// 0 1 2 3 4 5
		// 5 2 4 6 1 3
		while(j >= 0 && A[j] < key)
		{
			A[j+1] = A[j];
			j = j-1;
		}
		A[j+1] = key;
	}
}

int main(int argc, char* argv[])
{
  {
  std::vector<int> array = {5,2,4,6,1,3};
  int n = static_cast<int>(array.size());
  insertion_sort_asc(array, n);
  PrintAll(array, "after sort");
  }

  {
  std::vector<int> array = {5,2,4,6,1,3};
  int n = static_cast<int>(array.size());
  insertion_sort_desc(array, n);
  PrintAll(array, "after sort");
  }

  return 0;
}

