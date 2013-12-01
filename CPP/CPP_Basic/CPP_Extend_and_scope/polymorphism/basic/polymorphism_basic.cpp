#include <iostream>

using namespace std;

/** One of the key features of derived classes is that a pointer to 
 * a derived class is type-compatible with a pointer to its base class. 
 * Polymorphism is the art of taking advantage of this simple but powerful and 
 * versatile feature, that brings Object Oriented Methodologies to 
 * its full potential.
 * 
 * Reference:
 * 		http://www.cplusplus.com/doc/tutorial/polymorphism/
 * 
 */
class Base {
	public:
		// declare funcOne as virtual
		// can override it in derived classes
		virtual void funcOne () {
			cout << "funcOne from Base" << endl;
		}
};
class DerivedFirst : public Base {
	public:
		// remove virtual ->
		// no effect, still can override it in derived classes
		void funcOne () {
			cout << "funcOne from DerivedFirst" << endl;
		}
};
class DerivedSecond : public DerivedFirst {
	public:
		void funcOne () {
			cout << "funcOne from DerivedSecond" << endl;
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

	dFirst->funcOne();

	dSecond->funcOne();

	system("PAUSE");
	return 0;
}
