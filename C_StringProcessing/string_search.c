#include <stdio.h>
#include <string.h>
/**
 * 
 * Tested with Dev-C++ 4.9.9.2
 *  
 * Practice of string compare.
 *
 * char * strstr ( const char *, const char * ); 
 *			Locate substring
 *			Returns a pointer to the first occurrence of str2 in str1,
 *			or a null pointer if str2 is not part of str1.
 *
 * References: 
 *		http://www.cplusplus.com/reference/cstring/strstr/
 * 
 */

int main () {
	// string
	char* chPtr = "abcdwxyz";
	char* pos;

	/** Search a string within chPtr
	 *
	 */
	// memory address
	pos = strstr(chPtr, "cd");
	printf("Is 'cd' in chPtr? \n%s\n", (pos != NULL? "true" : "false"));
	// start index is pos - chPtr
	if (pos != NULL) {
		printf("What is the first start index (start from 0) of 'cd' in chPtr? \n%d\n\n", (pos - chPtr));
	}

	printf("abcd starts from \n%d\n", strstr(chPtr, "abcd") - chPtr);
	printf("abcd starts from \n%d\n\n", strstr(chPtr, "wxyz") - chPtr);

	system("PAUSE");
	return 0;
}
