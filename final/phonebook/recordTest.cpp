#include <iostream>
#include <string>
#include <map>
#include <random>
#include <ctime>
#include <cassert>

#include "record.h"

using namespace std;

typedef map<string, record> mapRecord;

void find(mapRecord & m);
void find(mapRecord & m, string target);

int main()
{
    record * rptr;

    mapRecord m;
    mapRecord maddr;

    vector<string> names = {"tom", "jenny", "cole", "nathaniel", "laura"};
    vector<string> addresses = {
        "123 lkjadlkj", "298 aslkjd s", "211 n shore rd",
        "2982 alkjs lakjs", "2987 alskj dalksdj"
    };
    vector<string> phoneNos = {
        "19872987", "198729871", "298382629", "2983798723", "2983798273"
    };

    for (int i = 0; i < 5; i++)
    {
        rptr = new record(names[i], addresses[i], phoneNos[i]);
        m.insert({rptr->getName(), *rptr});
        maddr.insert({rptr->getAddr(), *rptr});
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
    cout << "accessing record by variable name" << endl;
    *rptr = m[names[2]];
    rptr->display();

    cout << "-------------" << endl;
    cout << "getting name by user input" << endl;
    find(m);


    cout << "-------------" << endl;
    cout << "creating map from addresses" << endl;
    
    cout << "getting address by user input" << endl;
    string in;
    cout << "address to look up: ";
    getline(cin, in);
    find(maddr, in);

    return 0;
}

void find(mapRecord & m)
{
    cout << "-------------" << endl;
    string in;
    cout << "name to look up: ";
    getline(cin, in);

    mapRecord::iterator mit;
    mit = m.find(in);
    if (mit != m.end())
    {
        mit->second.display();
    }
    else
    {
        cout << "record not found" << endl;
    }
}

void find(mapRecord & m, string target)
{
    cout << "-------------" << endl;

    mapRecord::iterator mit;
    mit = m.find(target);
    if (mit != m.end())
    {
        mit->second.display();
    }
    else
    {
        cout << "record not found" << endl;
    }
}