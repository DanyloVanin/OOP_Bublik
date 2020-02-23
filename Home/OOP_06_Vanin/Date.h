// Danylo Vanin, SE-2, 23.03.20
#pragma once
#include <iostream>

class Date {
public:
	struct BadDate;
	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

	Date(int d = 0, Month m = Month(0), int y = 0);
	Date(int d, int m, int y);
	Date(const Date&);
	~Date();

	int day() const { return _day; }
	int month() const { return _month; }
	int year() const { return _year; }

	const std::string getMonthName() const { return monthNames[_month - 1]; }

	void setDay(const int);
	void setMonth(const int);
	void setYear(const int);

	static void setDefault(const int, const Month, const int);
	static void setDefault();
	static void showDefault();

	const Date& operator++();
	const Date  operator++(int);
	const Date& operator--();
	const Date  operator--(int);

private:
	int _day, _month, _year;
	static bool leapYear(int y);
	void fillDate(const int d, const Month m, const int y);
	static std::string monthNames[12];
	static bool defaultSet;
	static Date _defaultDate;

	static void checkDate(const int d, const int m, const int y);
	void normalizeDate();
	unsigned int numberOfDaysInMonth(const int m, const int y);
};

std::ostream& operator<<(std::ostream& os, const Date& d);
bool operator== (const Date&, const tm* const);
bool operator!= (const Date&, const tm* const);

struct Date::BadDate {
	unsigned int _day, _month, _year;
	BadDate(const int d, const int m, const int y) :_day(d), _month(m), _year(y) {};
};

std::ostream& operator<<(std::ostream& os, const Date::BadDate& bd);