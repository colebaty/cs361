#include <iostream>
#include <vector>
#include <stack>

#include "container.h"

using namespace std;

int main()
{
    int id = 3;
    container * contptr;
    int contID = id * 10000;

    stack<container> * stackptr;
    vector<stack<container>> * colptr;
    vector<vector<stack<container>>> * rowptr;

    int contCount = 0;
    rowptr = new vector<vector<stack<container>>>;
    for (int row = 0; row < 5; row++)
    {
        rowptr = new vector<vector<stack<container>>>;
        colptr = new vector<stack<container>>;
        for (int col = 0; col < 5; col++)
        {
            stackptr = new stack<container>;
            for (int i = 0; i < 3; i++)
            {
                contptr = new container(contID++);
                stackptr->push(*contptr);
                contCount++;
            }
            colptr->push_back(*stackptr);
            
        }
        rowptr->push_back(*colptr);
    }

    cout << contCount << "containers generated" << endl;
    
    return 0;
}