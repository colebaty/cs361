#ifndef __NODE_H__
#define __NODE_H__

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

        void display();
};


#endif //__NODE_H__