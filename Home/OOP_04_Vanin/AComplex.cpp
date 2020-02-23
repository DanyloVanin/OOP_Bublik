// Danylo Vanin, SE-2, 2020, 3 group, 15.02.20
#include "AComplex.h"
#include "TComplex.h"
#include <cmath>
#include <cassert>

int AComplex::_freeId = 0;

AComplex::AComplex(double re, double im):_re(re),_im(im),_id(_freeId++) {
#ifndef NDEBUG
	cout << "CREATED AComplex: " << *this << endl;
#endif
}

AComplex::AComplex(const AComplex& c) :_re(c.re()), _im(c.im()), _id(_freeId++) {
#ifndef NDEBUG
	cout << "COPIED AComplex: " << *this << endl;
#endif
}

AComplex::AComplex(const TComplex& c): _re(c.re()),_im(c.im()), _id(_freeId++) {
#ifndef NDEBUG
	cout << "COPIED to AComplex: " << *this << endl;
#endif
}

AComplex::~AComplex() {
#ifndef NDEBUG
	cout << "DELETED AComplex: " << *this << endl;
#endif
}

AComplex& AComplex::operator= (const AComplex& c) {
	_re = c.re();
	_im = c.im();
	return *this;
}

double AComplex::mod() const {
	return sqrt(_re * _re + _im * _im);
}
double AComplex::arg() const {
	/*
	// results in += can be different depending on formula: cos counts right, but there are problems in integrity with it
	// the problems are connected with different result that cos and tan/sin give despite being parts of intechangable formulas
	// however, they are interchangeble in all other operators which is quite interesting
	assert(mod() > numeric_limits<double>::epsilon());
	return atan(_im / _re);
	return acos(_re / mod());
	*/
	return asin(_im / mod());
	// need to use atan2 bcs it works in every quarter  - !important
	//return atan2(_im, _re);
}

const AComplex AComplex::conj() const {
	return AComplex(_re, -_im);
}

AComplex& operator+=(AComplex& a, const AComplex& b) {
	a.re() += b.re();
	a.im() += b.im();
	return a;
}
AComplex& operator-=(AComplex& a, const AComplex& b) {
	a.re() -= b.re();
	a.im() -= b.im();
	return a;
}
AComplex& operator*=(AComplex& a, const AComplex& b) {
	/*TComplex aTrig(a);
	TComplex bTrig(b);
	aTrig *= bTrig;
	a = aTrig;
	return a;*/
	/*double re = a.re() * b.re() - a.im() * b.im();
	double im = a.re() * b.im() + b.re() * a.im();
	a.re() = re;
	a.im() = im;
	return a;*/
	//return a *= b;
}
AComplex& operator/=(AComplex& a, const AComplex& b) {
	/*TComplex aTrig(a);
	TComplex bTrig(b);
	aTrig /= bTrig;
	a = aTrig;
	return a;*/
	/*double re = a.re() * b.re() + a.im() * b.im();
	re /= b.re() * b.re() + b.im() * b.im();
	double im = b.re() * a.im() - a.re() * b.im();
	im /= b.re() * b.re() + b.im() * b.im();
	a.re() = re;
	a.im() = im;
	return a;*/
	return a /= b;
}

const AComplex operator+ (const AComplex& a, const AComplex& b) {
	return AComplex(a.re() + b.re(), a.im() + b.im());
}
const AComplex  operator- (const AComplex& a, const AComplex& b) {
	return AComplex(a.re() - b.re(), a.im() - b.im());
}
const AComplex power(const AComplex& c, unsigned int n) {
	TComplex res(c);
	return power(res, n);
}

bool operator== (const AComplex& a, const AComplex& b) {
	return abs(a.re() - b.re()) < numeric_limits<double>::epsilon() &&
		   abs(a.im() - b.im()) < numeric_limits<double>::epsilon();
	//return a.re() == b.re() && a.im() == b.im();
}
bool operator!= (const AComplex& a, const AComplex& b) {
	return !(a == b);
}

ostream& operator<<(ostream& os, const AComplex& c) {
	return os << '(' << c.re() << (c.im() >= 0 ? "+" : "") << c.im() << "*i)";
}
istream& operator>>(istream& is, AComplex& c) {
	cout << "Enter re: ";
	is >> c.re();
	cout << "Enter im: ";
	is >> c.im();
	return is;
}