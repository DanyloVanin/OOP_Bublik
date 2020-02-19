// Developed by Danylo Vanin, SE-2, 3 Group
// on 21.01.2020
// Version 1.0
#include <iostream>
#include "Point.h"

using namespace std;

int main() {
	cout << "Constructors and ID:" << endl;
	{
		cout << "Free ID:" << Point::amount() << endl;
		Point x;
		Point y(3);
		Point z(2, 8);
		Point f(z);
		cout << "Points created:" << Point::amount() << endl;
		cout << x.getID() << endl;
		cout << y.getID() << endl;
		cout << z.getID() << endl;
	}
	cout << "= = = = = = = = = = = = = = = = = = = = = = = =" << endl;

	cout << "Selector and modifiers:" << endl;
	{
		Point k(1, 5);
		cout << "Last point parameters: id:" << k.getID() <<" x: "<< k.x() << " y: " << k.y() << endl;
		k.x() = 4; k.y() = 2;
		cout <<"Changed with modifiers: "<< k << endl;
	}
	cout << "= = = = = = = = = = = = = = = = = = = = = = = =" << endl;
	
	cout << "Operators:" << endl;
	{
		Point a(1, 2);
		Point b(2, 4);
		Point c(3, 6);
		cout << a << '+' << b << '=' << (a + b) << endl;
		cout<<std::boolalpha;
		cout << a << "==" << c <<' ' << (a == c) << endl;
		cout << a << "!=" << c << ' ' << (a != c) << endl;
		a += b;
		cout << "a+=b: " << a << endl;
		cout << a << "==" << c << ' ' << (a == c) << endl;
		cout << a << "!=" << c << ' ' << (a != c) << endl;
	}
	cout << "= = = = = = = = = = = = = = = = = = = = = = = =" << endl;

	return 0;
}