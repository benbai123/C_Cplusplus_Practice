#include <stdio.h>
#include <stdlib.h>

/** This is the third C/C++ Pointer Practice
  * Try use Pointer to create 2D array.
  * The fires dimension is a set of pointers that
  * point to the 1D int array,
  * each 1D int array can have different size.
  * 
  * The only problem is unlike we can use sizeof(an_array)
  * to get the size of an array,
  * we have to handle the size here.
  */
int main () {
    // declare a pointer that points to int pointers.
    int** num_ptr_first;
    // allocates 3 block of memory that will store the int pointers.
    num_ptr_first = (int**) malloc (sizeof(int*) * 3);
    // for each block of int pointer,
    // allocates the block(s) of memory that will store the int value(s).
    for (int i = 0; i < 3; i++)
        *(num_ptr_first+i) = (int*) malloc ((i+1)*sizeof(int));
    // assign value to each int value in the simulated 2D array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i+1; j++)
            num_ptr_first[i][j] = (i+1)*(j+1);
    }
    // print the values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i+1; j++)
            printf("%d, ", num_ptr_first[i][j]);
        printf("\n");
    }
    // free the blocks of the int pointers that point to int values
    for (int i = 0; i < 3; i++)
        free(num_ptr_first[i]);
    // free the blocks of the pointer that points to int pointers
    free(num_ptr_first);
    printf("\n");
    system("PAUSE");
}
