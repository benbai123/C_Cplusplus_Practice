#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/** This is the first practice of struct
  * Practice use struct and union to define a 'data' struct
  * that can contains different type of data
  */

// declare a struct that contains
// only a float variable
// define its type as 'first'
typedef struct first {
        float floatData;
} first;
// declare a struct that contains
// an int variable and a char variable
// define its type as 'second'
typedef struct second {
        int intData;
        char charData;
} second;
// declara a struct that contains
// an int variable thet denotes the data type,
// and an union that will be one of the two data type declared above,
// define its type as 'data'
typedef struct data {
        int type;
        union {
              first firstTypeData;
              second secondTypeData;
        };
} data;
// showData function declaration
void showData (data d);
int main () {
    data dataOne;
    data dataTwo;
    first firstData;
    second secondData;

    // set the type of dataOne
    // set the value of firstData
    // assign firstData to dataOne
    dataOne.type = 1; // first type
    firstData.floatData = 1.2;
    dataOne.firstTypeData = firstData;

    // set the type of data two
    // set the values of secondData
    // assign secondData to dataTwo
    dataTwo.type = 2; // second type
    secondData.intData = 3;
    secondData.charData = 'd';
    dataTwo.secondTypeData = secondData;

    // call showData to show the value(s) of dataOne and dataTwo
    showData(dataOne);
    showData(dataTwo);
    system("PAUSE");
}
void showData (data d) {

     switch (d.type) { // check data type by data.type
            case 1: // first type
                 printf ("float data = %.2f \n\n", d.firstTypeData.floatData);
                 break;
            case 2: // second type
                 printf ("int data = %d\nchar data = %c\n\n", d.secondTypeData.intData, d.secondTypeData.charData);
                 break;
     }
}
