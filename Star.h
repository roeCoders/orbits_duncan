/*
 * Star.h
 *
 *  Created on: Sep 13, 2012
 *      Author: dhf
 */

#include "Body.h"

using namespace std;

#ifndef STAR_H_
#define STAR_H_


//#include "Planet.h"

class Star: public Body {
public:

	Star();
	Star(string namestring, double m, vector<double> pos, vector<double> vel);
	virtual ~Star();

	// Standard cloning method
	virtual Star* Clone() { return new Star(*this); }

	//void addPlanet(class Planet *newplanet);

protected:
	string name;
	double mass;
	vector<double> position;
	vector<double> velocity;
	//vector<class Planet> planets;


};

#endif /* STAR_H */

