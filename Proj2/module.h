#ifndef __MODULE_H__
#define __MODULE_H__

#include <utility>
#include <map>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

const double PI = acos(-1);

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
enum types:int {_BASE = 1, _HOUSING, _POWER, _LAB, _GYM, _STORAGE, _AIRLOCK};

/**
 * @brief handy references to individual module walls.  _BOW corresponds
 * to heading module-north. _SB => starboard
 * 
 */
enum dirs:char {_STERN, _SB, _BOW, _PORT, _LAST};


/**
 * @brief base module type. corners are indexed from bottom-left, proceeding CCW.
 * for purposes of flip, reverse, rotate, modules are always oriented from 
 * their North wall; that is, N-S is aligned with y-axis, and E-W is aligned 
 * with x-axis
 * 
 */
class module {
    protected:
        int _id;
        types _type;
        map<corners, pair<double, double>> _corners;
        map<dirs, pair<pair<double, double>, pair<double, double>>> _walls;
        map<dirs, module> _connections;

        int _maxConnections;

        //private methods
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
         * @brief shitty utility function to convert int into <dirs> enum type
         * 
         * @param i 
         * @return dirs 
         */
        dirs getWall(int i);

        /**
         * @brief arrange src corners to align with dst corners according to the
         * given src, dst walls. See README.md
         * 
         * @param srcWall 
         * @param dst 
         * @param dstWall 
         */
        void align(dirs& srcWall, module& dst, dirs& dstWall);

        /**
         * @brief shitty utility function to convert dir enum type to 
         * printable char
         * 
         * @param dir 
         * @return char 
         */
        char dir2char(dirs dir);

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

        //TODO expand this - need to make ofstream appendable?
        /**
         * @brief stub for writing to conf file
         * 
         * @param out 
         */
        void writeConfFile(ofstream& out);
        
        /**
         * @brief returns true if module has available connections
         * 
         * @return true 
         * @return false 
         */
        bool hasAvailable();

        /**
         * @brief a list of walls with no connections. if no available connections
         * returns an empty vector
         * 
         * @return vector<dirs> 
         */
        vector<dirs> getAvailable();

        //TODO sort out how to begin?
        /**
         * @brief connects this module to dst module. assumes dst module is
         * already attached to space station, and this module is not.
         * 
         * 
         * @param srcWall 
         * @param dst 
         * @param dstWall 
         */
        void connect(dirs srcWall, module& dst, dirs dstWall);

        /**
         * @brief rotate from x-axis deg degrees. deg > 0 => ccw
         * 
         * @param deg 
         */
        void rotate(double deg);


};


#endif //__MODULE_H__