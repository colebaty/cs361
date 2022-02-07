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


    //make three stacks
    stack<container> * stackptr1 = new stack<container>;
    stack<container> * stackptr2 = new stack<container>;
    stack<container> * stackptr3 = new stack<container>;

    //make three containers
    for (int i = 0; i < 3; i++)
    {
        //make new container
        contptr = new container(contID++);
        contCount++;
        //put container in stack1
        stackptr1->push(*contptr);
    }
    assert(stackptr1->size() == 3);

    //make three more containers
    for (int i = 0; i < 3; i++)
    {
        //make new container
        contptr = new container(contID++);
        contCount++;
        //put container in stack2
        stackptr2->push(*contptr);
    }
    assert(stackptr2->size() == 3);

    //make three more containers
    for (int i = 0; i < 3; i++)
    {
        //make new container
        contptr = new container(contID++);
        contCount++;
        //put container in stack3
        stackptr3->push(*contptr);
    }
    assert(stackptr3->size() == 3);

    //put stacks in column vector
    vector<stack<container>> * colptr = new vector<stack<container>>;
    colptr->push_back(*stackptr1);
    colptr->push_back(*stackptr2);
    colptr->push_back(*stackptr3);

    std::cout << contCount << " containers generated" << endl;
    std::cout << "------------------------" << endl;

    // cout << "get container at top of stack (1 1)" << endl;
    // cargo[1][1].top().display();

    return 0;
}