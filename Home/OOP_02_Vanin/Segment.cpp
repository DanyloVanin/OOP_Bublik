// Developed by Danylo Vanin, SE-2, 3 Group
// on 25.01.2020
// Version 1.0

//*******************************************
//Every segment posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a segment created or resp. deleted
//  Developed by Danylo Vanin
//  at 25.01.20
//  Version 1.0
//*******************************************

#include "Segment.h"
//#define NDEBUG

int Segment::_freeID = 0;

//Default constructor (0,0)->(0,0) or with coordinates
Segment::Segment(const double x1, const double y1, 
    const double x2, const double y2): _a(x1,y1),_b(x2,y2),_myId(_freeID++) {
    #ifndef NDEBUG
        cout << "CREATED Segment: " << _a << " -> " << _b << " ID: "<<_myId<<endl;
    #endif
    return;
}

//Constructor with points
Segment::Segment(const Point& start, const Point& end): _a(start),_b(end),_myId(_freeID++) {
    #ifndef NDEBUG
        cout << "CREATED Segment: " << _a << " -> " << _b << " ID: " << _myId << endl;
    #endif
    return;
}

//Copy constructor
Segment::Segment(const Segment& s): _a(s._a),_b(s._b),_myId(_freeID++) {
    #ifndef NDEBUG
        cout << "COPIED Segment: " << _a << " -> " << _b << " ID: " << _myId << endl;
    #endif
    return;
}

//Destructor
Segment::~Segment() {
    #ifndef NDEBUG
        cout << "DELETED Segment: " << _a << " -> " << _b << " ID: " << _myId << endl;
    #endif
    return;
}

Segment& Segment::operator=(const Segment& s) {
    _a = s._a;
    _b = s._b;
    return *this;
}

ostream& operator<<(ostream& os, const Segment& s) {
    os << s.start() << "->" << s.end();
    return os;
}

double Segment::length() const {
    return _a.distanceTo(_b);
}

double Segment::distance(const Point& p) const {
    double a = _a.distanceTo(p);
    double b = _b.distanceTo(p);
    double c = length();
    if (a >= sqrt(b * b + c * c)) return b;
    if (b >= sqrt(a * a + c * c)) return a;
    //finding altitude/distance using Heron's formula
    double hper = (a + b + c) / 2;
    return 2 * sqrt(hper * (hper - a) * (hper - b) * (hper - c)) / c;
}

double distance(const Segment& s, const Point& p) {
    double a = s.start().distanceTo(p);
    double b = s.end().distanceTo(p);
    double c = s.length();
    if (a >= sqrt(b * b + c * c)) return b;
    if (b >= sqrt(a * a + c * c)) return a;
    //finding altitude/distance using Heron's formula
    double hper = (a + b + c) / 2;
    return 2 * sqrt(hper * (hper - a) * (hper - b) * (hper - c)) / c;
}