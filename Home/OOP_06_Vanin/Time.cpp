// Danylo Vanin, SE-2, 23.02.20
#include "Time.h"
using namespace std;

const double Time::hourToDec = 1./3600;

void Time::normalizeTime() {
	int s = static_cast<int>(*this);
	_hours = s / 3600;
	_minutes = s / 60 % 60;
	_seconds = s % 60;
}

Time::Time(int h, int m, int s): _hours(h),_minutes(m),_seconds(s) {
	normalizeTime();
#ifndef NDEBUG
	cout << "CREATED Time: " << *this << endl;
#endif
}

Time::Time(const Time& t): _hours(t._hours), _minutes(t._minutes),_seconds(t._seconds)  {
#ifndef NDEBUG
	cout << "COPIED Time: " << *this <<endl;
#endif
}

Time::~Time()
{
#ifndef NDEBUG
	cout << "DELETED Time: " << *this << endl;
#endif
}

Time& Time::operator=(const Time& t) {
	_hours = t.hours();
	_minutes = t.minutes();
	_seconds = t.seconds();
	return *this;
}

Time::operator int() const {
	return _hours * 3600 + _minutes * 60 + _seconds;
}

Time::operator double() const {
	return static_cast<int>(*this) * hourToDec;
}

const Time& Time::operator++()
{
	++_seconds;
	normalizeTime();
	return *this;
}

const Time Time::operator++(int)
{
	Time temp(*this);
	++* this;
	return temp;
}

const Time& Time::operator--()
{
	--_seconds;
	normalizeTime();
	return *this;
}

const Time Time::operator--(int)
{
	Time temp(*this);
	--* this;
	return temp;
}

double operator+(const Time& a, const Time& b)
{
	return double(a) + double(b);
}

bool operator==(const Time& t, const tm* const t2)
{
	return (t.hours() == t2->tm_hour + 2) && (t.minutes() == t2->tm_min) && (t.seconds() == t2->tm_sec);
}
bool operator!=(const Time& t, const tm* const t2)
{
	return !(t==t2);
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	return os << t.hours() << ':' << t.minutes() << ':' << t.seconds();
}
