/*
 * main.cpp
 *
 *  Created on: 13 Sep 2012
 *      Author: dhf
 *
 *      A program to create Star and Planet objects, and calculate orbital elements
 */

#include <iostream>
#include "Star.h"
#include "Planet.h"
#include "Constants.h"

using namespace std;

int main()
{
	Star myStar;
	Planet myPlanet;

	//Body * pmyStar = &myStar;
	//Body * pmyPlanet = &myPlanet;

	double starmass;
	string starname = "Sun";
	vector<double> starpos(3,0.0);
	vector<double> starvel(3,0.0);

	double planetmass;
	string planetname = "Earth";
	vector<double> planetpos(3,0.0);
	vector<double> planetvel(3,0.0);

	cout << "Defining Stellar Properties " << endl;
	starmass = 1.0;

	starpos[0] = 0.0;
	starpos[1] = 0.0;
	starpos[2] = 0.0;

	starvel[0] = 0.0;
	starvel[1] = 0.0;
	starvel[2] = 0.0;

	cout << "Defining Planetary Properties " << endl;
	planetmass = 1.0e-6;

	planetpos[0] = 0.0;
	planetpos[1] = 1.0;
	planetpos[2] = 0.0;

	planetvel[0] = -1.0;
	planetvel[1] = 0.0;
	planetvel[2] = 0.0;

	// Create star and planet objects

	cout << "Creating Objects "<< endl;
	myStar.setName(starname);
	myStar.setPosition(starpos);
	myStar.setVelocity(starvel);


	myPlanet.setName(planetname);
	myPlanet.setPosition(planetpos);
	myPlanet.setVelocity(planetvel);

	cout << "Setting Host Star " << endl;
	// Give Planet its Host Object's position and velocity

	myPlanet.setRCOM(myStar.getPosition());
	myPlanet.setVCOM(myStar.getVelocity());

	cout <<"Calculating Planet Orbit" << endl;
	// Calculate orbital elements
	myPlanet.calculateOrbit(Gmau);


	// Display Planet's orbital elements

	cout << "Planet's Position " << planetpos[0] << endl;
	cout << "Planet's Velocity " << planetvel[1] << endl;
	cout << "Semi Major Axis " << myPlanet.getSemiMajorAxis() << endl;

	return 0;
}

