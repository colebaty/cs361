#include <iostream>
#include <fstream>

using namespace std;

void first(ofstream& out);
void second(ofstream& out);

int main()
{
    cout << "testing whether state is preserved when fstream" << endl
         << "object is passed as param through multiple functions" << endl;

    cout << "------------------------------------------" << endl;
    cout << "creating new ofstream object to write to 'out.dat'" << endl;

    ofstream * fout = new ofstream("out.dat");
    *fout << "from main" << endl;
    first(*fout);
    fout->close();

    //housekeeping
    delete fout;

    return 0;
}

void first(ofstream& out)
{
    out << "\tfrom first" << endl;
    second(out);
}
void second(ofstream& out)
{
    out << "\t\tfrom second" << endl;
}