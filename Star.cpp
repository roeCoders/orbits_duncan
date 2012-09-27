/*
 * Star.cpp
 *
 *  Created on: 13 Sep 2012
 *      Author: dhf
 */

#include "Star.h"

Star::Star(): Body(){}
Star::Star(string namestring,double m,vector<double>pos, vector<double>vel):Body(namestring,m,pos,vel){}
Star::~Star() {}



