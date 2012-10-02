/*
 * tested with Dev-C++ 4.9.9.2
 */
#include <iostream>
#include "type_casting.h"

using namespace std;

int main () {
	Base baseInstance;
	Extended extendedInstance;
	Unrelated unrelatedInstance;
	const char* strOne = "text one";

	testImplicitConversion(baseInstance, extendedInstance);
	testExplicitConversion(baseInstance, extendedInstance, unrelatedInstance);
	testDynamicCast(baseInstance, extendedInstance, unrelatedInstance);
	testStaticCast(baseInstance, extendedInstance, unrelatedInstance);
	testReinterpretCast(baseInstance, extendedInstance, unrelatedInstance);
	testConstCast(const_cast<char *>(strOne));

	
	system("PAUSE");
}

/**
 **** **** Implicit conversions **** ****
 * do not require any operator
 * they are automatically performed when a value is
 * copied to a compatible type.
 */
void testImplicitConversion(Base baseInstance, Extended extendedInstance) {
	// correct, sub class to super class
	Base b = extendedInstance;
	cout << "test implicit conversions" << endl;
	cout << b.a << endl << endl;
	// wrong, no 'b' in Base class
	// cout << b.b << endl

	// wrong, super class to sub class
	// Extended e = baseInstance;
}

/**
 **** **** Explicit conversion **** ****
 * for most needs with fundamental data types
 * can be applied indiscriminately on classes and pointers to classes,
 * which can * lead to code that while being syntactically correct
 * can cause runtime errors
 */

void testExplicitConversion (Base baseInstance, Extended extendedInstance, Unrelated unrelatedInstance) {
	// correct, sub class to super class
	Base b = (Base)extendedInstance;
	cout << "test explicit conversion" << endl;
	cout << b.a << endl << endl;
	// wrong, no 'b' in Base class
	// cout << b.b << endl

	// syntactically correct, super class pointer to sub class pointer
	Extended *pe = (Extended*)&baseInstance;
	// runtime error, no 'b' in Base class
	// cout << pe->b << endl;

	// wrong, Unrelated to Base
	// Base *pb = (Unrelated*)&unrelatedInstance;
}

/**
 **** **** dynamic_cast **** ****
 *
 * can be used only with pointers and references to objects.
 *
 * Its purpose is to ensure that the result of the type conversion
 * is a valid complete object of the requested class.
 *
 * has overhead of the type-safety checks at run time
 */
void testDynamicCast(Base baseInstance, Extended extendedInstance, Unrelated unrelatedInstance) {
	cout << "test dynamic cast" << endl;
	// correct, cast sub class pointer to super class pointer
	Base* pb = dynamic_cast<Base*>(&extendedInstance);
	Extended* pe;

	// output: 1
	cout << pb->a << endl << endl;
	
	// wrong, cast between two unrelated class pointer
	// pb = dynamic_cast<Base*>(&unrelatedInstance);

	// wrong, cast super class pointer to sub class pointer
	// pe = dynamic_cast<Extended*>(&baseInstance);

}

/**
 **** **** static_cast **** ****
 *
 * can perform conversions between pointers to related classes,
 * can also be used to perform any other non-pointer conversion that
 * could also be performed implicitly,
 * or any conversion between classes with explicit constructors or
 * operator functions as described in "implicit conversions" above.
 *
 * ensures that at least the classes are compatible if the proper
 * object is converted, but no safety check is performed during runtime
 * to check if the object being converted is in fact a full object of
 * the destination type
 *
 * the overhead of the type-safety checks of dynamic_cast is avoided
 */
void testStaticCast(Base baseInstance, Extended extendedInstance, Unrelated unrelatedInstance) {
	cout << "test static cast" << endl;
	// correct, cast sub class pointer to super class pointer
	Base* pb = static_cast<Base*>(&extendedInstance);
	// output: 1
	cout << pb->a << endl;
	// wrong, no 'b' in Base
	// cout << pb->b << endl;

	// correct, cast super class pointer to sub class pointer
	Extended* pe = static_cast<Extended*>(&baseInstance);
	// output: 1
	cout << pe->a << endl << endl;
	// wrong, there is 'b' in Extended but the real object that pe points to is a Base object
	// can run it but the value is unexpectable
	// cout << pe->b << endl;

	// wrong, cast between unrelated class
	// pe = static_cast<Extended*>(&unrelatedInstance);

	// correct, valid Implicit conversion -> valid static_cast
	Base biTwo = static_cast<Base>(extendedInstance);
	// wrong, invalid Implicit conversion -> invalid static_cast
	// Extended eiTwo = static_cast<Extended>(baseInstance);
}
/**
 **** **** reinterpret_cast **** ****
 * converts any pointer type to any other pointer type
 *
 * can also cast pointers to or from integer types
 */
void testReinterpretCast(Base baseInstance, Extended extendedInstance, Unrelated unrelatedInstance) {
	cout << "test reinterpret cast" << endl;
	// cast between unrelated class
	Extended* pe = reinterpret_cast<Extended*>(&unrelatedInstance);
	// maybe unsafe
	cout << pe->a << endl << pe->b << endl;

	// cast pointer to integer
	int nptr = reinterpret_cast<int>(&unrelatedInstance);
	cout << nptr << endl;
	// cast int to pointer
	Base *pb = reinterpret_cast<Base*>(nptr);
	cout << pb->a << endl << endl;
}

/**
 **** **** const_cast **** ****
 * manipulates the constness of an object, either to be set or to be removed
 */
void testConstCast (char* strOne) {
	cout << "test const cast" << endl;
	cout << strOne << endl << endl;
}
