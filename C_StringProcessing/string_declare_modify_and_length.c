#include <stdio.h>
#include <string.h>

int main () {
	/**
	 * declare, modify and length
	 *
	 */
	// declare string
	char* chPtr = "abcdefg";// will add '\0' at the tail automatically
	char chArr[] = "bbcdefg";
	char chArrTwo[] = {'c', 'b', 'c', 'd', 'e', 'f', 'g'}; // will not add '\0' automatically
	char chArrThree[] = {'d', 'b', 'c', 'd', 'e', 'f', 'g', '\0', '\0', '\0'};

	// output string
	printf("chPtr = %s\n", chPtr);
	printf("chArr = %s\n", chArr);
	printf("chArrTwo = %s\n", chArrTwo);
	printf("chArrThree = %s\n", chArrThree);

	// output length by sizeof
	// 4, the size of pointer
	printf ("\nLenbgh of char pointer = %d\n", sizeof(chPtr));
	// 8, the size of whole array
	// including a, b, c, d, e, f, g and '\0' (the terminate char added automatically)
	printf ("Length of char array = %d\n", sizeof(chArr));
	// 7, no terminate char
	printf ("Length of char array two = %d\n", sizeof(chArrTwo));
	// 10, including 3 terminate char
	printf ("Length of char array three = %d\n", sizeof(chArrThree));

	// output length by strlen
	// 7, only count the length before first '\0' or array length
	printf ("\nLenbgh of char pointer = %d\n", strlen(chPtr));
	printf ("Length of char array = %d\n", strlen(chArr));
	printf ("Length of char array two = %d\n", strlen(chArrTwo));
	printf ("Length of char array three = %d\n", strlen(chArrThree));

	// replace first char
	// cannot modify char points by a char pointer
	// this line below cause the runtime error
	// chPtr[0] = 'w';
	chArr[0] = 'x';
	chArrTwo[0] = 'y';
	chArrThree[0] = 'z';

	// output string again
	printf("\nchPtr = %s\n", chPtr);
	printf("chArr = %s\n", chArr);
	printf("chArrTwo = %s\n", chArrTwo);
	printf("chArrThree = %s\n\n", chArrThree);
	
	system("PAUSE");
}
