#include <fcntl.h>
#include <string.h>
#include <iostream>

using namespace std;

class custom_errno
{};

/*
std::ostream& operator<< (std::ostream& os, const custom_errno& errno)
{
  os << strerror(errno);
  return os;
}
*/

std::ostream &operator<<(std::ostream &os, const custom_errno &e)
{ return os << strerror(errno); }


int main()
{
  if (open("filename.txt", O_RDWR) == -1)
    {
      cout << custom_errno {} << endl;
    }
  return 0;
}
