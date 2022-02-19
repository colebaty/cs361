/**
 * @file ship.h
 * @author your name (you@domain.com)
 * @brief ship class for shipping port assignment spring 22 CS 361
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * _cargo is a 2d data structure with _width rows and _length columns. individual
 * containers are accessed by (row, column).
 * 
 */
#ifndef __SHIP_H__
#define __SHIP_H__

// uncomment for more info in display()
#define DEBUG

#include <vector>
#include <stack>

#include "shiputils.h"
#include "container.h"

using namespace std;

const int SHIP_MAX_CAPACITY = 1000;
const int SHIP_MIN_CAPACITY = 750;

class ship {
    private:
        int _id;
        int _capacity;
        int _numLoadedConts;

        int _lastX, _lastY;
        
        //super private instance variables just for debugging
        int _numLevels;
        int _contsPerLevel;
        /**
         * @brief column
         * 
         */
        int _width;
        /**
         * @brief row
         * 
         */
        int _length;

        /**
         * @brief the cargo hold. best thought of as
         * container -> stack -> columns -> layers
         * accessed through _cargo[x][y].top()
         * 
         */
        vector<vector<stack<container>>> _cargo;
        //private methods

        /**
         * @brief private method to fill the cargo hold. containers are
         * generated with incrementing IDs and pseudo-randomly generated 
         * destination codes
         */
        void fillCargo();

        #ifdef DEBUG
        void displayCargoInfo();
        #endif

    public:
        /**
         * @brief default constructor, initializes a ship object with
         * id = 0, capacity = 0;
         * 
         */
        ship();

        /**
         * @brief initializes a ship object with the specified ID. unless otherwise 
         * specified, capacity will be a random integer on the interval 
         * [MIN_CAPACITY, MIN_CAPACITY].
         * 
         * @param id 
         * @param min 
         * @param max 
         */
        ship(int id, int capacity = getRand(SHIP_MIN_CAPACITY, SHIP_MAX_CAPACITY));

        int getID() { return _id; }
        int getWidth() { return _width; }
        int getLength() { return _length; }
        int getNumLevels() { return _numLevels; }
        int getNumLoadedConts() { return _numLoadedConts; }
        int getCapacity() { return _capacity; }

        /**
         * @param row 
         * @param col 
         * @return container& 
         */


        /**
         * @brief returns false if cargo hold is empty; otherwise returns true
         * 
         * @return true 
         * @return false 
         */
        bool hasNext();

        /**
         * @brief stub for getting next container. cargo is 2D vector of stacks 
         * accessed by [x][y].top(). need to figure out some way of keeping 
         * track of which stack was last visited, so that I can determine 
         * whether or not it's empty.
         * 
         * for now, returns a reference to a container with randomly generated 
         * destination code.
         * 
         * @return container& 
         */
        container& getNext();

        bool empty() { return _cargo.empty(); }

        void display();
};

#endif //__SHIP_H__