#include <iostream>
using namespace std;

int main()
{
  // POSIX : portable operating system interface
  // example 2 POSIX API
  {
    void* ptr = NULL;
    if (posix_memalign(&ptr, 0x1000, 42* sizeof(int)))
      {
	std::clog << "ERROR: imable to allocate aligned memory\n";
	::exit(EXIT_FAILURE);
      }
    std::cout << ptr << '\n';
    free(ptr);
  }

  /* POSIX file system:
   * /bin
   * /boot
   * /dev
   * /home
   * /lib
   * /mnt, /media
   * /sbin
   * /tmp
   * /usr
   **********/
  
    
  return 0;
}
