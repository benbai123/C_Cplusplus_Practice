#include <iostream> 
#include <vector>

using namespace std;

/** Test basic vector operation with array,
 *
 * From http://www.cplusplus.com/reference/vector/vector/
 *		Vectors are sequence containers representing arrays that can change in size.
 *
 *		Just like arrays, vectors use contiguous storage locations for their elements,
 *		which means that their elements can also be accessed using offsets on regular pointers
 *		to its elements, and just as efficiently as in arrays. But unlike arrays, their size
 *		can change dynamically, with their storage being handled automatically by the container.
 */
void testBasic ();
void testInitialWithArray ();
int main() {
	testBasic();
	testInitialWithArray();
	system("PAUSE");
	return 0;
}

void testBasic () {
	cout << "function testBasic" << endl;
	// declare and init with size and default value
	// first param for size
	// second param for default value
	vector<int> intVector(5, 3);
	// declare and init with another vector
	// the values will be copied from intVector to intVectorTwo
	// change the value of intVectorTwo will not affect intVector
	vector<int> intVectorTwo(intVector);
	// declare int vector
	vector<int> intVectorThree(5);
	intVectorTwo[3] = 5;
	// init
	// vector knows the size itself
	for (int i = 0; i < intVectorThree.size(); i++) {
		intVectorThree[i] = 3*i;
	}
	// output content of vector
	cout << "output initVector: ";
	for (int i = 0; i < intVector.size(); i++) {
		if (i > 0) {
			cout << ", ";
		}
		cout << intVector[i];
	}
	
	cout << endl << "output initVectorTwo: ";
	for (int i = 0; i < intVectorTwo.size(); i++) {
		if (i > 0) {
			cout << ", ";
		}
		cout << intVectorTwo[i];
	}
	cout << endl << "output initVectorThree: ";
	for (int i = 0; i < intVectorThree.size(); i++) {
		if (i > 0) {
			cout << ", ";
		}
		cout << intVectorThree[i];
	}
	cout << endl << endl;
}

void testInitialWithArray () {
	cout << "function testInitialWithArray" << endl;
	int arr[] = {1, 3, 5};
	// declare and init with array
	vector<int> intVector(arr, arr+3);
	// declare and init with partial array
	vector<int> intVectorTwo(arr+1, arr+3);
	// output content of vector
	cout << "output initVector: ";
	for (int i = 0; i < intVector.size(); i++) {
		if (i > 0) {
			cout << ", ";
		}
		cout << intVector[i];
	}
	cout << endl << "output initVectorTwo: ";
	for (int i = 0; i < intVectorTwo.size(); i++) {
		if (i > 0) {
			cout << ", ";
		}
		cout << intVectorTwo[i];
	}
	cout << endl << endl;
}
