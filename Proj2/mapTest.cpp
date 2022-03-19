#include <map>
#include <utility>
#include <iostream>
#include <cassert>

using namespace std;

/**
 * @brief unique <map> keys for module corners
 * 
 */
enum corners:char {_BL, _BR, _TR, _TL};

const int HALLWAY_LEN = 5;
const int HALLWAY_WID = 5;

void printMap(map<char, pair<int, int>>& _map);

int main()
{
    cout << "testing pair creation" << endl;
    pair<int, int> bl = make_pair(0, 0);
    cout << "bl: " << bl.first << " " << bl.second << endl;

    cout << "--------------------" << endl;
    cout << "adding bl to map" << endl;
    map<char, pair<int, int>> corners;
    corners.insert(make_pair(_BL, bl));

    cout << "printing from map" << endl;
    printMap(corners);
    cout << "--------------------" << endl;
    cout << "filling rest of corners" << endl;
    pair<int, int> br = make_pair(HALLWAY_LEN, 0);
    pair<int, int> tr = make_pair(HALLWAY_LEN, HALLWAY_WID);
    pair<int, int> tl = make_pair(0, HALLWAY_WID);

    corners.insert(make_pair(_BR, br));
    corners.insert(make_pair(_TR, tr));
    corners.insert(make_pair(_TL, tl));
    printMap(corners);

    return 0;
}

void printMap(map<char, pair<int, int>>& _map)
{
    map<char, pair<int, int>>::iterator mit = _map.begin();

    while (mit != _map.end())
    {
        //proof that enum types work
        assert(mit->first == _BL || mit->first == _BR || mit->first == _TR || mit->first == _TL);

        cout << mit->first << " " << mit->second.first << " " << mit->second.second << endl;
        mit++;
    }
}