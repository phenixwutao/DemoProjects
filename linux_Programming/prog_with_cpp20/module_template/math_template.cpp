// declare a module
export module math_template;

// host lib function within namespace
export namespace mathlib
{
  template <typename U, typename V>
  auto sum(U u, V v)
  {
    return u + v;
  }

  // this function has internal linkage
  static int mod(int a, int b)
  {
    return a%b;
  }

  // this anonymous namespace function has internal linkage
  namespace
  {
    double cube(double v)
    {
      return v*v*v;
    }
  }

}

// This function has module linkage
export double cube2(double v)
{
  return v*v*v;
}

