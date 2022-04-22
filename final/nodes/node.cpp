#include <iostream>
#include <queue>

#include "node.h"

using namespace std;

node::node()
{
    _id = 0;
}

node::node(int id)
{
    _id = id;
}

void node::display()
{
    cout << "id:\t" << _id << endl;
    if(!_q.empty())
    {
        cout << "queue contents: " << endl << "\t";

        char * temp;
        for (int i = 0; i < _q.size(); i++)
        {
            temp = &_q.front();
            cout << *temp << " ";
            _q.pop();
            _q.push(*temp);
        }

        cout << endl;
    }
    else
    {
        cout << "queue is empty" <<  endl;
    }
}

void node::push(char data)
{
    _q.push(data);
}