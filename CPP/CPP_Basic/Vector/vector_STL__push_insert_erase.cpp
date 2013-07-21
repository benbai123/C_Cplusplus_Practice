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
 *
 * Tested functions:
 * http://www.cplusplus.com/reference/vector/vector/push_back/
 * push_back: void push_back (const value_type& val);
 *		Adds a new element (val) at the end of the vector
 *
 * http://www.cplusplus.com/reference/vector/vector/insert/
 * insert 1 -- single element: iterator insert (iterator position, const value_type& val);
 *		Insert an element (val) at the specified position
 * insert 2 -- fill: void insert (iterator position, size_type n, const value_type& val);
 *		Fill specified amount (n) of elements (val) starts from specified position
 * insert 3 -- range: template <class InputIterator>
 *			void insert (iterator position, InputIterator first, InputIterator last);
 *		Insert a range (first, last) of vector into this vector,
 *		starts from specified position
 *
 * http://www.cplusplus.com/reference/vector/vector/erase/
 * erase 1 -- erase single element: iterator erase (iterator position);
 *		Erase the element at the specified position
 * erase 2 -- erase a range: iterator erase (iterator first, iterator last);
 *		Erase elements from specified start position (first, included)
 *		to specified end position (last, excluded)
 */
void testBasic ();
void output(vector<int>::iterator start, vector<int>::iterator end, const char* msg);
int main() {
	testBasic();

	system("PAUSE");
	return 0;
}

void testBasic () {
	cout << "function testBasic (push, insert, erase)" << endl;
	vector<int> intVector;
	// {5, 5}
	vector<int> intVectorTwo;
	// push 0, 1, 2 into intVector,
	// intVector will be  {0, 1, 2} after this loop
	for (int i = 0; i < 3; i++) {
		intVector.push_back(i);
	}
	// intVectorTwo becomes {9, 11, 13, 15, 17}
	intVectorTwo.push_back(9);
	intVectorTwo.push_back(11);
	intVectorTwo.push_back(13);
	intVectorTwo.push_back(15);
	intVectorTwo.push_back(17);
	output(intVector.begin(), intVector.end(), "output intVector after push 0, 1, 2: ");
	output(intVectorTwo.begin(), intVectorTwo.end(), "output intVectorTwo: ");
	// insert 3 into intVector at 2nd position,
	// intVector will be  {0, 3, 1, 2}
	intVector.insert(intVector.begin()+1, 3);
	output(intVector.begin(), intVector.end(), "output intVector after insert 3 at 2nd position: ");
	// insert 7 into intVector from 2nd position to 5th position
	// intVector will be {0, 7, 7, 7, 3, 1, 2}
	intVector.insert(intVector.begin()+1, 3, 7);
	output(intVector.begin(), intVector.end(), "output intVector after fill 7 from 2nd position to 4th position: ");
	// insert 3rd element till the element before last element of intVectorTwo
	// to intVector, starts from 4th position of intVector
	// intVector will be {0, 7, 7, 13, 15, 7, 3, 1, 2}
	intVector.insert(intVector.begin()+3, intVectorTwo.begin()+2, intVectorTwo.end()-1);
	output(intVector.begin(), intVector.end(), "output intVector after insert partial intVectorTwo into intVector: ");
	// erase 4th element of intVector
	// intVector will be {0, 7, 7, 15, 7, 3, 1, 2}
	intVector.erase(intVector.begin()+3);
	output(intVector.begin(), intVector.end(), "output intVector after erase 4th element: ");
	// erase 4th element to 6th element of intVector
	// intVector will be {0, 7, 7, 1, 2}
	intVector.erase(intVector.begin()+3, intVector.begin()+6);
	output(intVector.begin(), intVector.end(), "output intVector after erase 4th to 6th elements: ");
	
	cout << endl << endl;
}
void output(vector<int>::iterator start, vector<int>::iterator end, const char* msg) {
	cout << msg << endl;
	int cnt = 0;
	for(; start != end; start++) {
		if (cnt > 0) {
			cout << ", ";
		}
		cout << *start;
		cnt++;
	}
	cout << endl;
}
