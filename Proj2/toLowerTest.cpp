#include <iostream>
#include <cctype>
#include <cassert>
#include "menuOptions.h"

using namespace std;

int main()
{
    cout << "testing cctype::tolower functionality" << endl
         << "specifically, testing what happens when a lowercase char is supplied" << endl;

    cout << "------------------------------------------" << endl;

    cout << "comparing \'a\' to tolower(\'A\')...";
    assert(_ADD == tolower('A'));
    cout << "pass" << endl;

    cout << "------------------------------------------" << endl;

    cout << "comparing \'a\' to tolower(\'a\')...";
    assert(_ADD == tolower('a'));
    cout << "pass" << endl;

    return 0;
}