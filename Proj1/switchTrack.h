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

        int _max;

        //private methods
        void pushToSiding(container cont);

    public:
        switchTrack();
        //public methods

        bool full();

        void push(container cont);
        void display();
};



#endif //__SWITCHTRACK_H__