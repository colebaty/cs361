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

        int _maxOnTrack;
        int _maxOnSiding;

        //private methods
    public:
        switchTrack();
        switchTrack(int maxOnTrack = 40, int maxOnSiding = 39);
        //public methods

        bool full();

        void push(container cont);
};



#endif //__SWITCHTRACK_H__