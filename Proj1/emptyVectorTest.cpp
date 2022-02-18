#include <iostream>
#include <vector>
#include <stack>

#include "container.h"

using namespace std;

int main() {

    cout << "creating container" << endl;

    container * cont = new container(1);
    cont->display();

    cout << "--------------------" << endl;

    cout << "creating stack; pushing container to stack" << endl;

    stack<container> s;
    s.push(*cont);
    cont = nullptr;

    cout << "size of stack: " << s.size() << endl;
    cout << "s.top().display():" << endl;
    s.top().display();

    cout << "--------------------" << endl;

    cout << "popping container from stack" << endl;

    cont = &s.top();
    s.pop();
    cont->display();
    cout << "size of stack: " << s.size() << endl;

    cout << "--------------------" << endl;

    cout << "adding empty stack to vector" << endl;
    vector<stack<container>> v;
    v.push_back(s);
    cout << "size of vector: " << v.size() << endl;
    cout << "size of stack: " << v.front().size() << endl;
    cont->display();

    cout << "--------------------" << endl;

    cout << "erasing empty stack from vector" << endl;
    v.erase(v.begin());
    cout << "size of vector: " << v.size() << endl;
    cout << "size of stack: " << v.front().size() << endl;
    cont->display();

    cout << "--------------------" << endl;
    cout << "pushing container back on stack" << endl;
    s.push(*cont);
    cout << "pushing stack back into vector" << endl;
    v.push_back(s);
    cout << "size of vector: " << v.size() << endl;
    cout << "size of stack: " << s.size() << endl;
    v.front().top().display();
    cont = nullptr;
    cout << "--------------------" << endl;

    /**
     * @brief money shot. from c++ documentation:
     * 
     * 
     */
    cout << "popping container from stack inside of vector" << endl;
    cont = new container(v.front().top());
    v.front().pop();
    cout << "v.front().size(): " << v.front().size() << endl;
    cout << "v.size(): " << v.size() << endl;
    cont->display();
    cout << "--------------------" << endl;

    cout << "popping empty stack from vector" << endl;
    v.pop_back();
    cout << "v.size(): " << v.size() << endl;
    cont->display();
    cout << "--------------------" << endl;


    return 0;
}