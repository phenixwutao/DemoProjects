#include <iostream>

#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

using namespace std;

int main()
{
    // two shared pointers representing two persons by their name
    shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pJutta(new string("jutta"));

    // capitalize person names
    (*pNico)[0] = 'N';
    pJutta->replace(0,1,"J");
    
    // put them multiple times in a container
    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);

    // print all elements
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << "  ";
    }
    cout << endl;

    // overwrite a name again
    *pNico = "Nicolai";

    // print all elements again
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << "  ";
    }
    cout << endl;
    
    // print some internal data
    cout << "shared ptr use_count: " << whoMadeCoffee[0].use_count() << endl;

    // shared pointer with deleter
    shared_ptr<string> pnoci4(new string("hello"), [](string* p) {
      cout << "delete "<< *p << endl;
      delete p;
    });
    shared_ptr<string> p1 = make_shared<string>();
    p1 = pnoci4;
    shared_ptr<string> p2 = make_shared<string>();
    p2 = pnoci4;    
    cout << "shared ptr use_count: " << pnoci4.use_count() << endl;
    
    cout << "shared_ptr pnoci4: " << *pnoci4 << endl;
    pnoci4.reset(new string("Ncilloa"));
    cout << "shared_ptr pnoci4: " << *pnoci4 << endl;

    // shared ptr to host array need to supply a deleter
    shared_ptr<int> pintarr1(new int[10] {1,2,3},
			    [](int* p){delete [] p;}
			    );
  
    shared_ptr<int> pintarr2(new int[10] {1,2,3}, std::default_delete<int[]>() );

  return 0;  
}


