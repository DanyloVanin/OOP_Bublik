// Danylo Vanin, SE-2, 23.03.20
#include "Date.h"
#include <iostream>
#include <ctime>

//#define NDEBUG
using namespace std;

string Date::monthNames[12] = {
"Jan", "Feb", "Mar", "Apr", "May", "Jun",
"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
bool Date::defaultSet = false;
Date Date::_defaultDate = Date();

bool Date::leapYear(int y)
{
	return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
}
void Date::fillDate(const int d, const Month m, const int y) {
	if (!defaultSet) setDefault();
	_day = d ? d : _defaultDate._day;
	_month = m ? m : _defaultDate._month;
	_year = y ? y : _defaultDate._year;
	
	checkDate(_day,_month,_year);
#ifndef NDEBUG
	cout << "FILLED DATE: " << *this << endl;
#endif
}
void Date::checkDate(const int d, const int m, const int y)
{
		int numberOfDays = 0;

		switch (m) {
		case feb: numberOfDays = 28 + leapYear(y); break;
		case apr: case jun: case sep: case nov: numberOfDays = 30; break;
		case jan: case mar: case may: case jul: case aug: case oct: case dec: numberOfDays = 31; break;
		default: throw BadDate(d, m, y);
		}
		
		if ((d < 1) || (numberOfDays < d) || (y < 0))
			throw BadDate(d, m, y);
}

unsigned int Date::numberOfDaysInMonth(const int m, const int y) {
	switch (m) {
	case feb: return 28 + leapYear(y); 
	case apr: case jun: case sep: case nov: return 30;
	case jan: case mar: case may: case jul: case aug: case oct: case dec: return 31; 
	default: throw BadDate(_day, m, y);
	}
}

void Date::normalizeDate() {
	if (_day < 1) {
		if (_month == 1) {
			_month = 12;
			_year--;
		}
		else {
			--_month;
		}
		_day = numberOfDaysInMonth(_month,_year);
	} else {
	int numberOfDays = numberOfDaysInMonth(_month,_year);
	if (_day > numberOfDays) {
		_day = 1;
		if (_month == 12) {
			_month = 1;
			_year++;
		}
		else {
			++_month;
		}
	}
}
#ifndef NDEBUG
		checkDate(_day,_month,_year);
#endif
}

Date::Date(const int d, const Month m, const int y) {
	fillDate(d, m, y);
}
Date::Date(const int d, const int m, const int y) {
	fillDate(d, Month(m), y);
}
Date::Date(const Date& d): _day(d._day), _month(d._month), _year(d._year)
{
#ifndef NDEBUG
	cout << "COPIED Date: " << *this << endl;
#endif
}
Date::~Date()
{
#ifndef NDEBUG
	cout << "DELETED Date: " << *this << endl;
#endif
}

void Date::setDefault(const int d, const Month m,const int y) {
	checkDate(d,m,y);
	_defaultDate = Date(d, m, y);
	defaultSet = true;
#ifndef NDEBUG 
	cout << "SET DEFAULT: ";
	showDefault();
#endif
}
#pragma warning(disable : 4996)
void Date::setDefault() {
	time_t timer; time(&timer);
	struct tm* today = gmtime(&timer);
	_defaultDate._day = today->tm_mday;
	_defaultDate._month = ++(today->tm_mon);
	_defaultDate._year = today->tm_year += 1900;

	defaultSet = true;
#ifndef NDEBUG 
	cout << "SET DEFAULT: ";
	showDefault();
#endif
}
void Date::showDefault() { cout << _defaultDate << endl; }

void Date::setDay(const int d) {
	checkDate(d, _month, _year);
	_day = d;
}
void Date::setMonth(const int m) {
	checkDate(_day, m, _year);
	_month = m;
}
void Date::setYear(const int y) {
	checkDate(_day, _month, y);
	_year = y;
}

ostream& operator<<(ostream& os, const Date& d) {
	os << d.day() << ' ' << d.getMonthName() << ' ' << d.year();// << endl;
	return os;
}
std::ostream& operator<<(std::ostream& os, const Date::BadDate& bd)
{
	os << "Bad Date: "<<bd._day << ' ' << bd._month << ' ' << bd._year << endl;
	return os;
}

const Date& Date::operator++()
{
	_day++;
	normalizeDate();
	return *this;
}
const Date Date::operator++(int)
{
	Date temp(*this);
	++* this;
	return temp;
}
const Date& Date::operator--()
{
	_day--;
	normalizeDate();
	return *this;
}
const Date Date::operator--(int)
{
	Date temp(*this);
	--* this;
	return temp;
}