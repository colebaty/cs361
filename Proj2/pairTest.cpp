#include <map>
#include <utility>
#include <iostream>
#include <cassert>

#include "module.h"

using namespace std;

int main()
{
    cout << "testing pair creation" << endl;
    pair<int, int> bl = make_pair(0, 0);
    cout << "bl: " << bl.first << " " << bl.second << endl;

    int * first;
    int * second;

    first = &get<0>(bl);
    second = &get<1>(bl);

    assert(*first == 0 && *second == 0);

    cout << "*first:\t\t" << *first << endl
         << "*second:\t" << *second << endl;

    cout << "---------------------" << endl;

    cout << "attempting to modify contents of pair through pointers" << endl;

    *first = 10;
    *second = 100;

    cout << "---------------------" << endl;

    assert(bl.first == 10 && bl.second == 100);

    cout << "bl.first:\t" << bl.first << endl
         << "bl.second:\t" << bl.second << endl;


    cout << "*first:\t\t" << *first << endl
         << "*second:\t" << *second << endl;

    cout << "---------------------" << endl;

    cout << "creating some modules" << endl;

    module * modptr; 
    int modID = 100;
    map<int, module> mymap;

    for (int i = 0; i < 5; i++)
    {
         modptr = new module(modID++);
         mymap.insert(make_pair(modptr->getID(), *modptr));
    }

    cout << "available modules: ";
    map<int, module>::iterator mit = mymap.begin();
    while (mit != mymap.end())
    {
         cout << mit->first << " ";
         mit++;
    }
    cout << endl;

    cout << "---------------------" << endl;
    
    cout << "get specific module (ID): ";
    int choice;
    cin >> choice;

    mit = mymap.find(choice);
    mit->second.display();

    cout << "---------------------" << endl;
    cout << "attempting to move selected module through mit->second" << endl;

    mit->second.move(10.0, 10.0);
    mit->second.display();

    cout << "---------------------" << endl;
    cout << "attempting to move selected module through get<module>" << endl;

    modptr = &get<1>(*mymap.find(choice));
    modptr->move(-3.0, -3.0);

    modptr->display();

    cout << "---------------------" << endl;
    cout << "creating a pair where the second element is a pair of doubles" << endl;
    pair<int, pair<double, double>> doublePair = make_pair(1, make_pair(1.0, 2.0));

    cout << "pair: " << doublePair.first << endl
         << "\tfirst double: " << doublePair.second.first << endl
         << "\tsecond double: " << doublePair.second.second << endl
         << endl;

    cout << "---------------------" << endl;
    cout << "attemptining to assign doublPair.second values to pointers" << endl;

    double *x, *y;
    x = &get<0>(doublePair.second);
    y = &get<1>(doublePair.second);

    cout << "x: " << *x << endl
         << "y: " << *y << endl;

    cout << "---------------------" << endl;
    cout << "attempting to modify values of x, y" << endl;

    *x = 100 * *x;
    *y = 1000 * *y;

    cout << "x: " << *x << endl
         << "y: " << *y << endl;

    cout << "pair: " << doublePair.first << endl
            << "\tfirst double: " << doublePair.second.first << endl
            << "\tsecond double: " << doublePair.second.second << endl
            << endl;

    return 0;
}