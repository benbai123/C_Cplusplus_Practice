#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

/** This is the fourth C/C++ Pointer Practice
  * Practice the Function Pointer
  * store the function and the related key code in a struct
  * execute function based on the input
  */

// declare a structure contains
// function pointer: int (*fp) (int, int);
// key: char, will be '+', '-', '*' or '/'
typedef struct op {
    int (*calc) (int, int);
    char key;
} op;

// the function that do the Plus operation
int doPlus (int a, int b) {
     return a+b;
}
// the function that do the Subtract operation
int doSubtract (int a, int b) {
     return a-b;
}
// the function that do the Multiple operation
int doMultiple (int a, int b) {
     return a*b;
}
// the function that do the Divide operation
int doDivide (int a, int b) {
     return a/b;
}

int main () {
    char ch;
    bool finish = true;
    int i;
    // declare an array of the strcuture op,
    // set the function pointer of operation
    // and the proper key char to it.
    op opList[] = {
         &doPlus, '+',
         &doSubtract, '-',
         &doMultiple, '*',
         &doDivide, '/'
    };

    // an infinite loop
    // will output the value
    // 10 + 2, 10 - 2, 10 * 2 or 10 / 2
    // with respect to the input key +, -, * or /
    for (;;) {
        printf("please enter '+', '-', '*' or '/' \nto calculate 10(op)2, or others to exit\n\n");
        ch = getch();
        for (i = 0; i < sizeof(opList)/sizeof(op); i++) {
            if (opList[i].key == ch) {
               // the opList[i].calc is the function to execute
               printf("10 %c 2 = %d\n", ch, opList[i].calc(10, 2));
               finish = false;
            }
        }
        if (finish)
           break;
        finish = true;
    }
    system("PAUSE");
}
