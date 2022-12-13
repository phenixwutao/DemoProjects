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

struct Point2D {
  int x;
  int y;
};

class Point3D {
public:
  int x;
  int y;
  int z;
};

int main()
{
  cout <<std::boolalpha;
  Point2D point2D{.x = 1, .y = 2.5}; // compile error: narrowing conversion
  Point3D point3D{.x = 1, .y = 2, .z = 3.5f}; // compile error: narrowing conversion

  std::cout << "point2D: " << point2D.x << " " << point2D.y << '\n';
  std::cout << "point3D: " << point3D.x << " " << point3D.y << " "
	    << point3D.z << '\n';

  /*
   * Designated initialization is a special case of aggregate initialization
   * and enables it to initialize the class members using their name. The
   * initialization order must match the declaration order.
   */
  return 0;
}
