#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>

#include "container.h"
#include "ship.h"

using namespace std;

container getNext(vector<vector<stack<container>>>& cargo);
bool hasNext(vector<vector<stack<container>>>& cargo);

int main()
{
    //seed srand
    srand(time(NULL));

    container * contp;
    stack<container> * column;
    vector<stack<container>> * layer;
    vector<vector<stack<container>>> cargo;

    int contID = 10000;
    for (int z = 0; z < 5; z++)
    {
        layer = new vector<stack<container>>;
            for (int y = 0; y < 5; y++)
            {
                column = new stack<container>;
                    for (int x = 0; x < 5; x++)
                    {
                        contp = new container(++contID);
                        column->push(*contp);
                    }
                layer->push_back(*column); 
            }
        cargo.push_back(*layer);
    }

    cout << "-----------------------" << endl;
    while (hasNext(cargo))
    {
        *contp = getNext(cargo);
        contp->display();
        cout << "-----------------------" << endl;
    }

    return 0;
}

container getNext(vector<vector<stack<container>>>& cargo)
{
    container * cont;
    cont = &cargo[0][0].top();
    cargo[0][0].pop();

    return *cont;
}

bool hasNext(vector<vector<stack<container>>>& cargo)
{
    if (cargo[0][0].empty())
    {
        cargo[0].erase(cargo[0].begin());
    }

    if (cargo[0].empty())
    {
        cargo.erase(cargo.begin());
    }

    return !cargo.empty() && !cargo[0].empty() && !cargo[0][0].empty();
}