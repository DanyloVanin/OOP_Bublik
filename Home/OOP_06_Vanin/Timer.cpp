// Danylo Vanin, SE-2, 23.03.20
#pragma warning(disable : 4996)
#include "Timer.h"
#include <iostream>
#include "Windows.h"
using namespace std;

void Timer::checkParameters() {
	time_t timer; time(&timer);
	struct tm* today = gmtime(&timer);

	if (badStartParameters(_startDate, _startTime, today)) {
		throw "Invalid start date or time parameters!";
	}
}

bool Timer::badStartParameters(const Date& d, const Time& t, const tm* const today)
{
	if (d.year() < today->tm_year + 1900) return true; 
	else if (d.year() > today->tm_year + 1900) return false;
	if (d.month() < today->tm_mon+1) return true;
	else if (d.month() > today->tm_mon + 1) return false;
	if (d.day() < today->tm_mday) return true;
	else if (d.day() > today->tm_mday) return false;
	if (t.hours() > 24) return true;
    if (t.hours() < today->tm_hour +2 ) return true;
	else if (t.hours() > today->tm_hour + 2) return false;
	if (t.minutes() < today->tm_min) return true;
	else if (t.minutes() > today->tm_min) return false;
	if (t.seconds() < today->tm_sec) return true;
	return false;
}

Timer::Timer(Date& date, Time& time, Time& interval): _startDate(date), _startTime(time), _interval(interval) {
	checkParameters();
}
Timer& Timer::operator=(const Timer& t)
{
	_startDate = t.startDate();
	_startTime = t.startTime();
	_interval = t.interval();
	return *this;
}

void Timer::waitAndStartCountdown() {
	time_t timer; time(&timer);
	struct tm* now = gmtime(&timer);

	cout << "Waiting for: " << startDate() << ' ' << startTime() << endl;
	while ((startDate() != now) || (startTime() != now)) {
		time(&timer);
		now = gmtime(&timer);
		Sleep(1000);
		cout << char(13) << "Now: "
			 <<now->tm_mday << '.' << now->tm_mon + 1 << '.' << now->tm_year + 1900 << ' '
			 << now->tm_hour+2 << ':' << now->tm_min     << ':' << now->tm_sec << "      ";
	}

	Time timeLeft = _interval;
	cout << "Timer started:" << endl;
	while (static_cast<int>(timeLeft)) {
		cout << char(13) << "Time left: " << timeLeft << "       ";
		--timeLeft;
		Sleep(1000);
	}
	cout <<endl<< "Time is up!" << endl;
}
