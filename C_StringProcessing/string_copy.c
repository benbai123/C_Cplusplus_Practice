#include <stdio.h>
#include <string.h>
/**
 * 
 * Tested with Dev-C++ 4.9.9.2
 *  
 * Practice of string copy and concat.
 * char * strcpy ( char * destination, const char * source );
 *         copy source to destination
 * char * strncpy ( char * destination, const char * source, size_t num );
 *         copy first n (the specified num) char
 *         from source to destination
 * memset ( void * ptr, int value, size_t num );
 *        Sets the first n (the specified num) bytes of the
 *		  block of memory pointed by ptr to the specified value
 *        (interpreted as an unsigned char).
 * 
 */
int main () {
	// a char array without '\0'
	char chArr[4] = {'a', 'b', 'c', 'd'};
	char chArrTwo[6] = "mnopq";
	char chArrThree[6];
	char chArrFour[6];

	// copy chArr to chArrThree
	// will not add '\0' automatically
	strcpy(chArrThree, chArr);
	printf("chArrThree terminate with \\0? %s \n", (chArrThree[4] == '\0'? "true" : "false"));
	// output chArrThree, may contains wrong value since no \0
	printf("%s\n", chArrThree);


	// add \0 manually
	chArrThree[4] = '\0';
	// copy (replace) first Three char of chArrTwo to chArrThree
	strncpy(chArrThree, chArrTwo, 2);
	printf("chArrThree terminate with \\0? %s \n", (chArrThree[4] == '\0'? "true" : "false"));
	// output chArrThree correctly
	printf("%s\n", chArrThree);

	// use memset to preset all chars in chArrFour to \0
	memset(chArrFour, '\0', sizeof(chArrFour));
	// copy chArr to chArrFour
	strncpy(chArrFour, chArr, sizeof(chArr));
	// NOTE:
	// use strncpy will not clear all specified '\0' --> correct
	// use strcpy as below will clear all specified '\0' --> cause wron string
	// strcpy(chArrFour, chArr);
	printf("chArrFour terminate with \\0? %s \n", (chArrFour[4] == '\0'? "true" : "false"));
	// output chArrFour correctly
	printf("%s\n\n", chArrFour);

	system("PAUSE");
}
