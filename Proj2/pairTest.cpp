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

    

    return 0;
}