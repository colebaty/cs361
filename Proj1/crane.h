#ifndef __CRANE_H__
#define __CRANE_H__

#include "container.h"

class crane {
    private:
        int _id;
        bool _loaded;

        container * _cont;

        //private methods

    public:
        crane();
        crane(int id) { _id = id; }
        //public methods
        int getID() { return _id; }
        int setID(int id) { _id = id; }

        /**
         * @brief returns true if crane is currently loaded
         * 
         * @return true 
         * @return false 
         */
        bool isLoaded() { return _loaded; }

        /**
         * @brief loads the crane with the specified container, sets state to loaded
         * 
         * @param cont a pointer to the container to load into the crane
         */
        void load(container cont) ;

        /**
         * @brief unloads the container, sets state to not loaded
         * 
         * @return container 
         */
        container unload();

        /**
         * @brief if unloaded, returns 0; else returns ID of loaded container
         * 
         * @return int 
         */
        int getContID();

        void display();
};

#endif //__CRANE_H__