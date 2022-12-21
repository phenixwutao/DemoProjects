namespace ext
{
  template <typename T>
  struct wrapper
  {
    T data;
  };

  extern template struct wrapper<int>; // [1] explicit instantiation declaration
  void f();
  void g();
}