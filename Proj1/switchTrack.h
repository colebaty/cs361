#ifndef __SWITCHTRACK_H__
#define __SWITCHTRACK_H__

#include <queue>
#include <stack>
#include "container.h"

using namespace std;

class switchTrack {
    private:
        queue<container> _track;
        stack<container> _siding;

        int _id;
        int _max;
        int _maxSiding;

        //private methods
        /**
         * @brief returns true if siding track size is less than max allowable 
         * siding capacity
         * 
         * @return true 
         * @return false 
         */
        bool sidingFull();

    public:
        switchTrack();
        switchTrack(int id, int max = 40);
        //public methods

        /**
         * @brief switch track is full when both the main track is full. 
         * 
         * @return true 
         * @return false 
         */
        bool full();
        bool empty();

        /**
         * @brief if track not full, push container to track.
         * 
         * @param cont 
         */

        void push(container cont);

        /**
         * @brief push the container at the head of the main track to the
         * siding track
         * 
         * @param cont 
         */
        void pushToSiding();

        /**
         * @brief returns a reference to the container at the head of the 
         * switch track.
         * 
         * @return container& 
         */
        container getNext();
        int getNextDest();

        void display();
        int getID() { return _id ; }
        int size() { return _track.size(); }
};



#endif //__SWITCHTRACK_H__