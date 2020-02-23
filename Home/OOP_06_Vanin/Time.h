// Danylo Vanin, SE-2, 23.03.20
#pragma once
#include <iostream>

class Time {
private:
	int _hours;
	int _minutes;
	int _seconds;
	void normalizeTime();
public:
	static const double hourToDec;
	Time(int h = 0, int m = 0, int s = 0);
	Time(const Time&);
	~Time();

	Time& operator=(const Time&);
	operator int() const;
	operator double() const;

	int hours() const { return _hours; }
	int minutes() const { return _minutes; }
	int seconds() const { return _seconds; }

	int& hours() { return _hours; }
	int& minutes() { return _minutes; }
	int& seconds() { return _seconds; }

	const Time& operator++();
	const Time operator++(int);
	const Time& operator--();
	const Time operator--(int);
};

double operator+ (const Time&, const Time&);
bool operator== (const Time&, const tm* const);
bool operator!= (const Time&, const tm* const);
std::ostream& operator<<(std::ostream&, const Time&);