#ifndef __SHIPTRACK_H__
#define __SHIPTRACK_H__

#include <queue>

#include "shiputils.h"

#include "container.h"

using namespace std;

class shipTrack {
    private:
        int _id;
        /**
         * @brief like an ICMP packet; intent is to decrement at the end of each
         * timestep
         */
        int _ttl;
        int _cap;
        int _dest;
        queue<container> _contents;
        //private methods
    public:
        //constructors
        /**
         * @brief defaults are 0 or empty as appropriate.
         * 
         */
        shipTrack();
        /**
         * @brief instantiates a new shipping track with a default ttl (i.e., 
         * time to depart), and default capacity
         * 
         * @param id 
         * @param ttl 
         * @param cap 
         */
        shipTrack(int id, int ttl = 100, int cap = 100, int dest = getRand(1,9));

        //public methods
        void push(container cont);
        /**
         * @brief returns true IF train has reached capacity OR train ttl has
         * expired but capcity is >= 80% full
         * 
         * @return true 
         * @return false 
         */
        bool ready();
        bool full();

        void display();
        /**
         * @brief updates ttl by decrementing
         * 
         */
        void update();

        int getID() {return _id; }
        int getDest() { return _dest; }
        int getTTL() { return _ttl; }
};


#endif //__SHIPTRACK_H__