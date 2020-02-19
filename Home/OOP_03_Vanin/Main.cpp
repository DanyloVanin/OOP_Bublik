// Developed by Danylo Vanin, SE-2, 3 Group
// on 08.02.2020
// Version 1.0
#include <iostream>
using namespace std;
#include "Triangle.h"
#include "Segment.h"
#include "Point.h"

int main() {
	cout << "All constructors:" << endl;
	Triangle t0;		
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);
	Triangle::Segment bc(b, c);
	Triangle t1(a, b, c);
	Triangle t2(a, b, c);
	Triangle t3(t2);
	cout << endl;
	cout << " Operator = " << endl;
	t0 = t3;
	cout << t0;
	cout << endl;
	cout << "================================================" << endl;
	cout << "Sides and length " << endl;
	cout << " Length AB: " << t0.side_c() << " is: " << t0.length_c() << endl;
	cout << " Length BC: " << t0.side_a() << " is: " << t0.length_a() << endl; 
	cout << " Length CA: " << t0.side_b() << " is: " << t0.length_b() << endl;
	cout << endl;
	cout << "================================================" << endl;
	cout << "Area and perimeter " << t0<< endl;
	cout << " Perimeter: " << t0.perimeter() << endl;
	cout << " Area: " << t0.area() << endl;
	cout << endl;
	cout << "================================================" << endl;
	cout << "Medians:" << endl;
	cout << "Median A: "<< t0.median_a() << endl;
	cout << "Median B: " << t0.median_b() << endl;
	cout << "Median C: " << t0.median_c() << endl;

	cout << endl;
	cout << "================================================" << endl;
	cout << "Modifiying/Checking integrity:" << endl;
	cout <<"Old: "<< t0 << endl;
	Point nA(1, 1);
	Point nB(1, 6);
	Point nC(6, 1);
	t0.modApexA(nA);
	t0.modApexB(nB);
	t0.modApexC(nC);
	cout <<"New: "<< t0 << endl;
	cout << "================================================" << endl;
	cout << "     Results of tringle with changed points   "  <<endl<<t0<< endl;
	cout << "================================================"  << endl;
	cout << "Sides and length " << endl;
	cout << " Length AB: " << t0.side_c() << " is: " << t0.length_c() << endl;
	cout << " Length BC: " << t0.side_a() << " is: " << t0.length_a() << endl;
	cout << " Length CA: " << t0.side_b() << " is: " << t0.length_b() << endl;
	cout << endl;
	cout << "Area and perimeter " << t0 << endl;
	cout << " Perimeter: " << t0.perimeter() << endl;
	cout << " Area: " << t0.area() << endl;
	cout << endl;
	cout << "Medians:" << endl;
	cout << "Median A: " << t0.median_a() << endl;
	cout << "Median B: " << t0.median_b() << endl;
	cout << "Median C: " << t0.median_c() << endl;

	return 0;
}