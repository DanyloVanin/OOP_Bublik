// Developed by Danylo Vanin, SE-2, 3 Group
// on 08.02.2020
// Version 1.0
#include <iostream>
#include <cassert>
#include "Triangle.h"
#include "Segment.h"
using namespace std;

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3): 
	_a(x1,y1), _b(x2,y2), _c(x3,y3), _ab(nullptr), _bc(nullptr), _ca(nullptr), _midAB(nullptr), _midBC(nullptr), _midCA(nullptr) {
#ifndef NDEBUG
	cout << "CREATED " << *this << endl;
#endif
	assert(area() > std::numeric_limits<double>::epsilon());
}
Triangle::Triangle(const Point& a, const Point& b, const Point& c):
	_a(a), _b(b), _c(c), _ab(nullptr), _bc(nullptr), _ca(nullptr), _midAB(nullptr), _midBC(nullptr), _midCA(nullptr) {
#ifndef NDEBUG
	cout << "CREATED " << *this << endl;
#endif
	assert(area() > std::numeric_limits<double>::epsilon());
}
Triangle::Triangle(const Point& a, const Segment& _bc):
	_a(a), _b(_bc.start()), _c(_bc.end()), _ab(nullptr), _bc(nullptr), _ca(nullptr), _midAB(nullptr), _midBC(nullptr), _midCA(nullptr) {
#ifndef NDEBUG
	cout << "CREATED " << *this << endl;
#endif
	assert(area() > std::numeric_limits<double>::epsilon());
}
Triangle::Triangle(const Triangle& t): 
	_a(t.apexA()), _b(t.apexB()), _c(t.apexC()), _ab(nullptr), _bc(nullptr), _ca(nullptr), _midAB(nullptr), _midBC(nullptr), _midCA(nullptr) {
#ifndef NDEBUG
	cout << "COPIED " << *this << endl;
#endif
}
Triangle::~Triangle() {
#ifndef NDEBUG
	cout << "DELETED " << *this << endl;
#endif
	delete _ab;
	delete _bc;
	delete _ca;
	_ab = nullptr;
	_bc = nullptr;
	_ca = nullptr;
	delete _midAB;
	delete _midBC;
	delete _midCA;
	_midAB = nullptr;
	_midBC = nullptr;
	_midCA = nullptr;
}

Triangle& Triangle::operator= (const Triangle& t) {
	delete _ab;
	delete _bc;
	delete _ca;
	_ab = nullptr;
	_bc = nullptr;
	_ca = nullptr;
	delete _midAB;
	delete _midBC;
	delete _midCA;
	_midAB = nullptr;
	_midBC = nullptr;
	_midCA = nullptr;

	_a = t.apexA();
	_b = t.apexB();
	_c = t.apexC();

	return *this;
}

double Triangle::perimeter() const {
	return length_a() + length_b() + length_c();
}
double Triangle::area() const {
	double p = 0.5 * perimeter();
	return sqrt(p * (p - length_a()) * (p - length_b()) * (p - length_c()));
}

const Triangle::Segment &Triangle::side_a() const {
	if (!_bc) {
		_bc = new Segment(_b, _c);
	}
	return *_bc;
}
const Triangle::Segment& Triangle::side_b() const {
	if (!_ca) {
		_ca = new Segment(_c, _a);
	}
	return *_ca;
}
const Triangle::Segment& Triangle::side_c() const {
	if (!_ab) {
		_ab = new Segment(_a, _b);
	}
	return *_ab;
}

double Triangle::length_a() const {
	return side_a().length();
}
double Triangle::length_b() const {
	return side_b().length();
}
double Triangle::length_c() const {
	return side_c().length();
}

const Triangle::Segment Triangle::median_a() const {
	if (!_midBC)
		_midBC = new Point(0.5 * (_b.x() + _c.x()), (0.5 * (_b.y() + _c.y())));
	return Segment(_a, *_midBC);
}
const Triangle::Segment Triangle::median_b() const {
	if (!_midCA)
		_midCA = new Point(0.5 * (_c.x() + _a.x()), (0.5 * (_c.y() + _a.y())));
	return Segment(_b, *_midCA);
}
const Triangle::Segment Triangle::median_c() const {
	//Point temp = (0.5 * (_a.x() + _b.x()), (0.5 * (_a.y() + _b.y())));
	if(!_midAB)
	_midAB = new Point(0.5 * (_a.x() + _b.x()), (0.5 * (_a.y() + _b.y())));
	return Segment(_c, *_midAB);
}

ostream& operator<<(ostream& os, const Triangle& t) {
	os << "Triangle { " << t.apexA() << ' ' << t.apexB() << ' ' << t.apexC() << '}';
	return os;
}

// modifiers (added as a tool to check integrity)
void Triangle::modApexA(const Point& a) {
	Point oldA = _a;
	_a = a;
	if (area() > std::numeric_limits<double>::epsilon()) {
		delete _midCA;
		delete _midAB;
		_midCA = new Point(0.5 * (_c.x() + _a.x()), (0.5 * (_c.y() + _a.y())));
		_midAB = new Point(0.5 * (_a.x() + _b.x()), (0.5 * (_a.y() + _b.y())));
	}
	else _a = oldA;
}
void Triangle::modApexB(const Point& b) {
	Point oldB = _b;
	_b = b;
	if (area() > std::numeric_limits<double>::epsilon()) {
		delete _midAB;
		delete _midBC;
		_midAB = new Point(0.5 * (_a.x() + _b.x()), (0.5 * (_a.y() + _b.y())));
		_midBC = new Point(0.5 * (_b.x() + _c.x()), (0.5 * (_b.y() + _c.y())));
	}
	else _b = oldB;
}
void Triangle::modApexC(const Point& c) {
	Point oldC = _c;
	_c = c;
	if (area() > std::numeric_limits<double>::epsilon()) {
		delete _midBC;
		delete _midCA;
		_midBC = new Point(0.5 * (_b.x() + _c.x()), (0.5 * (_b.y() + _c.y())));
		_midCA = new Point(0.5 * (_c.x() + _a.x()), (0.5 * (_c.y() + _a.y())));
	}
	else _c = oldC;
}