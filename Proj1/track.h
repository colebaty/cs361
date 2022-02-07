/**
 * @file track.h
 * @author your name (you@domain.com)
 * @brief basic class for shipyard track. will be extended into "switching" 
 *        and "shipping" tracks
 * @version 0.1
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __TRACK_H__
#define __TRACK_H__

#include <queue>
#include "container.h"

using namespace std;

class track {
    private:
        queue<container> _track;

        bool _full;

        //private methods
    public:
        // constructor
        //public methods
};

#endif //__TRACK_H__