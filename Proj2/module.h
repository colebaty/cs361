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
 * @brief maximum number of connections to a hallway module
 * 
 */
const int HALLWAY_MAX_CONNECTIONS = 4;

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
 * @brief wall directions, North-indexed, proceeding CCW
 * 
 */
enum dirs:int {_N = 0, _W, _S, _E};


/**
 * @brief base module type. corners are indexed from bottom-left, proceeding CCW
 * 
 */
class module {
    protected:
        int _id;
        char _type;
        map<char, pair<double, double>> _corners;
        map<int, pair<pair<double, double>, pair<double, double>>> _walls;

        /**
         * @brief [0, 1, 2, 3] -> [N, W, S, E]
         * 
         */
        module **_connections;

        /**
         * @brief initializes a 5x5 hallway module with id set to 0 and 
         * bottom-left corner at (0,0)
         * 
         */
        void initialize();

        /**
         * @brief updates walls map after a call to module::move
         * 
         */
        void updateWalls();

        /**
         * @brief swap top and bottom pairs of x coords to reverse over
         * y-axis
         * 
         */
        void reverse();
        /**
         * @brief swap top and bottom pairs of y coords to flip over x-axis
         * 
         */
        void flip();
        /**
         * @brief rotate from x-axis deg degrees. deg > 0 => ccw
         * 
         * @param deg 
         */
        void rotate(int deg);

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

        /**
         * @brief writes corners to data file specified by given <ofstream> param.
         * 
         * 
         * @param out 
         */
        void writeDataFile(ofstream& out);
        
        bool hasAvailable();

        /**
         * @brief connect this.wall to target.wall.  assumption is that target
         * is already attached to space station. verb is transitive.
         * 
         * @param srcWall 
         * @param target 
         * @param targetWall 
         */
        // void connect(int srcWall, module& target, int targetWall);
};


#endif //__MODULE_H__