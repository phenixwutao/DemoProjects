#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>

#include <map>
using namespace std;

std::tuple<char,float,std::string> getTyple()
{
    return {'c', 1.1, "hello"};
}

int main()
{
    {
    std::array<int,4> stdarr { 1, 2, 3, 4 };
    auto& [a,b,c,d] = stdarr;
    a += 10; // OK: modifies stdarr[0]
    }

    {
    std::array<int,4> stdarr { 1, 2, 3, 4 };
    const auto& [e,f,g,h] = stdarr;
    //e += 10; // ERROR: reference to constant object
    }

    {
    std::array<int,4> stdarr { 1, 2, 3, 4 };
    auto&& [i,j,k,l] = stdarr;
    i += 10; // OK: modifies stdarr[0]
    }

    {
    std::array<int,4> stdarr { 1, 2, 3, 4 };
    auto [a,b,c,d] = stdarr;
    a += 10; // OK: modifies copy of stdarr[0]
    }

    {
        auto [a,b,c] = getTyple();
        cout << a << ", " << b << " , " << c << '\n';
    }

    {
        std::map<string, int> coll;
        auto [pos, ok] = coll.insert({"new", 42});
        if (!ok) {
            cout << "coll insert failed\n";
        }
        else
        {
            cout << "coll insert success\n";
        }
    }
  return 0;
}

