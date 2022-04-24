#ifndef __RECORD_H__
#define __RECORD_H__

#include <string>

using namespace std;

class record {
    private:
        string _name;
        string _address;
        /**
         * @brief stored as string. must verify user input
         * 
         */
        string _phoneNo;

        //private methods

    public:
        /*constructor*/
        record();
        record(string& name, string& address, string& _phoneNo);

        //public methods
        string getName() { return _name; }
        string getAddr() { return _address; }
        string getPhone() {return _phoneNo; }

        void display();
};


#endif //__RECORD_H__