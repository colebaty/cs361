#include <iostream>
#include <random>
#include <ctime>
#include <cctype>
#include <vector>

#include "node.h"

using namespace std;

enum menuOptions:char {_ENTER = 'a', _GEN = 'b', _SEARCH = 'c', 
                       _DISPLAY = 'd', _ERASE = 'e', _EXIT = 'x'};

menuOptions menu();
void getNandM(int& n, int& m);
void generate(vector<node>& v, const int& n, const int& m);
void display(vector<node>& v);
void getNodesWithChar(vector<node>& v);
void displayNode(vector<node>& v);
void erase(vector<node>* v);

int main()
{

    vector<node> * v = new vector<node>;

    int n, m;
    menuOptions choice;
    do
    {
        choice = menu();
        switch (choice)
        {
        case _ENTER:
            getNandM(n, m);
            break;
        
        case _GEN:
            generate(*v, n, m);
            display(*v);
            break;

        case _SEARCH:
            getNodesWithChar(*v);
            break;

        case _DISPLAY:
            displayNode(*v);
            break;

        case _ERASE:
            erase(v);
            break;

        case _EXIT:
            break;

        default:
            cout << "invalid selection; try again" << endl;
            break;
        }
    }
    while (choice != _EXIT);

    return 0;
}

menuOptions menu()
{
    cout << "\t\tMenu" << endl
         << "a) Enter a number of nodes N, and the number of chars M" << endl
         << "b) Generate the N nodes and M characters." << endl
         << "c) search for all nodes with a certain character" << endl
         << "d) search for all characters inside a node N." << endl
         << "e) erase the current data collection" << endl
         << "x) exit." << endl;
    
    char choice;
    cout << "Choice: ";
    cin >> choice;

    return (menuOptions) tolower(choice);
}

void getNandM(int& n, int &m)
{
    cout << "enter N and M: ";
    cin >> n >> m;
    cout << endl;
}

void generate(vector<node>& v, const int& n, const int& m)
{
    default_random_engine gen(time(NULL));
    uniform_int_distribution<int> ldist(_A, _Z);//letter distribution
    /*
     * during testing, discovered that the first value is always the same for
     * a default random engine seeded the way it is above. this call is just to
     * discard that first value
     */
    ldist(gen);

    node * nptr;
    int nodeID = 1;
    for (int i = 0; i < n; i++)
    {
        nptr = new node(nodeID++);
        v.push_back(*nptr);
    }

    for (int i = 0; i < m; i++)
    {
        v[i % n].push(ldist(gen));
    }
    

}

void display(vector<node>& v)
{
    for (auto it : v)
    {
        it.display();
        cout << endl;
    }
}

void getNodesWithChar(vector<node>& v)
{
    char target;
    cout << "char to search for: ";
    cin >> target;

    vector<node> results;

    for(vector<node>::iterator vit = v.begin(); vit != v.end(); vit++)
    {
        if (vit->search(target)) results.push_back(*vit);
    }

    if (!results.empty())
    {
        for (auto n : results)
        {
            n.display();
        }
    }
    else
    {
        cout << "not found" << endl;
    }

}

void displayNode(vector<node>& v)
{
    cout << "index of node to display [1, N]: ";
    int target;
    cin >> target;
    while (target < 0 || target > v.size())
    {
        cout << "selection out of bounds" << endl;
        cout << "index of node to display [0, N]: ";
        cin >> target;
        cout << endl;
    }

    for (vector<node>::iterator vit = v.begin(); vit != v.end(); vit++)
    {
        if (vit->getID() == target)
        {
            vit->display();
            break;
        }
    }
    
}

void erase(vector<node>* v)
{
    delete v;
    v = new vector<node>;
}