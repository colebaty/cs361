#include <iostream>
#include <string>

#include "record.h"

using namespace std;

record::record()
{
    _name = "";
    _address = "";
    _phoneNo = "";
}

record::record(string& name, string& address, string& phoneNo)
{
    _name = name;
    _address = address;
    _phoneNo = phoneNo;
}

void record::display()
{
    cout << "------------------" << endl;
    cout << "\tName:\t" << getName() << endl
         << "\tAddr.:\t" << getAddr() << endl
         << "\tPh.Nr.:\t" << getPhone() << endl;
    cout << "------------------" << endl;
}