#include <stdio.h>
#include <stdlib.h>
/**
  * This sample practice the shallow copy and
  * deep copy of struct in c.
  *
  * Shallow copy:
  *          copy all member field values, the copied pointer and
  *          the original pointer will point to the same address
  * Deep copy:
  *           copy the field values that are not pointer,
  *           create new pointer for pointer value,
  *           and copy the real content from old address to new address.
  */
typedef struct DataStruct {
        int data_one;
        int* data_two;
} DataStruct;
void deepCopy(DataStruct* to, DataStruct* from);
int main () {
    DataStruct dsOne;
    DataStruct dsTwo;
    DataStruct dsThree;

    int data_two = 2;
    // assign the datas to mainsOne
    dsOne.data_one = 1;
    dsOne.data_two = &data_two;

    // shallow copy dsOne to dsTwo
    memcpy(&dsTwo, &dsOne, sizeof(DataStruct));
    // deep copy dsOne to dsThree
    deepCopy(&dsThree, &dsOne);
    // show the value of original data
    printf("original data_one is %d,\noriginal data_two is %d\n\n", dsOne.data_one, *dsOne.data_two);

    // change the data of dsOne
    dsOne.data_one = 3;
    *dsOne.data_two = 4;

    // show the data of dsTwo after dsOne changed
    // actually dsOne.data_two and dsTwo.data_two
    // point to the same address, so the value of
    // *dsTwo->data_two is changed
    printf("data_one in dsTwo is %d,\ndata_two in dsTwo is %d\n\n", dsTwo.data_one, *dsTwo.data_two);
    // show the data of dsThree after dsOne changed
    // the address that dsThree.data_two points to and
    // the address of dsOne.data_two are not the same,
    // so *dsThree.data_two keep the original value.
    printf("data_one in dsThree is %d,\ndata_two in dsThree is %d\n\n", dsThree.data_one, *dsThree.data_two);

    system("PAUSE");
}

void deepCopy(DataStruct* to, DataStruct* from) {
     to->data_one = from->data_one;
     // copy the real value to the address
     // that to->data_two points to
     memcpy(to->data_two, from->data_two, sizeof(int));
}
