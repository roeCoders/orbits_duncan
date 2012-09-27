/*
 * Planet.h
 *
 *  Created on: Sep 13, 2012
 *      Author: dhf
 */

#include <iostream>
#include "Body.h"
#include "Star.h"
#include "math.h"

using namespace std;

#ifndef PLANET_H_
#define PLANET_H_

class Planet: public Body {
public:

	Planet();
	Planet(string namestring, double m, vector<double> pos, vector<double> vel);
	virtual ~Planet();

	/* Accessors */

	double getHostMass() {return hostMass;}
	void setHostMass(double m) {hostMass = m;}

	vector<double> getRelativePosition(){ return relativePosition;}
	void setRelativePosition(vector<double> pos){relativePosition=pos;}

	vector<double> getRelativeVelocity(){ return relativeVelocity;}
	void setRelativeVelocity(vector<double> vel){relativeVelocity=vel;}

	double getSemiMajorAxis(){ return semiMajorAxis;}
	void setSemiMajorAxis(double a){semiMajorAxis=a;}

	vector<double> getEccVector(){return eccentricityVector;}
	void setEccVector(vector<double> eccvec){eccentricityVector = eccvec;}

	double getEcc()
	{
		eccentricity = sqrt(eccentricityVector[1]*eccentricityVector[1] + eccentricityVector[2]*eccentricityVector[2]+eccentricityVector[3]*eccentricityVector[3]);
		return eccentricity;
	}

	void setEcc(double e){eccentricity = e;}

	vector<double> getAngularMomentum(){return angularMomentum;}
	void setAngularMomentum(vector<double> L){angularMomentum = L;}

	double getMagAngularMomentum(){return magAngularMomentum;}
	void setMagAngularMomentum(double L){magAngularMomentum = L;}

	vector<double> getRCOM() {return rCoM;}
	void setRCOM(vector<double> r) { rCoM = r; }

	vector<double> getVCOM() {return vCoM;}
	void setVCOM(vector<double> v) { vCoM = v; }

	/* Calculation Methods */

	void calcRelativeVectors();

	void calcAngularMomentum();

	void calcEccentricity(double G);

	void calculateOrbit(double G);

	// Standard cloning method
	virtual Planet* Clone() { return new Planet(*this); }

protected:
	string name;
	double mass;
	vector<double> position;
	vector<double> velocity;

	vector<double> relativePosition;
	vector<double> relativeVelocity;

	vector<double> rCoM;
	vector<double> vCoM;
	double hostMass;

	double semiMajorAxis;

	vector<double> eccentricityVector;
	double eccentricity;

	vector<double> angularMomentum;
	double magAngularMomentum;

	/* Not yet used
	double trueAnomaly;
	double meanAnomaly;
	double inc;
	double longAscendingNode; */

};

#endif /* PLANET_H */

