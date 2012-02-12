#include <stdio.h>
#include <stdlib.h>

/** This is the first practice of C/C++ pointer, it practice two concept:
  * '&' is the reference operator and can be read as "address of"
  * and
  * '*' is the dereference operator and can be read as "value pointed by"
  */
int main () {
    // declare an int variable
    int num = 5;
    // declare an int pointer variable and assign
    // the memory address of an int variable to it.
    int* num_ptr = &num;
    // declare a double variable
    double dblNum = 6.7;
    // declare a double pointer variable and assign
    // the memory address of a double variable to it.
    double* dblNum_ptr = &dblNum;

    // print the value of an int variable
    printf("\n\t%d\n", num);
    // print the memory address of an int variable
    printf("\t%x\n", &num);
    // print the value of an int pointer points to
    printf("\t%d\n", *num_ptr);
    // print the value of an int pointer
    printf("\t%x\n\n", num_ptr);

    // print the value of a double variable
    printf("\t%.2f\n", dblNum);
    // print the address of a double variable
    printf("\t%x\n", &dblNum);
    // print the value of a double pointer points to
    printf("\t%.2f\n", *dblNum_ptr);
    // print the value of a double pointer
    printf("\t%x\n\n", dblNum_ptr);

    // assign the address of a double variable by cast it to int pointer
    num_ptr = (int*)&dblNum;
    // print the double value as int - wrong result
    printf("\t%d\n", *num_ptr);
    // print the address - correct, it still an address
    printf("\t%x\n\n", num_ptr);

    // assign the address of an int variable by cast it to double pointer
    dblNum_ptr = (double*)&num;
    // print the int value as double - wrong result
    printf("\t%.2f\n", *dblNum_ptr);
    // print the address - correct, it still an address
    printf("\t%x\n\n", dblNum_ptr);
    system("PAUSE");
}
