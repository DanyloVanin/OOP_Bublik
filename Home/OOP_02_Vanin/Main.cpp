// Developed by Danylo Vanin, SE-2, 3 Group
// on 01.02.2020
// Version 1.0

#include <iostream>
using namespace std;

#include "Segment.h"
#include "Point.h"

int main() {
	{
		cout << "Constructors"<<endl;
		Point a(2);
		Point b(2, 7);
		Segment s(a, b);
		{
			Segment s0;
			Segment s_copy(s);
			double x1(1), x2(1), y1(2), y2(8);
			Segment s_c(x1, y1, x2, y2);

			cout << "= = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
			cout << "Length:" << endl;
			cout << s_copy << " length: " << s.length() << endl;
			cout << s0 << " length: " << s0.length() << endl;
			cout << s_c << " length: " << s_c.length() << endl;

			cout << "= = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
			cout << "Desctructor:" << endl;
		}

		cout << "= = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
		cout << "Selectors and modifiers:" << endl;
		cout << s << endl;
		cout << s.start() << ' ' << s.end() << endl;
		cout << '(' << s.startX() << ',' << s.startY() << ") (" << s.endX() << ',' << s.endY() << ')' << endl;

		s.startX() = 3; s.endX() = 3;
		s.startY() = 1; s.endY() = 8;
		cout << "Modified:" << s << endl;;
		
		cout << "= = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
		cout << "Distance:" << endl;
		Point p1(4, 9); // 1
		Point p2(5, -2); // 2
		Point pm(3, 4.5); // middle of segment
		Point p3(3, 1); // start of segment
		Point p4(3, 8); // end of segment
		Point p5(3, 14); // on the line of segment
		Point p6(3, -2); // on the line of segment
		Point p7(5, 6); // distance is perpendicular
		Point p8(7, 3); // distance is perpendicular
		cout << s << " point: " << p1 << " dist: " << s.distance(p1)<<endl;
		cout << s << " point: " << p2 << " dist: " << s.distance(p2) << endl;
		cout << s << " point: " << p3 << " dist: " << s.distance(p3) << endl;
		cout << s << " point: " << p4 << " dist: " << s.distance(p4) << endl;
		cout << s << " point: " << p5 << " dist: " << s.distance(p5) << endl;
		cout << s << " point: " << p6 << " dist: " << s.distance(p6) << endl;
		cout << s << " point: " << p7 << " dist: " << s.distance(p7) << endl;
		cout << s << " point: " << p8 << " dist: " << s.distance(p8) << endl;
		cout << s << " point: " << pm << " dist: " << s.distance(pm) << endl;
	}
	{
		cout << "= = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
		cout << "Another example:" << endl;
		Point p1(1, 3);
		Point p2(2, 7);
		Point p3(4, -2);
		Segment s1to2(p1, p2);
		Segment s2to3(p2, p3);
		Segment s3to1(p3, p1);
		cout << s2to3 << " point: " << p1 << " dist: " << s2to3.distance(p1) << endl;
		cout << s3to1 << " point: " << p2 << " dist: " << s3to1.distance(p2) << endl;
		cout << s1to2 << " point: " << p3 << " dist: " << s1to2.distance(p3) << endl;
		cout << "Using outer function:" << endl;
		cout << s2to3 << " point: " << p1 << " dist: " << distance(s2to3,p1) << endl;
		cout << s3to1 << " point: " << p2 << " dist: " << distance(s3to1,p2) << endl;
		cout << s1to2 << " point: " << p3 << " dist: " << distance(s1to2,p3) << endl;
	}
	return 0;
}