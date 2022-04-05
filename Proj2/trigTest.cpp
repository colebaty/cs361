#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1);

int main()
{
    cout << "testing trig functions for use in rotation matrix" << endl;
    cout << "-------------------------------------------------" << endl;

    double x;
    double y;

    double deg;

    cout << "enter values <x> <y> <deg>: ";
    cin >> x >> y >> deg;
    cout << endl;

    double rad = deg * PI / 180;

    cout << "x:\t" << x << endl
         << "y:\t" << y << endl
         << "deg:\t" << deg << endl
         << "rad:\t" << rad << endl;

    double newX = (x * cos(rad)) - (y * sin(rad));
    double newY = (x * sin(rad)) + (y * cos(rad));

    abs(newX) < 0.0001 ? newX = 0 
                       : newX = (x * cos(rad)) - (y * sin(rad));
    abs(newY) < 0.0001 ? newY = 0
                       : newY = (x * sin(rad)) + (y * cos(rad));


    cout << "-------------------------------------------------" << endl;
    cout << "newX:\t" << newX << endl
         << "newY:\t" << newY << endl;

    return 0;
}
