/*
 * Planet.cpp
 *
 *  Created on: 13 Sep 2012
 *      Author: dhf
 */

#include <iostream>
#include "Planet.h"

Planet::Planet(): Body(), semiMajorAxis(0.0), eccentricity(0.0) {}
Planet::Planet(string namestring,double m,vector<double>pos, vector<double>vel):Body(namestring,m,pos,vel), semiMajorAxis(0.0), eccentricity(0.0){}
Planet::~Planet() {}

/* Calculation Methods */

	void Planet::calcRelativeVectors()
	{
		int i;

		vector<double> pos = getPosition();
		vector<double> vel = getVelocity();

		vector<double> rcom = getRCOM();
		vector<double> vcom = getVCOM();

		vector <double> relpos(3,0.0);
		vector <double> relvel(3,0.0);

		for (i=0; i<3; i++){
			relpos[i] = pos[i]-rcom[i];
			relvel[i] = vel[i]-vcom[i];
		}

		setRelativePosition(relpos);
		setRelativeVelocity(relvel);
	}

	void Planet::calcAngularMomentum()
	{

		vector<double> angMom(3,0.0);
		double magangMom;

		vector<double> relpos = getRelativePosition();
		vector<double>relvel = getRelativeVelocity();

		// Calculates orbital angular momentum, given relative positions and velocities
		angMom[0] = relpos[1]*relvel[2] - relpos[2]*relvel[1];
		angMom[1] = relpos[2]*relvel[0] - relpos[0]*relvel[2];
		angMom[2] = relpos[0]*relvel[1] - relpos[1]*relvel[0];

		magangMom = sqrt(angMom[0]*angMom[0]+angMom[1]*angMom[1]+angMom[2]*angMom[2]);
		setAngularMomentum(angMom);
		setMagAngularMomentum(magangMom);
	}

	void Planet::calcEccentricity(double G)
	{
		int i;
		double magvel, magpos,magecc,totmass;

		vector<double> ecc(3,0.0);

		vector<double> relpos = getRelativePosition();
		vector<double> relvel = getRelativeVelocity();

		vector<double> angmom = getAngularMomentum();

		magpos = 0.0;
		magvel = 0.0;

		for (i=0; i<3; i++)
		{
			magpos = magpos + relpos[i]*relpos[i];
			magvel = magvel + relvel[i]*relvel[i];
		}

		magpos = sqrt(magpos);
		magvel = sqrt(magvel);

		totmass = getHostMass() + getMass();

		// TODO - add exception for zero value of magpos

		ecc[0] = (relvel[1]*angmom[2] - relvel[2]*angmom[1])/(G*totmass)-relpos[0]/magpos;
		ecc[1] = (relvel[2]*angmom[0] - relvel[0]*angmom[2])/(G*totmass)-relpos[1]/magpos;
		ecc[2] = (relvel[0]*angmom[1] - relvel[1]*angmom[0])/(G*totmass)-relpos[2]/magpos;

		magecc = sqrt(ecc[0]*ecc[0]+ ecc[1]*ecc[1]+ecc[2]*ecc[2]);

		setEccVector(ecc);
		setEcc(magecc);

	}

	void Planet::calculateOrbit(double G)
	{

		vector<double> relpos(3,0.0);
		vector<double> relvel(3,0.0);
		double magangmom,ecc, semimaj;

		double totmass = getHostMass() + getMass();

		// Get relative position and velocity of planet from host star

		cout << "Calculating Relative Position/Velocity"<<endl;

		calcRelativeVectors();

		cout << "Calculating Angular Momentum" << endl;
		// Use these to calculate specific orbital angular momentum (h) via cross-product
		calcAngularMomentum();

		cout << "Calculating Eccentricity" <<endl;
		// Calculate eccentricity vector (e)
		calcEccentricity(G);

		cout << "Calculating Semimajor Axis" <<endl;
		// Calculate semi-major axis from |h| and |e|

		magangmom = getMagAngularMomentum();
		ecc = getEcc();

		semimaj = magangmom*magangmom/(G*(totmass)*(1-ecc*ecc));

		setSemiMajorAxis(semimaj);
		// Calculate true anomaly using eccentricity and position vectors (note cases for e=0, etc)

	}



