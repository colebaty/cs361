#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>

#include "module.h"
#include "utilities.h"

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

    //data out
    ofstream dout("m1.dat");
    m1.writeDataFile(dout);
    dout.close();
    
    //boilerplate
    //draw commands out
    ofstream drout("commands.dat");
    drout << "set xlabel \"stuff\"" << endl
        << "set ylabel \"other stuff\"" << endl
        << "set xrange [0:40]" << endl
        << "set yrange [0:40]" << endl
        << "set terminal png" << endl
        << "set output \"output.png\"" << endl
        << "plot 'm1.dat' with lines linecolor rgb \"#9ACD32\"" << endl
        << "pause -1" << endl;

    drout.close();

    cout << "drawing plot for m1...";
    system("gnuplot commands.dat");
    cout << "done" << endl;

    cout << "----------------------" << endl;
    cout << "creating new default module m0" << endl;

    module m0;
    m0.display();

    cout << "----------------------" << endl;
    cout << "creating datafile for m0" << endl;

    //data out
    ofstream ddout("m0.dat");
    m0.writeDataFile(ddout);
    ddout.close();

    ofstream ddrout("commands2.dat");
    ddrout << "set xlabel \"stuff\"" << endl
        << "set ylabel \"other stuff\"" << endl
        << "set xrange [0:40]" << endl
        << "set yrange [0:40]" << endl
        << "set terminal png" << endl
        << "set output \"output2.png\"" << endl
        << "plot 'm0.dat' with lines linecolor rgb \"#336699\"" << endl
        << "pause -1" << endl;

    ddrout.close();

    cout << "drawing plot for m1...";
    system("gnuplot commands2.dat");
    cout << "done" << endl;

    return 0;
}