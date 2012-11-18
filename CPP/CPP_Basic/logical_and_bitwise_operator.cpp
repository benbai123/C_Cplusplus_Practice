#include <iostream>
using namespace std;

/** some practice of logical operators
 * and bitwise operators
 */
int main () {

	cout << endl;
	cout << "\tLogical operators" << endl;
	// && (Logical AND)
	// All true -> true
	// Any false -> false
	cout << "\ttrue && true && true\t -> \t" << (true && true && true? "true" : "false") << endl;
	cout << "\ttrue && true && false\t -> \t" << (true && true && false? "true" : "false") << endl;
	// || (Logical OR)
	// Any true -> true
	// All false -> false
	cout << "\tfalse || false || true\t -> \t" << (false || false || true? "true" : "false") << endl;
	cout << "\tfalse || false || false\t -> \t" << (false || false || false? "true" : "false") << endl;
	// ! (Logical NOT)
	// inverse the value
	cout << "\t!true\t\t\t -> \t" << (!true? "true" : "false") << endl;
	cout << "\t!false\t\t\t -> \t" << (!false? "true" : "false") << endl << endl;

	cout << "\tBitwise operators" << endl;
	// & (Bitwise AND)
	// 0 & any -> 0
	// 1 & 1 -> 1
	// 3 & 5 -> 0011 & 0101 = 0001 -> 1
	cout << "\t3 & 5\t\t\t -> \t" << (3 & 5) << endl;

	// | (Bitwise Inclusive OR)
	// 1 | any -> 1
	// 0 | 0 -> 0
	// 3 | 5 -> 0011 | 0101 = 0111 -> 7
	cout << "\t3 | 5\t\t\t -> \t" << (3 | 5) << endl;

	// ^ (Bitwise Exclusive OR)
	// 0 ^ 0 -> 0
	// 1 ^ 1 -> 0
	// 1 ^ 0 -> 1
	// 0 ^ 1 -> 1
	// 3 ^ 5 -> 0011 ^ 0101 = 0110 -> 6
	cout << "\t3 ^ 5\t\t\t -> \t" << (3 ^ 5) << endl;

	// << (Shift Left)
	// 0001 << 1 -> 0010
	// 0001 << 2 -> 0100
	// shift all bits to left side and add 0 to right side,
	// the left side bits will be dropped,
	// e.g., 100...001 << 1 -> 00...010
	// 
	// can use it as *2 operation 
	// 3 << 1 -> 0011 << 1 = 0110 -> 6 (3*2)
	// 3 << 2 -> 0011 << 2 = 1100 -> 12 (3*2*2)
	cout << "\t3 << 1\t\t\t -> \t" << (3 << 1) << endl;
	cout << "\t3 << 2\t\t\t -> \t" << (3 << 2) << endl;

	// << (Shift Right)
	// 0100 >> 1 -> 0010
	// 0100 >> 2 -> 0001
	// shift all bits to right side and
	// add 0 or 1 (depends on system) to left side,
	// the right side bits will be dropped,
	// e.g., ...00011 >> 1 -> ...0001
	// 
	// can use it as /2 operation 
	// 12 >> 1 -> 1100 >> 1 = 0110 -> 6 (12/2)
	// 12 >> 2 -> 1100 >> 2 = 0011 -> 3 (12/2/2)
	cout << "\t12 >> 1\t\t\t -> \t" << (12 >> 1) << endl;
	cout << "\t12 >> 2\t\t\t -> \t" << (12 >> 2) << endl;

	// ~ (Unary complement (bit inversion))
	// 0 -> 1
	// 1 -> 0
	// ~ (char) -128 -> ~10000000 = 01111111 -> 127
	cout << "\t ~(char)-128\t\t -> \t" << ~(char)-128 << endl;
	cout << endl;

	system("PAUSE");
	return 0;
}
