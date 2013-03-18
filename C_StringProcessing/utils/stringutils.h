#include <stdio.h>
#include <string.h>
/**
 * 
 * Tested with Dev-C++ 4.9.9.2
 *  
 * Practice of string copy and concat.
 *
 * char * strncpy ( char * destination, const char * source, size_t num );
 *         copy first n (the specified num) char
 *         from source to destination
 * void* malloc (size_t size);
 *         Allocate memory block
 *         Allocates a block of size bytes of memory,
 *         returning a pointer to the beginning of the block.
 *         
 *         The content of the newly allocated block of memory is not initialized,
 *         remaining with indeterminate values.
 *         
 *         If size is zero, the return value depends on the particular
 *         library implementation (it may or may not be a null pointer),
 *         but the returned pointer shall not be dereferenced.
 * void free (void* ptr);
 *         A block of memory previously allocated by a call to malloc,
 *         calloc or realloc is deallocated,
 *         making it available again for further allocations.
 *         
 *         If ptr does not point to a block of memory allocated with the
 *         above functions, it causes undefined behavior.
 *         
 *         If ptr is a null pointer, the function does nothing.
 *         Notice that this function does not change the value of ptr itself,
 *         hence it still points to the same (now invalid) location.
 * void * memset ( void * ptr, int value, size_t num );
 *         Fill block of memory
 *         Sets the first num bytes of the block of memory pointed by ptr to
 *         the specified value (interpreted as an unsigned char).
 * 
 * char * substring ( const char * source, int startIndex, int endIndex );
 *         custom function for getting a substring of source string
 *         source: the source string
 *         startIndex: start index (inclusive) of sub string in source string
 *         endIndex: end index (exclusive) of sub string in source string
 *         return: pointer of the sub string, or null if any error occured
 *
 *         NOTE: substring will return malloced pointer,
 *               remember to free it as needed.
 *
 * References:
 * http://www.cplusplus.com/reference/cstring/strncpy/
 * http://www.cplusplus.com/reference/cstdlib/malloc/
 * http://www.cplusplus.com/reference/cstdlib/free/
 * http://www.cplusplus.com/reference/cstring/memset/
 * 
 */
char * substring ( const char * source, int startIndex, int endIndex );
/**
 * custom function for getting a substring of source string
 *         source: the source string
 *         startIndex: start index (inclusive) of sub string in source string
 *         endIndex: end index (exclusive) of sub string in source string
 *         return: pointer of the sub string, or null if any error occured
 *
 *         NOTE: substring will return malloced pointer,
 *               remember to free it as needed.
 */
char * substring ( const char * source, int startIndex, int endIndex ) {
	char* result = NULL;
	if (startIndex < 0) {
		printf("startIndex should be a positive value\n");
	}
	else if (endIndex <= startIndex) {
		printf("endIdnex should larger than startIndex\n");
	} else if (startIndex > (strlen(source))) {
		printf("startIdnex should smaller than source length\n");
	} else if (endIndex > (strlen(source)+1)) {
		printf("endIdnex should smaller than or equal to source length\n");
	} else {
		int len = endIndex - startIndex;
		result = (char*)malloc(sizeof(char)*len+1);
		memset (result, '\0', len+1);
		strncpy (result, source+startIndex, len);
	}
	return result;
}
