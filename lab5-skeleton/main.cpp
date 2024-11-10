#include <iostream>
#include <string>
#include "MyStack.h"
#include "MyQueue.h"
#include "Student.h"

using namespace std;

int main() {
    // Using Stack with Integers
    MyStack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.printItems();
    cout << "Is intStack full? " << intStack.isFull() << endl;
    cout << "Popped from intStack: " << intStack.pop() << endl;
    intStack.printItems();
    intStack.clearItems();
    cout << "Is intStack empty? " << intStack.isEmpty() << endl;
    cout << "---------------------------------------------" << endl;

    // Using Stack with Strings
    MyStack<string> stringStack(5);
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.printItems();
    cout << "Popped from stringStack: " << stringStack.pop() << endl;
    stringStack.printItems();
    cout << "---------------------------------------------" << endl;

    // Using Stack with Students
    MyStack<Student> studentStack(5);
    studentStack.push(Student(1, "Zoe", 4.0, 4.3));
    studentStack.push(Student(2, "Mike", 3.0, 3.5));
    studentStack.push(Student(3, "Shawn", 3.0, 4.2));
    studentStack.printItems();
    Student s1 = studentStack.pop();
    cout << "Popped student has average gpa: " << s1.getAverageGPA() << endl;
    studentStack.printItems();
    cout << "---------------------------------------------" << endl;

    // Using Queue with Integers
    MyQueue<int> intQueue(3);
    intQueue.push(1);
    intQueue.push(2);
    intQueue.push(3);
    intQueue.push(4);
    intQueue.printItems();
    cout << "Dequeued from intQueue: " << intQueue.pop() << endl;
    intQueue.printItems();
    cout << "Peeked from intQueue: " << intQueue.peek() << endl;
    intQueue.printItems();
    cout << "Is intQueue empty? " << intQueue.isEmpty() << endl;
    intQueue.clearItems();
    cout << "Is intQueue empty after clear? " << intQueue.isEmpty() << endl;
    cout << "---------------------------------------------" << endl;

    // Using Queue with Strings
    MyQueue<string> stringQueue(5);
    stringQueue.push("Hello");
    stringQueue.push("World");
    stringQueue.printItems();
    cout << "Dequeued from stringQueue: " << stringQueue.pop() << endl;
    stringQueue.printItems();
    cout << "---------------------------------------------" << endl;

    // Using Queue with Students
    MyQueue<Student> studentQueue(5);
    studentQueue.push(Student(1, "Zoe", 4.0, 4.3));
    studentQueue.push(Student(2, "Mike", 3.0, 3.5));
    studentQueue.printItems();
    Student s2 = studentQueue.pop();
    cout << "Dequeued student average gpa = " << s2.getAverageGPA() << endl;
    studentQueue.push(Student(3, "Shawn", 3.0, 4.2));
    studentQueue.printItems();
    cout << "Capacity of student queue: " << studentQueue.getCapacity() << endl;
    cout << "---------------------------------------------" << endl;

    return 0;
}
