#include <iostream>
#include <random>

class product
{
    public:
        product();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        int GetQ() { return Q; }
        int SetQ(int val) { Q = val }

        void Display();

    private:
        int id;
        int Q;

}
