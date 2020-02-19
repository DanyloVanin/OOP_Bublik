// Danylo Vanin, SE-2, 2020, 3 group, 15.02.20
#include "AComplex.h"
#include "TComplex.h"
#include <iostream>
using namespace std;

//variable needed for flexible and convenient output of TComplex
extern bool displayAsAlg;

int main() {
	{
		cout << "AComplex:" << endl;
		//constructors
		cout << "	Constructors: " << endl;
		AComplex def, z1(4, 2);
		AComplex z2(z1);
		cout << "Default: " << def << endl;
		cout << "With re/im constr: " << z1 << endl;
		cout << "Copy constr: " << z2 << endl;
		//operator =
		cout << "	Operator = : (z2)" << z2 << " = (def)" << def << endl;
		z2 = def;
		cout << "Result (z2): " << z2 << endl;
		//modifiers and selectors
		cout << "	Modifiers and selectors: " << endl;
		cout << "Before: " << z2 << endl;
		z2.re() = 8;
		z2.im() = 15;
		cout << "After: re=" << z2.re() << " im=" << z2.im() << endl;
		// mod and arg
		cout << "	Complex number: " << z2 << endl;
		cout << "Mod: " << z2.mod() << endl;
		cout << "Arg: " << z2.arg() << endl;
		// conj 
		cout << "Conj: " << z2.conj() << endl;
		// operator +=
		cout << "	Operators:" << endl;
		cout << z1 << " += " << z2 << " = ";
		z1 += z2;
		cout << z1 << endl;
		// operator -=
		cout << z1 << " -= " << z2 << " = ";
		z1 -= z2;
		cout << z1 << endl;
		// operator *=
		cout << z1 << " *= " << z2 << " = ";
		z1 *= z2;
		cout << z1 << endl;
		// operator /=
		cout << z1 << " /= " << z2 << " = ";
		z1 /= z2;
		cout << z1 << endl;
		// operator +
		cout << z1 << " + " << z2 << " = " << (z1 + z2) << endl;
		// operator -
		cout << z1 << " - " << z2 << " = " << (z1 - z2) << endl;
		// operator ==
		cout << z1 << " == " << z2 << " = " << boolalpha << (z1 == z2) << endl;
		cout << z1 << " == " << z1 << " = " << boolalpha << (z1 == z1) << endl;
		// operator !=
		cout << z1 << " != " << z2 << " = " << boolalpha << (z1 != z2) << endl;
		cout << z1 << " != " << z1 << " = " << boolalpha << (z1 != z1) << endl;
		// power
		int n = 5;
		cout << "	Power: " << endl;
		cout << z1 << " to power of " << n << ": " << power(z1, 5) << endl;
	}
	{
		cout << "=====================================================" << endl;
		cout << "TComplex:" << endl;
		//constructors
		cout << "	Constructors: " << endl;
		TComplex def, z1(4, 2);
		TComplex z2(z1);
		cout << "Default: " << def << endl;
		cout << "With re/im constr: " << z1 << endl;
		cout << "Copy constr: " << z2 << endl;
		//operator =
		cout << "	Operator = : (z2)" << z2 << " = (def)" << def << endl;
		z2 = def;
		cout << "Result (z2): " << z2 << endl;
		//modifiers and selectors
		cout << "	Modifiers and selectors: " << endl;
		cout << "Before: " << z2 << endl;
		z2.mod() = 2;
		z2.arg() = 1.5;
		cout << "After: mod=" << z2.mod() << " arg=" << z2.arg() << endl;
		// mod and arg
		cout << "	Complex number: " << z2 << endl;
		cout << "Re: " << z2.re() << endl;
		cout << "Im: " << z2.im() << endl;
		// operator +=
		cout << "	Operators:" << endl;
		displayAsAlg = true;
		cout << z1 << " += " << z2 << " = "<<endl;
		z1 += z2;
		cout <<"Result: "<< z1 << endl;
		// operator -=
		cout << z1 << " -= " << z2 << " = " << endl;
		z1 -= z2;
		cout << "Result: " << z1 << endl;
		displayAsAlg = false;
		// operator *=
		cout << z1 << " *= " << z2 << " = ";
		z1 *= z2;
		cout << z1 << endl;
		// operator /=
		cout << z1 << " /= " << z2 << " = ";
		z1 /= z2;
		cout << z1 << endl;
		// operator *
		cout << z1 << " * " << z2 << " = " << (z1 * z2) << endl;
		// operator /
		cout << z1 << " / " << z2 << " = " << (z1 / z2) << endl;
		// power
		int n = 5;
		cout << "	Power: " << endl;
		cout << z1 << " to power of " << n << ": " << power(z1, 5) << endl;
	}
	{
		cout << "=====================================================" << endl;
		cout << "Operators and casting: " << endl;
		TComplex zTrig1(2, 4), zTrig2(-3, -5);
		AComplex zAlg1(0, 7), zAlg2(9, -1);
		cout << "	Operator +" << endl;
		displayAsAlg = true;
		cout << zTrig1 << " + " << zTrig2 << " = " << (zTrig1 + zTrig2) << endl;
		cout << zTrig1 << " + " << zAlg1 << " = " << (zTrig1 + zAlg1) << endl;
		cout << zAlg1 << " + " << zTrig1 << " = " << (zAlg1 + zTrig1) << endl;
		cout << zAlg1 << " + " << zAlg2 << " = " << (zAlg1 + zAlg2) << endl;
		cout << "	Operator -" << endl;
		cout << zTrig1 << " - " << zTrig2 << " = " << (zTrig1 - zTrig2) << endl;
		cout << zTrig1 << " - " << zAlg1 << " = " << (zTrig1 - zAlg1) << endl;
		cout << zAlg1 << " - " << zTrig1 << " = " << (zAlg1 - zTrig1) << endl;
		cout << zAlg1 << " - " << zAlg2 << " = " << (zAlg1 - zAlg2) << endl;
		cout << "	Operator *" << endl;
		displayAsAlg = false;
		cout << zTrig1 << " * " << zTrig2 << " = " << (zTrig1 * zTrig2) << endl;
		cout << zTrig1 << " * " << zAlg1 << " = " << (zTrig1 * zAlg1) << endl;
		cout << zAlg1 << " * " << zTrig1 << " = " << (zAlg1 * zTrig1) << endl;
		cout << zAlg1 << " * " << zAlg2 << " = " << (zAlg1 * zAlg2) << endl;
		cout << "	Operator /" << endl;
		cout << zTrig1 << " / " << zTrig2 << " = " << (zTrig1 / zTrig2) << endl;
		cout << zTrig1 << " / " << zAlg1 << " = " << (zTrig1 / zAlg1) << endl;
		cout << zAlg1 << " / " << zTrig1 << " = " << (zAlg1 / zTrig1) << endl;
		cout << zAlg1 << " / " << zAlg2 << " = " << (zAlg1 / zAlg2) << endl;
			
		cout << "	Checking integrity:" << endl;
		displayAsAlg = true;
		cout << (zAlg1 + zAlg2) * zTrig1 << " == "
			 << (zAlg1 * zTrig1 + zAlg2 * zTrig1) << endl;
		
		cout << (zAlg1 * zAlg2) << " == "
		     << (zAlg2 * zAlg1) << endl;
		cout << (zAlg1 + zAlg2) << " == "
			 << (zAlg2 + zAlg1) << endl;
		cout << (zAlg1 - zAlg2) << " == -"
			 << (zAlg2 - zAlg1) << endl;
	}
	{
		cout << "=====================================================" << endl;
		displayAsAlg = false;
		cout << "Input: " << endl;
		// input of TComplex
		cout << "	Input TComplex: " << endl;
		TComplex t;
		cin >> t;
		cout << "Your number is: " << t << endl;
		// input of AComplex
		cout << "	Input AComplex: " << endl;
		AComplex a;
		cin >> a;
		cout << "Your number is: " << a << endl;
	}
	return 0;
}