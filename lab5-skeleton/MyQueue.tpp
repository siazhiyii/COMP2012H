#include <iostream>
using namespace std;

// TODO: Complete the implementation of the member functions
// of MyQueue class.
//
// You may refer to MyStack.tpp to see how the corresponding functions
// are implemented. Note that some data members are different:
// - front: the index of the "front" item. Items should be removed from the front. It should be initialized as 0.
// - back: the index of the "back" item. Items should be added after the back. It should be initialized as -1.
// - count: how many items are in the queue.
//
// The queue is implemented as a "circular" queue - if the array limit is reached,
// new items "loop" back to the beginning of the array. The queue is full when the
// array has no empty slots.
// Note that this means the starting value of front and back is not strictly enforced.
// A queue with a single item would have "front" = "back", since they refer to the same item.

// Constructor
template <typename T>
MyQueue<T>::MyQueue(int capacity) : capacity(capacity), front(0), back(-1), count(0)
{
    items = new T[capacity];
}

// Destructor
template <typename T>
MyQueue<T>::~MyQueue()
{
    delete[] items;
}

// Add (push) an item into the queue.
// If the queue is full, it should be automatic to expand the capacity by 1.
// For a queue, new items should be inserted to the back.
template <typename T>
void MyQueue<T>::push(T item)
{
    if (isFull())
    {
        expand(capacity + 1);
    }
    back = (back + 1) % capacity;
    items[back] = item;
    count++;
}

// Remove (pop) an item from the queue.
// If the queue is empty, an error message is printed and the program exits.
// The "ERROR: Queue is empty" message should be printed to cerr.
// For a queue, items should be removed from the front.
template <typename T>
T &MyQueue<T>::pop()
{
    if (isEmpty())
    {
        cerr << "ERROR: Queue is empty" << endl;
        exit(0);
    }
    T &item = items[front];
    front = (front + 1) % capacity;
    count--;
    return item;
}

// Peek at the front item of the queue without removing it.
// If the queue is empty, an error message is printed and the program exits.
template <typename T>
T &MyQueue<T>::peek() const
{
    if (isEmpty())
    {
        cerr << "ERROR: Queue is empty" << endl;
        exit(0);
    }
    return items[front];
}

// Return true if the queue is empty.
template <typename T>
bool MyQueue<T>::isEmpty() const
{
    return count == 0;
}

// Return true if the queue is full.
template <typename T>
bool MyQueue<T>::isFull() const
{
    return count == capacity;
}

// Print all items in the queue, from front to back.
template <typename T>
void MyQueue<T>::printItems() const
{
    for (int i = 0; i < count; i++)
    {
        cout << items[(front + i) % capacity] << endl;
    }
}

// Reset the queue to the "empty" state.
template <typename T>
void MyQueue<T>::clearItems()
{
    front = 0;
    back = -1;
    count = 0;
}

// Expand the capacity of the queue to newCapacity.
template <typename T>
void MyQueue<T>::expand(int newCapacity)
{
    T *newItems = new T[newCapacity];
    for (int i = 0; i < count; i++)
    {
        newItems[i] = items[(front + i) % capacity];
    }
    delete[] items;
    items = newItems;
    front = 0;
    back = count - 1;
    capacity = newCapacity;
}
