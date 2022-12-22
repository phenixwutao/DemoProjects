#include <stdarg.h>
#include <iostream>

using namespace std;


template<typename T>
T MinValue(int count, ...)
{
  va_list args;
  va_start(args, count);  // start iteration of arguments
  T val = va_arg(args, T);
  for(int i = 1; i < count; i++)
  {
    T n = va_arg(args, T);  // access/read the argument
    val = (n < val) ? n : val;
  }
  va_end(args); // end iteration of arguments
  return val;
}


int mymin(int count, ...)
{
  va_list args;
  va_start(args, count);

  int val = va_arg(args, int); // read first argument value

  for(int i = 1; i < count; i++)
  {
    int n = va_arg(args, int);
    val = (n < val) ? n : val;
  }
  va_end(args);

  return val;
}

int main ()
{
  std::cout << "mymin is " << mymin(5, 1,5,3,-4,-9) << endl;
  std::cout << "MinValue<int> is " << MinValue<int>(5, 1,5,3,-4,-9) << endl;
  return 0;
}