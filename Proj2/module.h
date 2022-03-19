#ifndef __MODULE_H__
#define __MODULE_H__

#include <utility>
#include <map>
#include <list>

using namespace std;

/**
 * @brief along x-axis
 * 
 */
const double HALLWAY_LEN = 5.0;
/**
 * @brief along y-axis
 * 
 */
const double HALLWAY_WID = 5.0;

/**
 * @brief unique <map> keys for module corners. helpful to print in the same order
 * implied by enum; items stored in <map>s are sorted upon insertion. this enum
 * ensures traversal of the map occurs in ccw fashion starting from bottom-left
 * 
 */
enum corners:char {_BL, _BR, _TR, _TL};

/**
 * @brief unique module types for inheritance purposes
 * 
 */
enum types:char {_BASE};

/**
 * @brief base module type. corners are indexed from bottom-left, proceeding
 * CCW; that is
 *  bottom-left:    _corners[0][0] and _corners[0][1]
 *  bottom-right:   _corners[1][0] and _corners[1][1]
 *  top-right:      _corners[2][0] and _corners[2][1]
 *  top-left:       _corners[3][0] and _corners[3][1]
 * 
 */
class module {
    protected:
        int _id;
        char _type;
        map<char, pair<double, double>> _corners;

        /**
         * @brief [0, 1, 2, 3] -> [N, W, E, S]
         * 
         */
        module * _connections[4];

        /**
         * @brief initializes a 5x5 hallway module with id set to 0 and 
         * bottom-left corner at (0,0)
         * 
         */
        void initialize();

        //private methods
    public:
        /**
         * @brief Default constructor - id set to zero, bottom-left corner at
         * (0,0)
         * 
         */
        module();
        /**
         * @brief Construct a new "base"/hallway module with the given ID 
         * at the given (x,y) coordinate pair, which describes the bottom-left 
         * corner of the module.
         * 
         * @param id 
         * @param x x coord for bottom left corner 
         * @param y y coord for bottom left corner
         */
        module(int id, double x = 0.0, double y = 0.0);
        //public methods

        void move(double dx, double dy);
        void display();
        void printType();

        char getType() { return _type; };
        int getID() { return _id; };

        bool hasAvailable();

};


#endif //__MODULE_H__