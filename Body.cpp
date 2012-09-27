/*
 * Body.cpp
 *
 *  Created on: 13 Sep 2012
 *      Author: dhf
 */

#include "Body.h"

Body::Body(): name("Body"), mass(1.0), position(vector<double>(3,0.0)), velocity (vector<double>(3,0.0)) {}

Body::Body(string namestring, double m, vector<double> pos, vector<double> vel)
{
	name = namestring;
	mass = m;
	position = pos;
	velocity = vel;
}

Body::~Body() {}


