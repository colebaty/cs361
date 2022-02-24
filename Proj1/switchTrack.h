#ifndef __SWITCHTRACK_H__
#define __SWITCHTRACK_H__

#include <queue>
#include <stack>
#include "container.h"

using namespace std;

const int SWITCH_TRACK_MAX_CAP = 40;

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
        /**
         * @brief creates a new switchtrack with given id and default main
         * track capcity of 40. siding track capacity is one less than main
         * track capacity.
         * 
         * @param id 
         * @param max 
         */
        switchTrack(int id, int max = SWITCH_TRACK_MAX_CAP);
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
         * @brief returns true if main track is not empty and siding track is
         * not empty
         * 
         * @return true 
         * @return false 
         */
        bool hasNext() { return !_track.empty() && !_siding.empty(); }

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
        container getNextFromSiding();
        int getNextDest();
        int getNextSidingDest();
        int getNextContID();

        void display();
        int getID() { return _id ; }
        int size() { return _track.size(); }
};



#endif //__SWITCHTRACK_H__