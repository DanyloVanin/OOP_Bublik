// Developed by Danylo Vanin, SE-2, 3 Group
// on 25.01.2020
// Version 1.0
#include "Segment.h"
#define NDEBUG
int Triangle::Segment::_freeID = 0;

//Constructor with points
Triangle::Segment::Segment(const Point& start,const Point& end): _a(start),_b(end),_myId(_freeID++) {
    #ifndef NDEBUG
        cout << "CREATED Segment: " << _a << " -> " << _b << " ID: " << _myId << endl;
    #endif
    return;
}

//Destructor
Triangle::Segment::~Segment() {
    #ifndef NDEBUG
        cout << "DELETED Segment: " << _a << " -> " << _b << " ID: " << _myId << endl;
    #endif
    return;
}

//copy
Triangle::Segment::Segment(const Triangle::Segment& s) :
    _a(s._a), _b(s._b), _myId(++_freeID)
{
#ifndef NDEBUG
    cout << "COPIED Segment: " << _a << " -> " << _b << " ID: " << _myId << endl;
#endif
    return;
}

ostream& operator<<(ostream& os, const Triangle::Segment& s) {
    os << s.start() << "->" << s.end();
    return os;
}

double Triangle::Segment::length() const {
    return _a.distanceTo(_b);
}

double Triangle::Segment::distance(const Point& p) const {
    double a = _a.distanceTo(p);
    double b = _b.distanceTo(p);
    double c = length();
    //finding altitude/distance using Heron's formula
    double hper = (a + b + c) / 2;
    return 2 * sqrt(hper * (hper - a) * (hper - b) * (hper - c)) / c;
}