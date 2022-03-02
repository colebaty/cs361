#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>

#include "container.h"
#include "shiputils.h"
#include "ship.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));

    cout << "creating vector of containers" << endl;

    vector<container> v;
    int contID = 10000;
    while (v.size() < 10)
    {
        v.push_back(*new container(contID++));
    }

    vector<container>::iterator vit = v.begin();

    cout << "--------------------" << endl;
    int count = 0;
    while (vit != v.end())
    {
        cout << "container " << count++ << endl;;
        vit->display();
        vit = next(vit);
        cout << "--------------------" << endl;
    }

    cout << "sum: " << count << endl;
    
    cout << "--------------------" << endl;
    cout << "creating vector of stacks" << endl;

    vector<stack<container>> contents;
    stack<container> * stptr;

    while (contents.size() < 10)
    {
        stptr = new stack<container>;
        while (stptr->size() < 5)
        {
            stptr->push(*new container(contID++));
        }
        contents.push_back(*stptr);
    }

    assert(contents.size() == 10);
    assert(contents[0].size() == 5);

    int sum = 0;

    vector<stack<container>>::iterator vit2 = contents.begin();
    while (vit2 != contents.end())
    {
        sum += vit2->size();
        vit2 = next(vit2);
    }

    cout << "--------------------" << endl;
    cout << "sum: " << count << endl;
    cout << "--------------------" << endl;
    
    ship ship(1);
    ship.display();
    
    return 0;
}
