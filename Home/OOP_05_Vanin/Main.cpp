// Danylo Vanin, SE-2, 23.03.20
#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	try {
		{
		cout << "====================================================" << endl;
		cout << "Default date: " << endl;
		Date::showDefault();
		cout << "Changed default date: " << endl;
		Date::setDefault(1, Date::Month(1), 2001);
		Date::showDefault();
		cout << "Resetting default date: " << endl;
		Date::setDefault();
		Date::showDefault();

		cout << "====================================================" << endl;
		cout << "Constructors: " << endl;
		cout << "Default constructor: " << endl;
		Date d;
		cout << d << endl;
		cout << "Custom constructor: " << endl;
		Date d1(28, 2, 2019);
		cout << d1 << endl;
		cout << "Copy constructor: " << endl;
		Date d2(d1);
		cout << d2 << endl;

		cout << "====================================================" << endl;
		cout << "Operators: " << endl;
		cout << "++( " << d1 << " ): ";
		cout << ++d1 << endl;
		cout << "( " << d1 << " )++ : " << endl;
		cout << d1++ << endl;
		cout << "Result(2): " << d1 << endl;

		cout << "--( " << d1 << " ): ";
		cout << --d1 << endl;
		cout << "( " << d1 << " )-- : ";
		cout << d1-- << endl;
		cout << "Result(2): " << d1 << endl;

		// selectors
		cout << "====================================================" << endl;
		cout << "Selectors: " << endl;
		cout << "Date: " << d1 << endl;
		cout << "Day: " << d1.day() << endl;;
		cout << "Month: " << d1.month() << endl;;
		cout << "Month name: " << d1.getMonthName() << endl;;
		cout << "Year: " << d1.year() << endl;;

		// modifiers
		cout << "====================================================" << endl;
		cout << "Modifiers: " << endl;
		cout << "Old date: " << d1 << endl;
		d1.setDay(17);
		d1.setMonth(6);
		d1.setYear(2024);
		cout << "New date: " << d1 << endl;

		//leap year
		cout << "====================================================" << endl;
		cout << "Leap year situation: " << endl;
		d2.setYear(2020);
		cout << "Date: " << d2 << endl;
		cout << "++Date: " << ++d2 << endl;
		cout << "++Date: " << ++d2 << endl;
		cout << "--Date: " << --d2 << endl;

		// to next year
		cout << "====================================================" << endl;
		cout << "New year situation: " << endl;
		Date d3(31, 12, 2001);
		cout << "Date: " << d3 << endl;
		cout << "++Date: " << ++d3 << endl;
		cout << "--Date: " << --d3 << endl;

		// to prev and next month
		cout << "====================================================" << endl;
		cout << "Prev & next month situation: " << endl;
		Date d4(1, 9, 2018);
		cout << "Date: " << d4 << endl;
		cout << "--Date: " << --d4 << endl;
		cout << "++Date: " << ++d4 << endl;

		d4.setDay(30);
		cout << "Date: " << d4 << endl;
		cout << "++Date: " << ++d4 << endl;
		cout << "--Date: " << --d4 << endl;
		}
		//Errors
		cout << "====================================================" << endl;
		cout << "Errors: " << endl;
		Date err1(29, 2, 2019);
		//Date err2(32, 5, 2030);
		//Date err3(14, 13, 2001);
		//Date err4(14, 12, -1);
		//Date d4(1, 9, 2018);
		//d4.setDay(31);
		//d4.setMonth(-14);
		//d4.setYear(-2);
	}
	catch (Date::BadDate err) {
		cerr << err;
	}
}