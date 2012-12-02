#include <iostream>

using namespace std;

/** test switch statement
 * 
 * Note: the range part (e.g., 2 ... 35) is an extesion
 *       and may not work with each compiler
 */
void testSwitchNumber (int i);
void testSwitchChar (char ch);
int main() {
	// output: i == 1
	testSwitchNumber(1);
	// output: i between 2 and 35
	testSwitchNumber(2);
	// output: i between 2 and 35
	testSwitchNumber(35);
	// output: i == 40
	//         i is grater then 35
	testSwitchNumber(40);
	cout << endl;

	// output: ch == 'a'
	testSwitchChar('a');
	// output: ch between 'b' and 'z'
	testSwitchChar('c');
	// output: ch between 'A' and 'Z'
	testSwitchChar('C');
	// output: ch is not an alphabet
	testSwitchChar('2');
	cout << endl;

	system("PAUSE");
	return 0;
}

void testSwitchNumber (int i) {
	// Note: the range part (e.g., 2 ... 35) is an extesion
	//       and may not work with each compiler
	switch (i) {
		case 1: // a specific value
			cout << "i == 1" << endl;
			break;
		case 2 ... 35: // a range
			cout << "i between 2 and 35" << endl;
			break;
		case 40: // no break, will continue to try cases below
			cout << "i == 40" << endl;
		default:
			cout << "i is grater then 35" << endl;
	}
}
void testSwitchChar (char ch) {
	// Note: the range part (e.g., 'b' ... 'z') is an extesion
	//       and may not work with each compiler
	switch (ch) {
		case 'a': // a specific char
			cout << "ch == 'a'" << endl;
			break;
		case 'b' ... 'z': // a range
			cout << "ch between 'b' and 'z'" << endl;
			break;
		case 'A' ... 'Z':
			cout << "ch between 'A' and 'Z'" << endl;
			break;
		default:
			cout << "ch is not an alphabet" << endl;
	}
}