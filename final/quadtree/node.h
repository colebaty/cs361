#include <map>

using namespace std;


class node {
    private:
        int _val;

        node * _Q1;
        node * _Q2;
        node * _Q3;
        node * _Q4;

        //private methods
        void initialize();

    public:
        /*constructor*/
        node();
        node(int val);

        //public methods
        void add(int data);
};