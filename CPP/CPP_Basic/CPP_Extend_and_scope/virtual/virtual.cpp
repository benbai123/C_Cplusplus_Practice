#include <iostream>

using namespace std;

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
	dSecond->funcOne();
	dSecond->funcTwo();
	system("PAUSE");
	return 0;
}
