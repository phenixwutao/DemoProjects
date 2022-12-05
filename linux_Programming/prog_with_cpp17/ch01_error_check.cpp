#include <iostream>

std::pair<int,int> myfunc(int val)
{
  if (val == 42)
    return {0, -1};
  
  //return std::make_pair<int,int>(std::move(val), 0);
  return {val,0};
}

 
int main()
{
  if (auto [val, error_code] = myfunc(42); error_code == -1)
    {
      printf("catch an error\n");
    }
  return 0;
}

