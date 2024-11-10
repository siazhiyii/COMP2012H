#ifndef MYSTACK_H
#define MYSTACK_H

// TODO: Complete the declaration of the MyStack class
//
// You may refer to MyStack.tpp to know the corresponding member functions
// and the data members of the MyStack class.
// You can also refer to MyQueue.h since the MyQueue class is similar to MyStack
// Be noted that you should make all data members private, while making all
// member functions public.
template <typename T>
class MyStack
{
private:
    // Maximum number of items the queue can hold
    int capacity;
    // A dynamic array storing the items
    T *items;
    // topIndex: the index of the "top" item
    int topIndex;

public:
    // Constructor
    // The keyword "explicit" prevents implicit conversion, e.g. MyQueue q = 5;
    explicit MyStack(int capacity);

    // Destructor
    ~MyStack();

    // Add (push) an item into the stack.
    // If the stack is full, an error message is printed and the program exits.
    // For a stack, new items should be inserted to the top.
    void push(T item);

    // Remove (pop) an item from the stack.
    // If the stack is empty, an error message is printed and the program exits.
    // For a stack, items should be removed from the top.
    T &pop();

    // Return true if the stack is empty.
    bool isEmpty() const;

    // Return true if the stack is full.
    bool isFull() const;

    // Print all items in the stack, from top to bottom.
    void printItems() const;

    // Reset the stack to the "empty" state.
    void clearItems();
};

#include "MyStack.tpp"

#endif
