#include <stdio.h>
#include <stdlib.h>

/** This is the second practice of C/C++ pointer,
  * practice concept:
  * An array can be considered a constant pointer
  */

int main () {
    // declare an int array that contains 5 elements
    int num_arr[5];
    // get the length of the array num
    // we know it is '5', just show how we can get it
    // if we don't know it
    int length = sizeof(num_arr)/sizeof(num_arr[0]);
    // the num_arr can be considered a constant pointer points the num[0]
    int* num_arr_ptr = num_arr;
    int i;

    // assign values to num_arr by the pointer
    // where *(num_arr_ptr+i) denotes
    // 'the ith int element after the first element in num_arr'
    for (i = 0; i < length; i++)
        *(num_arr_ptr+i) = i*10 + i;
    // print the elements of num_arr
    for (i = 0; i < length; i++)
        printf("%d\n", num_arr[i]);
    printf("\n");
    // print the elements of num_arr through pointer
    for (i = 0; i < length; i++)
        printf("%d\n", *(num_arr_ptr+i));
    printf("\n");

    // change the num_arr_ptr that points the
    // 3rd element of num_arr and assign value
    num_arr_ptr = &num_arr[2];
    *num_arr_ptr = 55;
    // change the num_arr_ptr that points the
    // 4th element of num_arr and assign value
    num_arr_ptr = num_arr+3;
    *num_arr_ptr = 66;
    // increase the num_arr_ptr so it points
    // the 5th element and assign value
    num_arr_ptr++;
    *num_arr_ptr = 77;
    // print the elements of num_arr again
    for (i = 0; i < length; i++)
        printf("%d\n", num_arr[i]);
    printf("\n");
    system("pause");
}
