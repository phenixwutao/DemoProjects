#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>

#include <map>
#include <vector>
using namespace std;

class Customer
{
  private:
    std::string first;
    std::string last;
    long val;

  public:
    Customer (string f, string l, long v) : first(std::move(f)), last(std::move(l)), val(v)
    {       
    }

    string getFirst() const
    {
        return first;
    }

    string getLast() const
    {
        return last;
    }
    long getValue() const
    {
        return val;
    }

    const std::string& firstname() const
    {
        return first;
    }

    string& firstname()
    {
        return first;
    }

    const std::string& lastname() const
    {
        return last;
    }

    string& lastname()
    {
        return last;
    }

    long value() const
    {
        return val;
    }

    long& value()
    {
        return val;
    }
};


// provide a tuple-like API for class Customer for structured binding
template<>
struct std::tuple_size<Customer>
{
    static constexpr int value = 3;
};

template<>
struct std::tuple_element<2, Customer>
{
    using type = long; // last element 2 is long
};

template<std::size_t Idx>
struct std::tuple_element<Idx, Customer>
{
    using type = std::string; // other elements (0,1) are string
};

// define specific getters
template<std::size_t> decltype(auto) get(const Customer& c);
template<std::size_t> decltype(auto) get(Customer& c);
template<std::size_t> decltype(auto) get(Customer&& c);

template<> decltype(auto) get<0>(const Customer& c) { return c.firstname(); }
template<> decltype(auto) get<0>(Customer& c) { return c.firstname(); }
template<> decltype(auto) get<0>(Customer&& c) { return std::move(c.firstname()); }

template<> decltype(auto) get<1>(const Customer& c) { return c.lastname(); }
template<> decltype(auto) get<1>(Customer& c) { return c.lastname(); }
template<> decltype(auto) get<1>(Customer&& c) { return std::move(c.lastname()); }

template<> decltype(auto) get<2>(const Customer& c) { return c.value(); }
template<> decltype(auto) get<2>(Customer& c) { return c.value(); }
template<> decltype(auto) get<2>(Customer&& c) { return c.value(); }

template<std::size_t I>
decltype(auto) get(const Customer& c)
{
    static_assert(I < 3);
    if constexpr (I == 0)
        return c.firstname();
    else if constexpr (I == 1)
        return c.lastname();
    else if constexpr (I == 2)
        return c.value();
}

template<std::size_t I>
decltype(auto) get(Customer& c)
{
    static_assert(I < 3);
    if constexpr (I == 0)
        return c.firstname();
    else if constexpr (I == 1)
        return c.lastname();
    else if constexpr (I == 2)
        return c.value();
}

template<std::size_t I>
decltype(auto) get(Customer&& c)
{
    static_assert(I < 3);
    if constexpr (I == 0)
        return std::move(c.firstname());
    else if constexpr (I == 1)
        return std::move(c.lastname());
    else if constexpr (I == 2)
        return c.value();
}

int main()
{
    Customer c {"Tim", "Star", 42};
    auto [f, l, v] = c;
    cout << f << " , " << l << " , " << v << '\n';

    auto&& [f2, l2, v2] = c;
    cout << f2 << " , " << l2 << " , " << v2 << '\n';

    string s {std::move(f2)};
    f2 = "Ringo";
    v2 += 10;
    cout << f2 << " , " << l2 << " , " << v2 << '\n';
    cout << c.firstname() << " , " << c.lastname() << " , " << c.value() << '\n';
    cout << s << endl;

  return 0;
}

