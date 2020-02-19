// Developed by Danylo Vanin, SE-2, 3 Group
// on 21.01.2020
// Version 1.0

//#define NDEBUG

#include "Point.h"

int Point::freeID = 0;

//Default constructor
Point::Point(const double x, const double y): _x(x),_y(y),pointID(freeID++) {
	#ifndef NDEBUG
	cout << "CREATED Point (" << _x << ',' << _y << ") with ID: " << pointID << endl;
	#endif
	return;
}

//Copy constructor
Point::Point(const Point& p): _x(p._x),_y(p._y),pointID(freeID++) {
	#ifndef NDEBUG
		cout << "CREATED Point ("<< _x << ',' << _y << ") with ID: " << pointID << endl;
	#endif
	return;
}

//Destructor
Point::~Point() {
	#ifndef NDEBUG
		cout << "DELETED Point (" << _x << ',' << _y << ") with ID: " << pointID << endl;
	#endif
	return;
}

Point& Point::operator=(const Point& p) {
	if (this == &p)	return *this;
	_x = p._x;
	_y = p._y;
	return *this;
}

ostream& operator<<(ostream& os, const Point& u) {
	os << '(' << u.x() << ',' << u.y() << ')';
	return os;
};

const Point operator+ (const Point& u, const Point& v) {
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& operator+=(Point& u, const Point& v) {
	u.x() += v.x();
	u.y() += v.y();
	return u;
}

bool operator==(const Point& u, const Point& v) {
	return (u.x() == v.x() && u.y() == v.y());
}

bool operator!=(const Point& u, const Point& v) {
	return !(u == v);
}