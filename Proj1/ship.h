#ifndef __SHIP_H__
#define __SHIP_H__

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
        
        //super private instance variables just for debugging
        int _numLevels;
        int _contsPerLevel;
        int _width;
        int _length;

        /**
         * @brief a 2D vector of stacks of containers. a 2D vector of stacks 
         * eliminates the need to access any container below the topmost 
         */
        vector<vector<stack<container>>> * _cargo;
        //private methods

        /**
         * @brief private method to fill the cargo hold. containers are
         * generated with incrementing IDs and pseud-randomly generated 
         * destination codes
         */
        vector<vector<stack<container>>> fillCargo();
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

        int getCapacity() { return _capacity; }

        void display();
};

#endif //__SHIP_H__