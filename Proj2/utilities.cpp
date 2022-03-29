#include <fstream>
#include <iostream>
#include <utility>
#include <cstdio>   //for printf
#include <string>

#include "utilities.h"
#include "menuOptions.h"
#include "module.h"

using namespace std;

void addMod(station& station)
{
    types choice = displayAddModMenu();

    station.add(choice);
}