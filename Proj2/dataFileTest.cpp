#include <iostream>
#include <cstdio>
#include <fstream>

#include "module.h"

using namespace std;

int main()
{
    cout << "creating default module" << endl;
    module m1;
    m1.display();

    cout << "----------------------" << endl;

    cout << "moving dx = 5, dy = 2" << endl;
    m1.move(5.0, 2.0);
    m1.display();
    
    cout << "----------------------" << endl;
    cout << "creating datafile for m1" << endl;

    ofstream out("m1.dat");
    m1.writeDataFile(out);
    
    //boilerplate
    out << "set xlabel \"stuff\"" << endl
        << "set ylabel \"other stuff\"" << endl
        << "set xrange [-5:25]" << endl
        << "set yrange [-5:25]" << endl
        << "set terminal png" << endl
        << "set output \"output.png\"" << endl
        << "plot 'm1.dat' with rectangles leinecolor rgb \"#9ACD32\" fill solid noborder" << endl
        << "pause -1" << endl;

    out.close();

    return 0;
}