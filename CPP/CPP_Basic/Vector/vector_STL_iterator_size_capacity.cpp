#include <iostream> 
#include <vector>

using namespace std;

/** Test basic vector operation with STL functions,
 *
 * From http://www.cplusplus.com/reference/vector/vector/
 *		Vectors are sequence containers representing arrays that can change in size.
 *
 *		Just like arrays, vectors use contiguous storage locations for their elements,
 *		which means that their elements can also be accessed using offsets on regular pointers
 *		to its elements, and just as efficiently as in arrays. But unlike arrays, their size
 *		can change dynamically, with their storage being handled automatically by the container.
 *
 * Tested functions:
 * http://www.cplusplus.com/reference/vector/vector/begin/
 * begin: iterator begin(); or const_iterator begin() const;
 *		Returns an iterator pointing to the first element in the vector.
 *
 * http://www.cplusplus.com/reference/vector/vector/end/
 * end: iterator end(); or const_iterator end() const;
 *		Returns an iterator referring to the past-the-end element in the vector container.
 *
 * http://www.cplusplus.com/reference/vector/vector/rbegin/
 * rbegin: reverse_iterator rbegin(); or const_reverse_iterator rbegin() const;
 *		Returns a reverse iterator pointing to the last element in the vector
 *		(i.e., its reverse beginning).
 *
 * http://www.cplusplus.com/reference/vector/vector/rend/
 * rend: reverse_iterator rend(); or const_reverse_iterator rend() const;
 *		Returns a reverse iterator pointing to the theoretical element preceding the first
 *		element in the vector (which is considered its reverse end).
 *
 * http://www.cplusplus.com/reference/vector/vector/size/
 * size: size_type size() const;
 *		Returns the number of elements in the vector.
 *		This is the number of actual objects held in the vector, which is
 *		not necessarily equal to its storage capacity.
 *
 * http://www.cplusplus.com/reference/vector/vector/max_size/
 * max_size: size_type max_size() const;
 *		Returns the maximum number of elements that the vector can hold.
 *		This is the maximum potential size the container can reach due to known system or
 *		library implementation limitations, but the container is by no means guaranteed to be able to
 *		reach that size: it can still fail to allocate storage at any point before that size is reached.
 *
 * http://www.cplusplus.com/reference/vector/vector/capacity/
 * capacity: size_type capacity() const;
 *		Returns the size of the storage space currently allocated for the vector,
 *		expressed in terms of elements.
 *		This capacity is not necessarily equal to the vector size. It can be equal or greater,
 *		with the extra space allowing to accommodate for growth without the need to
 *		reallocate on each insertion.
 *
 */
void testIterator ();
void testReverseIterator ();
void testSizeMaxsizeCapacity ();
int main() {
	testIterator ();
	testReverseIterator ();
	testSizeMaxsizeCapacity ();

	system("PAUSE");
	return 0;
}
void testIterator () {
	cout << "function testIterater" << endl;
	vector<int> intVector;
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		intVector.push_back(i);
	}
	for (vector<int>::iterator it = intVector.begin();
		it != intVector.end();
		it++) {
		if (cnt > 0) {
			cout << ", ";
		}
		cout << *it;
		cnt++;
	}
	cout << endl << endl;
}
void testReverseIterator () {
	cout << "function testReverseIterator" << endl;
	vector<int> intVector;
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		intVector.push_back(i);
	}
	for (vector<int>::reverse_iterator rit = intVector.rbegin();
		rit != intVector.rend();
		rit++) {
		if (cnt > 0) {
			cout << ", ";
		}
		cout << *rit;
		cnt++;
	}
	cout << endl << endl;
}
void testSizeMaxsizeCapacity () {
	cout << "function testSizeMaxsizeCapacity" << endl;
	vector<int> intVector;

	for (int i = 0; i < 5; i++) {
		intVector.push_back(i);
	}
	cout << "real size: " << intVector.size() << endl;
	cout << "max size: " << intVector.max_size() << endl;
	cout << "capacity: " << intVector.capacity() << endl;
	cout << endl << endl;
}
