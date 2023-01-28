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
template<std::size_t> auto get(const Customer& c);
template<> auto get<0>(const Customer& c) {return c.getFirst();}
template<> auto get<1>(const Customer& c) {return c.getLast();}
template<> auto get<2>(const Customer& c) {return c.getValue();}

template<std::size_t I> auto get(const Customer& c)
{
    static_assert(I<3);
    if constexpr (I==0)
    {
        return c.getFirst();
    }
    else if (I==1)
    {
        return c.getLast();
    }
    else if (I==2)
    {
        return c.getValue();
    }
}

int main()
{
    Customer c {"Tim", "Star", 42};
    auto [f, l, v] = c;
    cout << f << " , " << l << " , " << v << '\n';
    cout << c.getFirst() << endl;
    cout << c.getLast() << endl;
    cout << c.getValue() << endl;

    std::vector<Customer> coll;
    coll.push_back(c);
    coll.push_back({"Adam", " Tadd", 33});
    for(const auto& [first, last, val] : coll)
    {
        cout << first << " , " << last << " , " << val << '\n';
    }
  return 0;
}

