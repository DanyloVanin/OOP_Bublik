// Danylo Vanin, SE-2, 23.03.20
#pragma once
#include "Time.h"
#include "Date.h"
#include <ctime>

class Timer {
private: 
	Date& _startDate;
	Time& _startTime;
	Time& _interval;
	void checkParameters();
	bool badStartParameters(const Date& d, const Time& t, const tm* const today);
public: 
	Timer(Date& date, Time& time, Time& interval);
	~Timer() {};
	Timer& operator=(const Timer&);
	void waitAndStartCountdown();

	Date startDate() const { return _startDate; }
	Time startTime() const { return _startTime; }
	Time interval() const { return _interval; }
	Date& startDate() { return _startDate; }
	Time& startTime() { return _startTime; }
	Time& interval() { return _interval; }
};