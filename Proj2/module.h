#ifndef __MODULE_H__
#define __MODULE_H__

#include <utility>
#include <map>

using namespace std;

const double HALLWAY_LEN = 5.0;
const double HALLWAY_WID = 5.0;

/**
 * @brief unique <map> keys for module corners
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
         * @brief initializes a 5x5 hallway module with bottom-left corner at (0,0)
         * 
         */
        void initialize();

        //private methods
    public:
        module();
        module(int id);
        /**
         * @brief Construct a new "base"/hallway module at the given (x,y) 
         * coordinate pair, which describes the lower left corner of the module.
         * 
         * @param id 
         * @param x x coord for bottom left corner 
         * @param y y coord for bottom left corner
         */
        module(int id, double x = 0.0, double y = 0.0);
        //public methods
};


#endif //__MODULE_H__