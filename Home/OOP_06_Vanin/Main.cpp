// Danylo Vanin, SE-2, 23.03.20
#include "Timer.h"
#include <iostream>

using namespace std;

int main() {
	{
		cout << "===============================================" << endl;
		cout << "\t\t\tTime:" << endl;
		cout << "===============================================" << endl;
		cout << "Constructors:" << endl;
		Time def, t0(5, 6, 2), t1(t0);
		cout << "Default constructor: " <<def<< endl;
		cout << "Custom constructor: " << t0 << endl;
		cout << "Copy constructor: " << t1 << endl;
		//def = t0;
		cout << "Operator =: (before): " << def;
		cout << " (after): " << (def = t0) << endl;

		cout << "===============================================" << endl;
		cout << "Casting: " << t0<< endl;
		cout << "To int: " << int(t0) << endl;
		cout << "To double: " << double(t0) << endl;
		
		cout << "===============================================" << endl;
		cout << "Selectors:" << t0 << endl;
		cout << "Hours: " << t0.hours() << endl;
		cout << "Minutes: " << t0.minutes() << endl;
		cout << "Seconds: " << t0.seconds() << endl;
	
		cout << "===============================================" << endl;
		cout << "Modifiers:" << endl;
		t0.hours() = 18;
		t0.minutes() = 59;
		t0.seconds() = 59;
		cout << "Hours: " << t0.hours() << endl;
		cout << "Minutes: " << t0.minutes() << endl;
		cout << "Seconds: " << t0.seconds() << endl;
		cout << "New time: " << t0 << endl;

		cout << "===============================================" << endl;
		cout << "Operators:" << endl;
		cout << " ++( " << t0 << " ): ";
		cout << (++t0) << endl;
		cout << " ( " << t0 << " )++: "<<endl;
		cout << "Result(1): " << (t0++) << endl;
		cout << "Result(2): " << t0 << endl;
		cout << " --( " << t0 << " ): "; 
		cout << (--t0) << endl;
		cout << " ( " << t0 << " )--: "<<endl;
		cout << "Result(1): " << (t0--) << endl;
		cout << "Result(2): " << t0 << endl;

		cout << "===============================================" << endl;
		cout << "Operator +:" << endl;
		Time t2(1, 0, 1);
		cout << t0 << " + " << t2 << " = " << (t0 + t2) << endl;
		cout << "Check: "<< double(t0) + double(t2) << endl;
		t2.minutes() = 1;
		cout << t0 << " + " << t2 << " = " << (t0 + t2) << endl;
		cout << "Check: " << double(t0) + double(t2) << endl;
	}
	{
		cout << "===============================================" << endl;
		cout << "\t\t\tTimer:" << endl;
		cout << "===============================================" << endl;
		Date startDate(23, 02, 2020);
		Time startTime(16, 23, 20);
		Time interval(0, 0, 10);
		try {
			Timer tr(startDate, startTime, interval);
			tr.waitAndStartCountdown();

			cout << endl << "Errors: " << endl;
			startDate.setYear(2019);
			Timer err(startDate, startTime, interval);
		}
		catch (const char* const error) {
			cout << error << endl;
		}
	}	
	return 0;
}