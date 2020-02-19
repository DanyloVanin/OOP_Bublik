// Developed by Danylo Vanin, SE-2, 3 Group
// on 25.01.2020
// Version 1.0
#pragma once
#include "Triangle.h"

class Triangle::Segment
{
private:
    // ID
    static int _freeID;
    const int _myId;
    // Start point
    const Point &_a;
    // End point
    const Point &_b;
    // Operator
    Segment& operator=(const Segment&);
public:
    // Constructor with points
    Segment(const Point& start, const Point& end);
    // Desctructor
    ~Segment();
    // Copy constructor
    Segment(const Segment&);
    // Points selector
    const Point& start() const { return _a; };
    const Point& end() const { return _b; };
    // Length of segment
    double length() const;
    // Distance from point to segment
    double distance(const Point&) const;
};

ostream& operator<<(ostream&, const Triangle::Segment&);