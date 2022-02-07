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

const int MAX_CAPACITY = 1000;
const int MIN_CAPACITY = 750;

class ship {
    private:
        int _id;
        int _capacity;
        int _numLoadedConts;
        
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
         * generated with incrementing IDs and pseud-randomly generated 
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
        ship(int id, int capacity = getRand(MIN_CAPACITY, MAX_CAPACITY));

        int getID() { return _id; }
        int getWidth() { return _width; }
        int getLength() { return _length; }
        int getNumLoadedConts() { return _numLoadedConts; }
        int getCapacity() { return _capacity; }

        /**
         * @brief returns a pointer to a container declared on the heap
         * 
         * @param row 
         * @param col 
         * @return container& 
         */
        container* getCont(int row, int col);

        void display();
};

#endif //__SHIP_H__