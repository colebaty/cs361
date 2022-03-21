#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <iostream>
#include <cstdio>   //for printf

#include "module.h"

using namespace std;

const string DATA_FILE_EXT = ".dat";
const string COMMAND_FILE_EXT = ".gpc"; //gnuplot command
const string IMAGE_FILE_EXT = ".png";

void writeData(module mod);

#endif //__UTILITIES_H__