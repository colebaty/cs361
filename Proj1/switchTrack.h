#ifndef __SWITCHTRACK_H__
#define __SWITCHTRACK_H__

#include <queue>
#include <stack>
#include "container.h"

using namespace std;

class switchTrack {
    private:
        queue<container> _track;

        int _id;
        int _max;

        //private methods
        void pushToSiding(container cont);

    public:
        switchTrack();
        switchTrack(int id) { _id = id; _max = 40; }
        //public methods

        bool full();

        void push(container cont);
        void display();
        int getID() { return _id ; }
};



#endif //__SWITCHTRACK_H__