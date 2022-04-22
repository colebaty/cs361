#include <iostream>
#include <random>
#include <ctime>

#include "node.h"

using namespace std;

int main()
{
    default_random_engine gen(time(NULL));
    uniform_int_distribution<int> idist(1, 1000);

    cout << "how many nodes to add to tree (N)? ";

    int ans;
    cin >> ans;
    cout << endl;

    //generating root node
    node * root = new node(idist(gen));

    //start at one because we've already added root
    for (size_t i = 1; i < ans; i++)
    {
        int next = idist(gen);
        root->add(next);
    }

    cout << "--------------------------" << endl;

    root->display();

    cout << endl;
    

    return 0;
}
