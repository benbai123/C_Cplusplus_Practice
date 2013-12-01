#include <iostream>

using namespace std;
/** Use virtual keyword to define a function in a class that can be redefined in its derived class.
 * The only valid declaration (virtual or non-virtual) is the declaration within first level Class
 * (first level here means the base class),
 * redefine it (add/remove virtual) in derived class will be ignored.
 * Tested with Dev-C++ 4.9.9.2
 * 
 * Reference:
 *		http://www.cplusplus.com/doc/tutorial/polymorphism/
 */
class Base {
	public:
		// declare funcOne as virtual
		// can override it in derived classes
		virtual void funcOne () {
			cout << "funcOne from Base" << endl;
		}
		// cannot override funcTwo in derived classes
		void funcTwo () {
			cout << "funcTwo from Base" << endl << endl;
		}
};
class DerivedFirst : public Base {
	public:
		// remove virtual ->
		// no effect, still can override it in derived classes
		void funcOne () {
			cout << "funcOne from DerivedFirst" << endl;
		}
		// add virtual keyworkd ->
		// no effect, still cannot override it in derived classes
		virtual void funcTwo () {
			cout << "funcTwo from DerivedFirst" << endl << endl;
		}
};
class DerivedSecond : public DerivedFirst {
	public:
		void funcOne () {
			cout << "funcOne from DerivedSecond" << endl;
		}
		void funcTwo () {
			cout << "funcTwo from DerivedSecond" << endl << endl;
		}
};
int main () {
	// create instances
	Base base;
	DerivedFirst first;
	DerivedSecond second;
	// convert to Base pointer
	Base* dBase = &base;
	Base* dFirst = &first;
	Base* dSecond = &second;
	// call methods
	dBase->funcOne();
	dBase->funcTwo();
	dFirst->funcOne();
	dFirst->funcTwo();
	// still can call non-virtual function from derived class pointer
	// DerivedFirst* pFirst = &first;
	// pFirst->funcTwo();
	dSecond->funcOne();
	dSecond->funcTwo();
	// still can call non-virtual function from derived class pointer
	// DerivedSecond* pSecond = &second;
	// pSecond->funcTwo();
	system("PAUSE");
	return 0;
}
