#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <iostream>
#include <utility>
#include <cstdio>   //for printf
#include <map>

#include "station.h"
#include "module.h"

using namespace std;

const string DATA_FILE_EXT = ".dat";
const string COMMAND_FILE_EXT = ".gpc"; //gnuplot command
const string IMAGE_FILE_EXT = ".png";
const string CONF_FILE_EXT = ".conf";

void writeData(module mod);

/**
 * @brief 
 * 
 * @param src 
 * @param srcWall 
 * @param dst 
 * @param dstWall 
 */
void connect(dirs srcWall, module& dst, dirs dstWall);

/**
 * @brief add a module to the station
 * 
 * @param station 
 */
void addMod(station& station);

#endif //__UTILITIES_H__