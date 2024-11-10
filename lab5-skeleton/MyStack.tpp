#include <iostream>
using namespace std;

// Constructor
// topIndex is the index of the top item.
template<typename T>
MyStack<T>::MyStack(int capacity) :capacity(capacity), topIndex(-1) {
    items = new T[capacity];
}

// Destructor
template<typename T>
MyStack<T>::~MyStack() {
    delete [] items;
}

// Add (push) an item into the stack.
// If the stack is full, an error message is printed and the program exits.
// For a stack, new items should be inserted to the top.
template<typename T>
void MyStack<T>::push(T item) {
    if (isFull()) {
        cout << "ERROR: Stack is full" << endl;
        exit(0);
    }
    this->items[++topIndex] = item;
}

// Remove (pop) an item from the stack.
// If the stack is empty, an error message is printed and the program exits.
// For a stack, items should be removed from the top.
template<typename T>
T &MyStack<T>::pop() {
    if (isEmpty()) {
        cout << "ERROR: Stack is empty" << endl;
        exit(0);
    }
    return this->items[topIndex--];
}

// Return true if the stack is empty.
template<typename T>
bool MyStack<T>::isEmpty() const {
    return (topIndex == -1);
}

// Return true if the stack is full.
template<typename T>
bool MyStack<T>::isFull() const {
    return topIndex >= this->capacity - 1;
}

// Print all items in the stack, from top to bottom.
template<typename T>
void MyStack<T>::printItems() const {
    for (int i = topIndex; i >= 0; i--) {
        cout << this->items[i] << endl;
    }
}

// Reset the stack to the "empty" state.
template<typename T>
void MyStack<T>::clearItems() {
    topIndex = -1;
}
