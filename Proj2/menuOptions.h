#ifndef __MENUOPTIONS_H__
#define __MENUOPTIONS_H__

#include "module.h"

using namespace std;

enum actions:char {_ADD = 'a', _MOVE = 'b', _SAVE = 'c', _DRAW = 'd', 
                   _LOAD = 'e', _VERIFY = 'f', _EXIT = 'g', _CONTINUE};

void displayHeader();

char displayMenu();
types displayAddModMenu();

#endif //__MENUOPTIONS_H__