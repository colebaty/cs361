#ifndef __MODULE_H__
#define __MODULE_H__

#include <cmath>

using namespace std;

enum types:char {_BASE};
/**
 * @brief the default distance between bottom-left and top-right
 * corners for a 5x5 "base"/hallway module. Used to plot the other corners
 * of the module.
 * 
 */
const double DEFAULT_DIAG_DIST = sqrt(50);

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
        double _corners[4][2];

        /**
         * @brief initializes corners to (0,0)
         * 
         */
        void initialize();
        /**
         * @brief uses the Pythagorean theorem to fill each corner using the 
         * given diagonal distance 
         * 
         * @param diag 
         */
        void fillCorners(double diag = DEFAULT_DIAG_DIST);
        
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
         * @param diag the diagonal distance between bottom-left and top-right
         *             corners
         */
        module(int id, double x, double y, double diag = DEFAULT_DIAG_DIST);
        //public methods
};


#endif //__MODULE_H__