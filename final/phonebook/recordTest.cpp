#include <iostream>
#include <string>
#include <map>
#include <random>
#include <ctime>

#include "record.h"

using namespace std;

string genName(uniform_int_distribution<int>& idist);
string genAddr(uniform_int_distribution<int>& idist);
string genPhone(uniform_int_distribution<int>& idist);

int main()
{
    string name = "cole";
    string addr = "211 n shore rd";
    string phone = "2987987";

    record r(name, addr, phone);

    r.display();

    cout << "------- 5 new records ---------" << endl;
    cout << "creating five new records; inserting into map with name as key" << endl;
    default_random_engine gen(time(NULL));
    uniform_int_distribution<int> idist('a', 'z');
    idist(gen);//discard first

    record * rptr;

    map<string, record> m;

    vector<string> names = {"tom", "jenny", "cole", "nathaniel", "laura"};
    vector<string> addresses = {
        "123 lkjadlkj", "298 aslkjd s", "29837 alskjdljkfa dr",
        "2982 alkjs lakjs", "2987 alskj dalksdj"
    };
    vector<string> phoneNos = {
        "19872987", "198729871", "298382629", "2983798723", "2983798273"
    };

    for (int i = 0; i < 5; i++)
    {
        rptr = new record(names[i], addresses[i], phoneNos[i]);
        m.insert({rptr->getName(), *rptr});
    }

    cout << "-------------" << endl;

    for (auto r : m)
    {
        r.second.display();
    }
    cout << "-------------" << endl;

    cout << "accessing record by name tom, i.e. m[\"tom\"]" << endl;

    *rptr = m["tom"];

    rptr->display();
    cout << "-------------" << endl;

    return 0;
}

string genName(uniform_int_distribution<int>& idist)
{
    
}

// string genAddr(uniform_int_distribution<int>& idist);
// {

// }

// string genPhone(uniform_int_distribution<int>& idist);
// {

// }
