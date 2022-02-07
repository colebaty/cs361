#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>
#include <cstdlib>

#include "container.h"

using namespace std;

int main()
{
    int id = 3;
    int contID = id * 10000;
    int contCount = 0;

    container * contptr;
    stack<container> * column;
    vector<stack<container>> * layer;
    vector<vector<stack<container>>> cargo;

    for (int row = 0; row < 3; row++)
    {
        layer = new vector<stack<container>>;
        for (int col = 0; col < 3; col++)
        {
            column = new stack<container>;
            for (int i = 0; i < 3; i++)
            {
                contptr = new container(contID++);
                contCount++;
                column->push(*contptr);
            }
            layer->push_back(*column);
        }
        cargo.push_back(*layer);
    }

    std::cout << contCount << " containers generated" << endl;
    std::cout << "------------------------" << endl;

    // cout << "get container at top of stack (1 1)" << endl;
    // cargo[1][1].top().display();

    return 0;
}