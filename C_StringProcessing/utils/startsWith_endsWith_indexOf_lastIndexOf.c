#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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
 * bool startsWith (char* base, char* str);
 *			Custom function for detecting whether base is starts with str
 * bool endsWith (char* base, char* str);
 *			Custom function for detecting whether base is ends with str
 * int indexOf (char* base, char* str)
 *			Custom function for getting the first index of str in base
 *			-1 denotes not found
 * int indexOf_shift (char* base, char* str, int startIndex)
 *			Custom function for getting the first index of str in base
 *			after the given startIndex
 *			-1 denotes not found
 * int lastIndexOf (char* base, char* str)
 *			Custom function for getting the last index of str in base
 *			-1 denotes not found
 * References: 
 *		http://www.cplusplus.com/reference/cstring/strstr/
 * 
 */

bool startsWith (char* base, char* str);
bool endsWith (char* base, char* str);
int indexOf (char* base, char* str);
int indexOf_shift (char* base, char* str, int startIndex);
int lastIndexOf (char* base, char* str);
int main () {
	// a char array without '\0'
	char* chArrOne = "abcdefabcdef";

	printf("chArrOne starts with abc?\n%s\n\n", startsWith(chArrOne, "abc")? "true" : "false");
	printf("chArrOne starts with def?\n%s\n\n", startsWith(chArrOne, "def")? "true" : "false");
	printf("chArrOne ends with def?\n%s\n\n", endsWith(chArrOne, "def")? "true" : "false");
	printf("first index of abc in chArrOne?\n%d\n\n", indexOf(chArrOne, "abc"));
	printf("first index of def in chArrOne?\n%d\n\n", indexOf(chArrOne, "def"));
	printf("first index of abc in chArrOne after index 2?\n%d\n\n", indexOf_shift(chArrOne, "abc", 2));
	printf("first index of def in chArrOne after index 5?\n%d\n\n", indexOf_shift(chArrOne, "def", 5));
	printf("last index of abc in chArrOne?\n%d\n\n", lastIndexOf(chArrOne, "abc"));
	printf("last index of def in chArrOne?\n%d\n\n", lastIndexOf(chArrOne, "def"));
	

	system("PAUSE");
	return 0;
}
/** detecting whether base is starts with str
 */
bool startsWith (char* base, char* str) {
	return (strstr(base, str) - base) == 0;
}
/** detecting whether base is ends with str
 */
bool endsWith (char* base, char* str) {
	int blen = strlen(base);
	int slen = strlen(str);
	return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}
/** getting the first index of str in base
 */
int indexOf (char* base, char* str) {
	return indexOf_shift(base, str, 0);
}
int indexOf_shift (char* base, char* str, int startIndex) {
	int result;
	int baselen = strlen(base);
	// str should not longer than base
	if (strlen(str) > baselen || startIndex > baselen) {
		result = -1;
	} else {
		if (startIndex < 0 ) {
			startIndex = 0;
		}
		char* pos = strstr(base+startIndex, str);
		if (pos == NULL) {
			result = -1;
		} else {
			result = pos - base;
		}
	}
	return result;
}
/** use two index to search in two part to prevent the worst case
 * (assume search 'aaa' in 'aaaaaaaa', you cannot skip three char each time)
 */
int lastIndexOf (char* base, char* str) {
	int result;
	// str should not longer than base
	if (strlen(str) > strlen(base)) {
		result = -1;
	} else {
		int start = 0;
		int endinit = strlen(base) - strlen(str);
		int end = endinit;
		int endtmp = endinit;
		while(start != end) {
			start = indexOf_shift(base, str, start);
			end = indexOf_shift(base, str, end);

			// not found from start
			if (start == -1) {
				end = -1; // then break;
			} else if (end == -1) {
				// found from start
				// but not found from end
				// move end to middle
				if (endtmp == (start+1)) {
					end = start; // then break;
				} else {
					end = endtmp - (endtmp - start) / 2;
					if (end <= start) {
						end = start+1;
					}
					endtmp = end;
				}
			} else {
				// found from both start and end
				// move start to end and
				// move end to base - strlen(str)
				start = end;
				end = endinit;
			}
		}
		result = start;
	}
	return result;
}
