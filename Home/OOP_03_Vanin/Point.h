#pragma once
// Developed by Danylo Vanin, SE-2, 3 Group
// on 25.01.2020
// Version 2.0 (added distanceTo())

#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
using namespace std;

//*******************************************
//Every point posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a point created or resp. deleted
// Developed by Danylo Vanin
// on 25.01.2020
// Version 2.0 (added distanceTo())
//*******************************************

class Point
{
private:
	static int freeID;
	const int pointID;
	double _x;
	double _y;
public:
	Point(double x = 0, double y = 0);
	Point(const Point&);
	~Point(); 
	Point& operator=(const Point&);

	//selectors and modifiers
	double& x() { return _x; };
	double& y() { return _y; };
	//selectors
	const double& x()const { return _x; };
	const double& y()const { return _y; };
	//selectors
	const int getID() const {return pointID;};
	static int amount() { return freeID; }

	//methods
	const double distanceTo(const Point&) const;
};

//operators
ostream& operator<<(ostream&, const Point&);
const Point operator+ (const Point& u, const Point& v);
Point& operator+=(Point&, const Point&);
bool operator==(const Point& u, const Point& v);
bool operator!=(const Point& u, const Point& v);

#endif