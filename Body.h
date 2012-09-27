/*
 * Body.h
 *
 *  Created on: Sep 13, 2012
 *      Author: dhf
 */


using namespace std;

#ifndef BODY_H_
#define BODY_H_

#include <string>
#include <vector>



class Body {
public:
	Body();
	Body(string namestring, double m, vector<double> pos, vector<double> vel);
	virtual ~Body();

	// TODO - Create own vector class for portability

	// accessor methods
	string getName() { return name; }
	double getMass(){ return mass; }
	vector<double>getPosition() { return position; }
	vector<double>getVelocity() { return velocity;}

	// Variable defining methods
	void setName(string newname) { name= newname; }
	void setMass(double m) { mass = m; }
	void setPosition(vector<double> pos) { position = pos; }
	void setVelocity(vector<double> vel) { velocity = vel; }

	// Standard cloning method
	virtual Body* Clone() { return new Body(*this); }

protected:
	string name;
	double mass;
	vector<double> position;
	vector<double> velocity;

};


#endif /* BODY_H_ */
