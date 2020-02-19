// Danylo Vanin, SE-2, 2020, 3 group, 15.02.20
#include "TComplex.h"
#include "AComplex.h"
#include <cmath>

bool displayAsAlg = false;
int TComplex::_freeId = 0;

TComplex::TComplex(double ro, double phi): _ro(ro),_phi(phi),_id(_freeId++) {
#ifndef NDEBUG
	cout << "CREATED TComplex: " << *this << endl;
#endif
}

TComplex::TComplex(const TComplex& c): _ro(c._ro),_phi(c._phi),_id(_freeId++) {
#ifndef NDEBUG
	cout << "COPIED TComplex: " << *this << endl;
#endif
}

TComplex::TComplex(const AComplex& c): _ro(c.mod()),_phi(c.arg()),_id(_freeId++) {
#ifndef NDEBUG
	cout << "CASTED to TComplex: " << *this << endl;
#endif
}

TComplex::~TComplex() {
#ifndef NDEBUG
	cout << "DELETED TComplex: " << *this << endl;
#endif
}

TComplex& TComplex::operator= (const TComplex& c) {
	_ro = c.mod();
	_phi = c.arg();
	return *this;
}

double TComplex::re() const {
	return _ro * cos(_phi);
}
double TComplex::im() const {
	return _ro * sin(_phi);
}

TComplex& operator+=(TComplex& a, const TComplex& b) {
	AComplex aAlg(a);
	AComplex bAlg(b);
	aAlg += bAlg;
	a = static_cast<TComplex>(aAlg);
	return a;
}
TComplex& operator-=(TComplex& a, const TComplex& b) {
	AComplex aAlg(a);
	AComplex bAlg(b);
	aAlg -= bAlg;
	a = static_cast<TComplex>(aAlg);
	return a;
}
TComplex& operator*=(TComplex& a, const TComplex& b) {
	a.mod() *= b.mod();
	a.arg() += b.arg();
	return a;
}
TComplex& operator/=(TComplex& a, const TComplex& b) {
	a.mod() /= b.mod();
	a.arg() -= b.arg();
	return a;
}

const TComplex operator* (const TComplex& a, const TComplex& b) {
	TComplex c(a);
	return c *= b;
}
const TComplex  operator/ (const TComplex& a, const TComplex& b) {
	TComplex c(a);
	return c /= b;
}
const TComplex power(const TComplex& a, unsigned int n) {
	double ro = pow(a.mod(), n);
	double phi = a.arg() * n;
	return TComplex(ro, phi);
}

ostream& operator<<(ostream& os, const TComplex& c) {
	// added to display number in more convenient way for testing +,- operators
	if (displayAsAlg) 
		return os << '(' << c.re() << (c.im() >= 0 ? "+" : "") << c.im() << "*i)";
	
	return os << c.mod() << "*(cos("<<c.arg()<<")+i*sin(" << c.arg() << "))";
}
istream& operator>>(istream& is, TComplex& c) {
	cout << "Enter ro: ";
	is >> c.mod();
	cout << "Enter phi: ";
	is >> c.arg();
	return is;
}