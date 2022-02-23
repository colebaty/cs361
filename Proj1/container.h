#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "shipTrack.h"

const int CONT_MIN_DEST = 100;
const int CONT_MAX_DEST = 999;
const int CONT_BASE_ID = 10000;

class container
{
    private:
        int _id;
        int _dest;

    public:
        //constructor
        container();
        
        /**
         * @brief Constructs a new container object with the given id. 
         * destination codes are generated randomly.  please note that srand 
         * must be seeded in the `main` function
         * 
         * TODO
         * [ ] randomize id?
         */
        container(int id);
        container(const container& other);

        int getID() { return _id; }
        int getDest() { return _dest; }

        void setID(int id) { _id = id; }
        void setDest(int dest) { dest = _dest; }

        void display(std::ostream& out = std::cout);

        bool operator== (const shipTrack& rtside) const;
};

#endif //__CONTAINER_H__