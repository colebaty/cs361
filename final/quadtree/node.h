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
        /**
         * @brief adds data to the tree/subtree rooted at this node. if
         * data is already found in the tree, this data is discarded. as
         * a result, node::display may show fewer than N nodes.
         * 
         * @param data 
         */
        void add(int data);

        /**
         * @brief depth first display function
         * 
         */
        void display();
};


#endif //__NODE_H__