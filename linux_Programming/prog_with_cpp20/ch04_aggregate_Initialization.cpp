#include <concepts>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>
#include <iostream>

#include <type_traits>

#include <compare>
using namespace std;

struct Point2D
{
  int x;
  int y;
};

class Point3D
{
public:
  int x;
  int y;
  int z;
};

int main()
{
  cout <<std::boolalpha;

  // aggregate initialization
  Point2D point2D{1, 2};
  Point3D point3D{1, 2, 3};

  std::cout << "point2D: " << point2D.x << " " << point2D.y << '\n';
  std::cout << "point3D: " << point3D.x << " " << point3D.y << " "
	    << point3D.z << '\n';  
  return 0;
}
