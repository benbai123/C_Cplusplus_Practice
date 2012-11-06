#include <iostream>
#include <iomanip>
using namespace std;

/** test unsigned keyword,
 * use char to test it since its range is fixed ( 1 byte )
 */
int main() {
	cout << "\tvalue - type: " << endl << endl << "\t"
		<< 11 << " - " << typeid(11).name() << "(int)" << endl << "\t" // int
		<< 011 << " - " << typeid(011).name() << "(int)" << endl << "\t" // int, octonary
		<< 0x11 << " - " << typeid(0x11).name() << "(int)" << endl << "\t" // int, hex
		<< 11U << " - " << typeid(11U).name() << "(unsigned int)" << endl << "\t" // unsigned int
		<< 11L << " - " << typeid(11L).name() << "(long)" << endl << "\t" // long
		<< 11UL << " - " << typeid(11UL).name() << "(unsigned long)" << endl << "\t" // unsigned long
		<< setprecision(2) << fixed // change to fixed format, 11.0 -> 11.00
        << 11.0 << " - " << typeid(11.0).name() << "(double)" << endl << "\t" // double
        << noshowpoint << setprecision( 0 )  // change to no point, 11.0 -> 11
		<< 1.1e1 << " - " << typeid(1.1e1).name() << "(double)" << endl << "\t" // double
		<< scientific // change to scientific notation, 11.0 -> 1.10e+001
		<< 11.0F << " - " << typeid(11.0F).name() << "(float)" << endl << endl; // float
	system("PAUSE");
	return 0;
}
