#include <iostream>
#include <queue>
#include <random>
#include <ctime>

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

        queue<char> temp = _q;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
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