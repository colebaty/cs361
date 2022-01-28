#ifndef __CONTAINER_H__
#define __CONTAINER_H__

class container
{
    private:
        int _id;
        int _dest;

    public:
        //constructor
        container();

        int getID() { return _id; }
        int getDest() { return _dest; }

        void setID(int id) { _id = id; }
        void setDest(int dest) { dest = _dest; }
};

#endif //__CONTAINER_H__