#ifndef __NODE_H__
#define __NODE_H__

#include <queue>

using namespace std;

const int _A = 65;
const int _Z = 90;
const int _E = 69;

class node {
    private:
        /*instance variables*/
        int _id;
        queue<char> _q;

        //private methods

    public:
        /*constructor*/
        /**
         * @brief creates a new node with id = 0 and an empty queue.
         * 
         */
        node();
        
        /**
         * @brief creates a new node with the given id and an empty queue.
         * 
         * @param id 
         * @param data 
         */
        node(int id);
        //public methods

        /**
         * @brief pushes the given char into this node's queue.
         * 
         * @param data 
         */
        void push(char data);

        /**
         * @brief returns true if any instance of @param target is found in the
         * node's associated queue. rotates through the queue once, returning 
         * it to its original order.
         * 
         * @param target 
         * @return true 
         * @return false 
         */
        bool search(char target);

        void display();

        int getID() { return _id; }
};


#endif //__NODE_H__