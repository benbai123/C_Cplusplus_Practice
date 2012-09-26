#include <iostream>
#include "ExtendedClass.h"

using namespace std;

int main() {
	ExtendedClass e1;
	ExtendedClass e2(1, 2, 3, 4);

	cout << "\te2._varOne: " << e2._varOne << endl << endl;
	cout << "\te2._varTwo: " << e2.getVarTwo() << endl << endl;
	cout << "\te2._varThree: " << e2.getVarThree() << endl << endl;
	cout << "\te2._varFour: " << e2.getVarFour() << endl << endl;


	// Error! _varTwo is protected member in e2's super class
	// can only access it directly in BaseClass or ExtendedClass
	// cout << "e2._varTwo: " << e2._varTwo << endl << endl;

	// Error! _varThree is private member in e2's super class
	// cout << "e2._varThree: " << e2._varThree << endl << endl;

	// Error! _varFour is private member in e2's class
	// cout << "e2._varFour: " << e2._varFour << endl << endl;

	e1.showAll();
	e2.showAll();
	system("PAUSE");
}
