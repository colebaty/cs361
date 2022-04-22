#include <iostream>
#include <map>
#include <utility>

#include "node.h"

using namespace std;

node::node()
{
    _val = 0;
    initialize();
}

node::node(int val)
{
    _val = val;
    initialize();
}

void node::initialize()
{
    _Q1 = nullptr;
    _Q2 = nullptr;
    _Q3 = nullptr;
    _Q4 = nullptr;
}

void node::add(int data)
{
    if ((data / _val) < (_val * .50))
    {
        if (_Q1 != NULL)
        {
            _Q1->add(data);
        }
        else
        {
            _Q1 = new node(data);
        }
    }
    else if (data <= _val - 1)
    {
        if (_Q2 != NULL)
        {
            _Q2->add(data);
        }
        else
        {
            _Q2 = new node(data);
        }
    }
    else if (data >= _val + 1 && data < 1.5 * _val)
    {
        if (_Q3 != NULL)
        {
            _Q3->add(data);
        }
        else
        {
            _Q3 = new node(data);
        }
    }
    else
    {
        if (_Q4 != NULL)
        {
            _Q4->add(data);
        }
        else
        {
            _Q4 = new node(data);
        }
    }
}