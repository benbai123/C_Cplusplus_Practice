#include <stdio.h>
#include <string.h>
/**
 * 
 * Tested with Dev-C++ 4.9.9.2
 *  
 * Practice of string copy and concat.
 * char * strcat ( char * destination, const char * source );
 *         Appends a copy of the source string to the destination string
 *         plus a terminating null-character if source contains null-character.
 * char * strncat ( char * destination, char * source, size_t num );
 *         Appends the first num characters of source to destination,
 *         plus a terminating null-character.
 *
 * Note: 
 * 
 */
int main () {
	// a char array without '\0'
	char chArr[4] = {'a', 'b', 'c', 'd'};
	char chArrTwo[20] = "mnopq";
	char chArrThree[] = "abcd";
	char chArrFour[20] = "wxyz";

	// the source (chArr) doesn't have null-char ('\0')
	// will become wrong value after first concat
	printf("original: %s\n", chArrTwo);
	strcat(chArrTwo, chArr); // <-- the line above
	// change the line above to the line below then everything should be okay.
	// strncat(chArrTwo, chArr, 4); // <-- the line below
	printf("append abcd: %s\n", chArrTwo);
	strncat(chArrTwo, chArr, 2);
	printf("append ab: %s\n\n", chArrTwo);

	// the source (chArrThree) contains null-char ('\0')
	// everything should be okay
	printf("original: %s\n", chArrFour);
	strcat(chArrFour, chArrThree);
	printf("append abcd: %s\n", chArrFour);
	strncat(chArrFour, chArrThree, 2);
	printf("append ab: %s\n\n", chArrFour);

	system("PAUSE");
}
