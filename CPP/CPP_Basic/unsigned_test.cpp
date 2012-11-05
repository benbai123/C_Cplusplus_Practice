#include <iostream>
using namespace std;

/** test unsigned keyword,
 * use char to test it since its range is fixed ( 1 byte )
 */
int main() {
	char ch = -1; // signed char, range -128 ~ 127
	unsigned char uch = ch; // unsigned char, range 0 ~ 255
	cout << "\n\tsigned: " << static_cast<int>(ch) << "\n"
		<< "\tunsigned: " << static_cast<int>(uch) << "\n\n";
	system("PAUSE");
	return 0;
}
