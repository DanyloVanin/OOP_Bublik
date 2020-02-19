// Developed by Danylo Vanin, SE-2, 3 Group
// on 08.02.2020
// Version 1.0
#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

class Triangle {
public:
	class Segment;
	Triangle(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0, const double x3 = 0, const double y3 = 1);
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Point& a, const Segment& _bc);

	Triangle(const Triangle&);
	~Triangle();
	Triangle& operator= (const Triangle&);

	double perimeter() const;
	double area() const;

	// Apex
	const Point& apexA() const { return _a; };
	const Point& apexB() const { return _b; };
	const Point& apexC() const { return _c; };

	// Modifiers (was decided to be added to check integrity)
	void modApexA(const Point& a);
	void modApexB(const Point& b);
	void modApexC(const Point& c);

	// Side selectors
	const Segment& side_a() const ;
	const Segment& side_b() const ;
	const Segment& side_c() const ;

	// Side length
	double length_a() const;
	double length_b() const;
	double length_c() const;

	// Medians
	const Segment median_a() const;
	const Segment median_b() const;
	const Segment median_c() const;
private:
	Point _a, _b, _c;
	mutable Segment *_ab, *_bc, *_ca;
	mutable Point *_midAB, *_midBC, * _midCA;
	//Segment *_ma, *_mb, *_mc; - can be useful if medians are often needed, otherwise pointers to points-center of the sides is enough
};

ostream& operator<<(ostream&, const Triangle&);