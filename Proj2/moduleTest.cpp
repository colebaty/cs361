#include <map>
#include <utility>
#include <iostream>
#include <cassert>

#include "module.h"

using namespace std;

void printMap(map<char, pair<int, int>>& _map);

int main()
{
    cout << "testing base module" << endl;
    
    cout << "----------------------------" << endl;
    cout << "creating new default module" << endl;
    module m0;
    assert(m0.getID() == 0);
    m0.display();
    cout << "----------------------------" << endl;

    cout << "creating new module with id = 1, bl at (1.0, 1.0)" << endl;
    cout << "this also tests module::move, which is called through this constructor" << endl;
    module m1(1, 1.0, 1.0);
    assert(m1.getID() == 1);
    m1.display();
    
}

void printMap(map<char, pair<int, int>>& _map)
{
    map<char, pair<int, int>>::iterator mit = _map.begin();

    while (mit != _map.end())
    {
        //proof that enum types work
        assert(mit->first == _BL || mit->first == _BR || mit->first == _TR || mit->first == _TL);
        cout << mit->first << " " << mit->second.first << " " << mit->second.second << endl;
        mit++;
    }
}