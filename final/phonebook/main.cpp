#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

#include "record.h"

using namespace std;

typedef map<string, record*> mapRecord;

enum menuOptions:char { _NAME = 'a', _ADDR = 'b', _PHONE = 'c', _EXIT = 'x' };
const char _DELIM = ',';

char menu();
void find(mapRecord & m, string target);
void loadFile(mapRecord& names, mapRecord & addresses, mapRecord & phones);

int main()
{
    mapRecord names;
    mapRecord addresses;
    mapRecord phones;

    loadFile(names, addresses, phones);

    char ans;
    do
    {
        ans =  menu();
        string target;

        switch (ans)
        {
        case _NAME:
            cout << "find name: ";
            cin>>ws;
            getline(cin, target);
            find(names, target);
            break;
        
        case _ADDR:
            cout << "find address: ";
            cin>>ws;
            getline(cin, target);
            find(addresses, target);
            break;
        
        case _PHONE:
            cout << "find phone: ";
            cin>>ws;
            getline(cin, target);
            find(phones, target);
            break;
        
        case _EXIT:
            break;

        default:
            cout << "invalid selection; try again" << endl;
            cin.ignore(100, '\n');
            break;
        }

    } while (ans != _EXIT);

    cout << endl;
    
    return 0;
}

char menu()
{
    cout << "\tphone book" << endl
         << "a) Search by name" << endl
         << "b) Search by addresses" << endl
         << "c) Search by number" << endl
         << "x) Exit" << endl;

    cout << "choice: ";
    char in;
    cin >> in;

    return in;
}

void find(mapRecord & m, string target)
{
    cout << "-------------" << endl;

    mapRecord::iterator mit;
    mit = m.find(target);
    if (mit != m.end())
    {
        mit->second->display();
    }
    else
    {
        cout << "record not found" << endl;
    }
    cout << "-------------" << endl;
}

void loadFile(mapRecord& names, mapRecord & addresses, mapRecord & phones)
{
    ifstream * infile = new ifstream("phonebook");
    string line;
    istringstream * in;

    string name, address, phone;

    record * rptr;

    while (!infile->eof())
    {
        getline(*infile, line);
        in = new istringstream(line);
        getline(*in, name, _DELIM);
        getline(*in, address, _DELIM);
        getline(*in, phone, _DELIM);

        rptr = new record(name, address, phone);
        names.insert({rptr->getName(), rptr});
        addresses.insert({rptr->getAddr(), rptr});
        phones.insert({rptr->getPhone(), rptr});

    }

}