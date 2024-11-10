#ifndef MYQUEUE_H
#define MYQUEUE_H

template<typename T>
class MyQueue {
private:
    // Maximum number of items the queue can hold
    int capacity;
    // A dynamic array storing the items
    T *items;
    // front: the index of the "front" item
    // back: the index of the "back" item
    // count: how many items are in the queue
    int front, back, count;

public:
    // Constructor
    // The keyword "explicit" prevents implicit conversion, e.g. MyQueue q = 5;
    explicit MyQueue(int capacity);
    // Destructor
    ~MyQueue();

    // Return the capacity of this queue
    int getCapacity() const { return capacity; }

    // Add (push) an item into the queue.
    // If the queue is full, it should be automatic to expand the capacity by 1.
    // For a queue, new items should be inserted to the back.
    void push(T item);

    // Remove (pop) an item from the queue.
    // If the queue is empty, an error message is printed and the program exits.
    // The "ERROR: Queue is empty" message should be printed to cerr.
    // For a queue, items should be removed from the front.
    T &pop();

    // Peek at the front item of the queue without removing it.
    // If the queue is empty, an error message is printed and the program exits.
    T &peek() const;

    // Return true if the queue is empty.
    bool isEmpty() const;

    // Return true if the queue is full.
    bool isFull() const;

    // Print all items in the queue, from front to back.
    void printItems() const;

    // Reset the queue to the "empty" state.
    void clearItems();

    // Expand the capacity of the queue to newCapacity.
    void expand(int newCapacity);
};

#include "MyQueue.tpp"

#endif
