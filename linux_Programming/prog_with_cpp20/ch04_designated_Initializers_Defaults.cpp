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

class Point3D
{
public:
  int x;
  int y = 1;
  int z = 2;
};

void needPoint(Point3D p) {
  std::cout << "p: " << p.x << " " << p.y << " " << p.z << '\n';
}

int main()
{
  cout <<std::boolalpha;
  // designated Initializers Defaults
  Point3D point1{.x = 0, .y = 1, .z = 2};
  std::cout << "point1: " << point1.x << " " << point1.y << " "
	    << point1.z << '\n';

  Point3D point2;
  std::cout << "point2: " << point2.x << " " << point2.y << " "
	    << point2.z << '\n';

  Point3D point3{.x = 0, .z = 20};
  std::cout << "point3: " << point3.x << " " << point3.y << " "
	    << point3.z << '\n';

  needPoint({.x = 0});

  // error: designator order for field ‘Point3D::y’ does not match declaration order in ‘Point3D’
  // Point3D point4 {.z = 20, .y = 1}; // Compile ERROR
  
  std::cout << std::endl;
  return 0;
}
