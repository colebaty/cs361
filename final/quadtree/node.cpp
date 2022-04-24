#include <iostream>

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
    _Q1 = NULL;
    _Q2 = NULL;
    _Q3 = NULL;
    _Q4 = NULL;
}

void node::add(int data)
{
    if (data < (_val / 2))
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
    else if ((_val / 2) <= data && data < _val)
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
    else if (_val < data && data < (_val * 3 / 2))
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
    else if ((_val * 3 / 2) <= data)
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

void node::display()
{
    if (_Q1 != NULL)
    {
        _Q1->display();
    }
    if (_Q2 != NULL)
    {
        _Q2->display();
    }
    
    //display this node
    cout << "Node: " << _val << " ";
    cout << "Q1->";
    _Q1 != NULL ? cout << _Q1->_val << " "
                : cout << "NULL ";

    cout << "Q2->";
    _Q2 != NULL ? cout << _Q2->_val << " "
                : cout << "NULL ";

    cout << "Q3->";
    _Q3 != NULL ? cout << _Q3->_val << " "
                : cout << "NULL ";

    cout << "Q4->";
    _Q4 != NULL ? cout << _Q4->_val << " "
                : cout << "NULL ";

    cout << endl;
    //end display this node

    if (_Q3 != NULL)
    {
        _Q3->display();
    }
    if (_Q4 != NULL)
    {
        _Q4->display();
    }
    
}