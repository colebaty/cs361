#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <map>
#include <vector>
#include <string>

#include "module.h"
#include "utilities.h"

using namespace std;

int main()
{
    cout << "creating 4 modules" << endl;
    module * mptr;
    vector<module> modlist;

    for (int i = 0; i < 4; i++)
    {
        mptr = new module(i+1);
        modlist.push_back(*mptr);
    }

    for (int i = 0; i < modlist.size(); i++)
    {
        modlist[i].display();
    }

    cout << "--------------------------" << endl;
    
    
    for (int i = 0; i < modlist.size(); i++)
    {
        modlist[i].move((double) i * HALLWAY_LEN, (double) i * HALLWAY_WID);
    }

    vector<module>::iterator mit = modlist.begin();
    while (mit != modlist.end())
    {
        mit->display();
        mit++;
    }
    
    cout << "--------------------------" << endl;

    ofstream * fout;
    mit = modlist.begin();
    while (mit != modlist.end())
    {
        string filename = "m" + to_string(mit->getID()) + DATA_FILE_EXT;
        cout << "writing coords of module " << mit->getID() 
             << " to filename " << filename << "...";
        fout = new ofstream(filename);
        mit->writeDataFile(*fout);
        fout->close();
        cout << "done" << endl;
        mit++;
    }

    cout << "--------------------------" << endl;
    cout << "writing command file to dataFileTest2" << COMMAND_FILE_EXT << "...";
    fout = new ofstream("datFileTest2" + COMMAND_FILE_EXT);

    *fout << "set xlabel \"stuff\"" << endl
          << "set ylabel \"other stuff\"" << endl
          << "set xrange [0:40]" << endl
          << "set yrange [0:40]" << endl
          << "set terminal png" << endl
          << "set output \"output2.png\"" << endl
          << "plot 'm1.dat' with lines linecolor rgb \"#336699\", \\" << endl
          << "\t'm2.dat' with lines linecolor rgb \"#669933\", \\" << endl
          << "\t'm3.dat' with lines linecolor rgb \"#993366\", \\" << endl
          << "\t'm4.dat' with lines linecolor rgb \"#369369\"," << endl
          << "pause -1" << endl;

    fout->close();
    cout << "done" << endl;

    system("gnuplot datFileTest2.gpc");
    //housekeeping
    delete fout;

    return 0;
}