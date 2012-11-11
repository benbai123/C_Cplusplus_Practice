#include <iostream>
using namespace std;

/** All non-zero value/non-null pointer will be
 * considered as "true" in conditional operator
 */
class Base {
	public:
		int a;
		Base ()
		{
			a = 1;
		}
};
int main () {
	bool bbb = true;
	Base baseInst;
	Base* baseNull = NULL;
	cout << endl
		<< "\t3 ? \t\t" << (3? "true" : "false") << endl // not zero, true
		<< "\t-1 ? \t\t" << (-1? "true" : "false") << endl // not zero, true
		<< "\t&baseInst ? \t" << (&baseInst? "true" : "false") << endl // pointer and not null, true
		<< "\t\"test\" ? \t" << ("test"? "true" : "false") << endl
		<< "\t0 ? \t\t" << (0? "true" : "false") << endl // zero, false
		<< "\tbaseNull ? \t" << (baseNull? "true" : "false") << endl << endl; // null pointer, false

	system("PAUSE");
	return 0;
}
