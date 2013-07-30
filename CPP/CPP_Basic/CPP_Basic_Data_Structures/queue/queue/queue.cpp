#include <iostream> 
#include <queue>

using namespace std;

/** Test basic operations of queue.
 *
 * From http://www.cplusplus.com/reference/queue/queue/
 *		queues are a type of container adaptor, specifically designed to operate
 *		in a FIFO context (first-in first-out), where elements are inserted into
 *		one end of the container and extracted from the other.
 *
 *		queues are implemented as containers adaptors, which are classes that use
 *		an encapsulated object of a specific container class as its underlying container,
 *		providing a specific set of member functions to access its elements. Elements are
 *		pushed into the "back" of the specific container and popped from its "front".
 *
 * Tested functions:
 * http://www.cplusplus.com/reference/queue/queue/empty/
 * empty: bool empty ( ) const;
 *		Returns whether the queue is empty: i.e. whether its size is zero.
 *
 * http://www.cplusplus.com/reference/queue/queue/size/
 * size: size_type size ( ) const;
 *		Returns the number of elements in the queue.
 *
 * http://www.cplusplus.com/reference/queue/queue/push/
 * push: void push (const value_type& val);
 *		Adds a new element at the end of the queue, after its current last element.
 *		The content of this new element is initialized to val.
 *
 * http://www.cplusplus.com/reference/queue/queue/pop/
 * pop: void pop ( );
 *		Removes the next element in the queue, effectively reducing its size by one.
 *		The element removed is the "oldest" element in the queue whose value can be
 *		retrieved by calling member queue::front.
 *
 *		NOTE: pop probably cause runtime error if queue is empty
 *
 * http://www.cplusplus.com/reference/queue/queue/front/
 * front: value_type& front(); or const value_type& front() const;
 *		Returns a reference to the next element in the queue. This is the "oldest" element in
 *		the queue and the same element that is popped out from the queue when queue::pop is called.
 *
 *		NOTE: front probably cause runtime error if queue is empty
 *
 * http://www.cplusplus.com/reference/queue/queue/back/
 * back: value_type& back(); or const value_type& back() const;
 *		Returns a reference to the last element in the queue. This is the "newest" element in
 *		the queue (i.e. the last element pushed into the queue).
 *
 *		NOTE: back probably cause runtime error if queue is empty
 *
 */

queue<int> testEmptySizePush (queue<int> intQueue);
queue<int> testFrontBack (queue<int> intQueue);
queue<int> testPop (queue<int> intQueue);

int main() {
	queue<int> intQueue;

	intQueue = testEmptySizePush (intQueue);
	intQueue = testFrontBack (intQueue);
	intQueue = testPop (intQueue);

	system("PAUSE");
	return 0;
}
queue<int> testEmptySizePush (queue<int> intQueue) {
	cout << "function testEmptySizePush" << endl;
	// test empty and size
	cout << "is intQueue empty? " << (intQueue.empty()? "true" : "false") << endl;
	cout << "size of intQueue is: " << intQueue.size() << endl;
	cout << "push 3, 5 and 7 into intQueue" << endl;
	// test push
	intQueue.push(3);
	intQueue.push(5);
	intQueue.push(7);
	// test empty and size again
	cout << "is intQueue empty? " << (intQueue.empty()? "true" : "false") << endl;
	cout << "size of intQueue is: " << intQueue.size() << endl << endl;
	return intQueue;
}
queue<int> testFrontBack (queue<int> intQueue) {
	cout << "function testFrontBack" << endl;
	if (!intQueue.empty()) {
		// test front
		cout << "current first value is: " << intQueue.front() << endl;
		cout << "add 5 to first value" << endl;
		intQueue.front() += 5;
		cout << "modified first value is: " << intQueue.front() << endl;

		// test back
		cout << "current last value is: " << intQueue.back() << endl;
		cout << "add 5 to last value" << endl;
		intQueue.back() += 5;
		cout << "modified last value is: " << intQueue.back() << endl << endl;
	}
	return intQueue;
}
queue<int> testPop (queue<int> intQueue) {
	cout << "function testPop" << endl;
	if (!intQueue.empty()) {
		// test pop
		cout << "first value before pop is: " << intQueue.front() << endl;
		cout << "last value before pop is: " << intQueue.back() << endl;
		cout << "pop first value" << endl;
		intQueue.pop();
		cout << "first value after pop is: " << intQueue.front() << endl;
		cout << "last value after pop is: " << intQueue.back() << endl << endl;
	}
	return intQueue;
}
