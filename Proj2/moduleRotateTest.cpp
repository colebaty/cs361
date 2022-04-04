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
    cout << "creating new module with id = 1" << endl;
    module m1(1);
    assert(m1.getID() == 1);
    m1.display();

    cout << "----------------------------" << endl;
    cout << "testing module rotation" << endl;

    double deg;
    cout << "degrees to rotate? ";
    cin >> deg;
    cout << endl;

    m1.rotate(deg);
    m1.display();


    return 0;
    
}
