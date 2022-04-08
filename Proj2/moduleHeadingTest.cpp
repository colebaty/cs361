#include <map>
#include <utility>
#include <iostream>
#include <cassert>

#include "module.h"

using namespace std;

int main()
{
    cout << "creating two modules" << endl;

    int modID = 100;
    module m1(modID++);
    module m2(modID++);

    m1.display();
    m2.display();

    cout << "--------------------------" << endl;

    cout << "connecting m2_SB to m1_BOW" << endl;

    m2.connect(_SB, m1, _BOW);

    m1.display();
    m2.display();


}