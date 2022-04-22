#include <iostream>
#include <random>
#include <ctime>

#include "node.h"

using namespace std;

int main()
{
    default_random_engine gen(time(NULL));
    uniform_int_distribution<int> idist(1, 1000);

    cout << "creating root node with random value" << endl;

    node * root = new node(idist(gen));

    root->display();

    cout << endl;

    cout << "--------------------------" << endl;
    cout << "adding ten random values to tree" << endl;

    for (size_t i = 0; i < 10; i++)
    {
        int next = idist(gen);
        // cout << "adding: " << next << endl;
        root->add(next);
    }

    root->display();

    cout << endl;
    

    return 0;
}
