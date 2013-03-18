#include <stdio.h>
#include <string.h>
/**
 * 
 * Tested with Dev-C++ 4.9.9.2
 *  
 * Practice of string compare.
 *
 * int strcmp ( const char * str1, const char * str2 );
 * 			Compares the C string str1 to the C string str2.
 * 			Returns an integral value indicating the relationship between the strings:
 * 			A zero value indicates that both strings are equal.
 * 			A value greater than zero indicates that the first character that does
 * 			not match has a greater value in str1 than in str2; And a value less than zero
 * 			indicates the opposite.
 * size_t strspn ( const char * str1, const char * str2 );
 *			Returns the length of the initial portion of str1 which consists only of characters that are part of str2.
 *			The length of the initial portion of str1 containing only characters that appear in str2.
 *			Therefore, if all of the characters in str1 are in str2,
 *			the function returns the length of the entire str1 string,
 *			if the first character in str1 is not in str2,
 *			the function returns zero.
 * 			size_t is an unsigned integral type.
 *
 * References: 
 * 		http://www.cplusplus.com/reference/cstring/strcmp/
 *		http://www.cplusplus.com/reference/cstring/strspn/
 * 
 */
int main () {
	// string
	char* chPtr = "abcdwxyz";
	int len;

	/** Compare whether two strings are
	 * equal, grater than or less than
	 */
	printf("chPtr equals to 'abcdwxyz'? \n%s\n", (strcmp(chPtr, "abcdwxyz") == 0? "true" : "false"));
	printf("chPtr larger than 'abcd'? \n%s\n", (strcmp(chPtr, "abcd") > 0? "true" : "false"));
	printf("chPtr less than or equal to 'abcd'? \n%s\n\n", (strcmp(chPtr, "abcd") <= 0? "true" : "false"));

	/** Use strspn to compare and find the different position
	 *
	 */
	len = strspn(chPtr, "abcdwxyz");
	printf("Are chPtr and 'abcdwxyz' equal? \n%s\n", (len == strlen(chPtr)? "true" : "false"));
	len = strspn(chPtr, "abcd");
	printf("Are chPtr and 'abcd' equal? \n%s\n", (len == strlen(chPtr)? "true" : "false"));
	printf("What is the first index (start from 0) that 'abcd' different with chPtr? \n%d\n\n", len);

	system("PAUSE");
	return 0;
}
