#include <iostream>
#include "BaseClass.h"

using namespace std;

/** Extends BaseClass
 * then can access all public/protected member of
 * BaseClass directly in ExtendedClass
 */
class ExtendedClass : public BaseClass {
	public:
		ExtendedClass ()
		{
			// will call super class' basic constructor
			_varFour = 0;
		}
		// call constructor in super class
		ExtendedClass (int varOne, int varTwo, int varThree, int varFour) : BaseClass (varOne, varTwo, varThree),
				_varFour(varFour) // then assign value
		{
		}
		int getVarFour ()
		{
			return _varFour;
		}
		void showAll ()
		{
			cout << "\tvarOne: " << _varOne << endl // _varOne is public
				<< "\tvarTwo: " << _varTwo << endl // _varTwo is protected
				<< "\tvarThree: " << getVarThree() << endl // _varThree is private member in super class

			// Error! cannot access super class' private member
			// <<"varThree: " << _varThree << endl

				<< "\tvarFour: " << _varFour << endl << endl; // _varFour is in this class
		}
	private:
		int _varFour;
};
