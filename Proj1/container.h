#ifndef __CONTAINER_H__
#define __CONTAINER_H__

class container
{
    private:
        int _id;
        int _dest;

    public:
        //constructor
        container() { _id = 0; _dest = 0; }
        /**
         * @brief Constructs a new container object with the given id. 
         * destination codes are generated randomly.  please note that srand 
         * must be seeded in the `main` function
         * 
         * TODO
         * [ ] randomize id?
         */
        container(int id);

        int getID() { return _id; }
        int getDest() { return _dest; }

        void setID(int id) { _id = id; }
        void setDest(int dest) { dest = _dest; }

        void display(std::ostream& out = std::cout);
};

#endif //__CONTAINER_H__