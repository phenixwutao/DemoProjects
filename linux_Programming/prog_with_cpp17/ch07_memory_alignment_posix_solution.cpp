#include <iostream>

using aligned_int alignas(0x1000) = int;

int main()
{
  // use posix_memalign() or aligned_alloc()
  int* ptr;
  // 0x1000 is the alignment address
  if (posix_memalign(reinterpret_cast<void**>(&ptr), 0x1000, 42*sizeof(int)))
  {
    std::cerr << "ERROR: unable to allocate aligned mmeory\n";
    exit(EXIT_FAILURE);
  }
  std::cout << "posix_memalign " << ptr << std::endl;
  free(ptr);

  // use aligned_alloc function
  if (auto ptr1 = aligned_alloc(0x1000, 42* sizeof(int)))
  {
    std::cout << "aligned_alloc " << ptr1 << '\n';
    free(ptr1);
  }

  // C++17 aligned allocation by using new(), compile with c++17 std
  auto ptr2 = new aligned_int;
  std::cout << "new aligned_int "<< ptr2 << '\n';
  delete ptr2;

  auto ptr3 = new aligned_int[42];
  std::cout << "new aligned_int[] "<< ptr3 << '\n';
  delete [] ptr3;

  return 0;
}
