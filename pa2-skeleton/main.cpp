#include <iostream>
#include "Deque.h"
using namespace std;

void test_create_destroy() {
    cout << "===== Test create and destroy deque =====" << endl;
    Deque deque;
    cout << "Deque created" << endl;

    cout << "The deque now is: ";
    deque.print_deque();

    cout << "Deque destroyed" << endl;
    cout << "===== End Test =====" << endl << endl;
}

void test_push_back() {
    cout << "===== Test push back =====" << endl;
    Deque deque;

    deque.push_back(10);
    deque.push_back(2012);
    deque.push_back(2022);

    cout << "The deque now is: ";
    deque.print_deque();

    cout << "===== End Test =====" << endl << endl;
}

void test_push_front() {
    cout << "===== Test push front =====" << endl;
    Deque deque;

    deque.push_front(10);
    deque.push_front(2012);
    deque.push_front(2022);

    cout << "The deque now is: ";
    deque.print_deque();

    cout << "===== End Test =====" << endl << endl;
}

void test_front_back() {
    cout << "===== Test get front and back =====" << endl;
    Deque deque;

    // when deque is empty, the returned value doesn't matter
    int front_item = deque.front();
    int back_item = deque.back();

    deque.push_back(10);
    front_item = deque.front();
    back_item = deque.back();
    cout << "front: " << front_item << ", back: " << back_item << endl;

    deque.push_back(15);
    front_item = deque.front();
    back_item = deque.back();
    cout << "front: " << front_item << ", back: " << back_item << endl;

    deque.push_front(20);
    front_item = deque.front();
    back_item = deque.back();
    cout << "front: " << front_item << ", back: " << back_item << endl;

    cout << "===== End Test =====" << endl << endl;
}

void test_empty_size() {
    cout << "===== Test empty and size =====" << endl;
    Deque deque;

    cout << "deque is empty: " << (deque.empty() ? "true" : "false") << endl;
    cout << "size of deque: " << deque.size() << endl;

    deque.push_back(10);
    cout << "deque is empty: " << (deque.empty() ? "true" : "false") << endl;
    cout << "size of deque: " << deque.size() << endl;

    deque.push_back(15);
    cout << "deque is empty: " << (deque.empty() ? "true" : "false") << endl;
    cout << "size of deque: " << deque.size() << endl;

    deque.push_front(20);
    cout << "deque is empty: " << (deque.empty() ? "true" : "false") << endl;
    cout << "size of deque: " << deque.size() << endl;

    cout << "===== End Test =====" << endl << endl;
}

void test_pop_back() {
    cout << "===== Test pop back =====" << endl;
    Deque deque;

    deque.pop_back();

    deque.push_back(10);
    deque.push_back(15);
    deque.push_front(20);

    cout << "The deque now is: ";
    deque.print_deque();

    deque.pop_back();
    cout << "The deque now is: ";
    deque.print_deque();

    deque.pop_back();
    cout << "The deque now is: ";
    deque.print_deque();

    cout << "===== End Test =====" << endl << endl;
}

void test_pop_front() {
    cout << "===== Test pop front =====" << endl;
    Deque deque;

    deque.pop_front();

    deque.push_back(10);
    deque.push_back(15);
    deque.push_front(20);

    cout << "The deque now is: ";
    deque.print_deque();

    deque.pop_front();
    cout << "The deque now is: ";
    deque.print_deque();

    deque.pop_front();
    cout << "The deque now is: ";
    deque.print_deque();

    cout << "===== End Test =====" << endl << endl;
}

void test_insert() {
    cout << "===== Test insert =====" << endl;
    Deque deque;

    deque.push_back(10);
    deque.push_back(15);
    deque.push_back(25);

    cout << "The deque now is: ";
    deque.print_deque();

    deque.insert(deque.begin(), 5);
    cout << "The deque now is: ";
    deque.print_deque();

    deque.insert(deque.end().prev(), 20);
    cout << "The deque now is: ";
    deque.print_deque();

    cout << "===== End Test =====" << endl << endl;
}

void test_erase() {
    cout << "===== Test erase =====" << endl;
    Deque deque;

    deque.push_back(10);
    deque.push_back(15);
    deque.push_back(25);

    cout << "The deque now is: ";
    deque.print_deque();

    deque.erase(deque.begin());
    cout << "The deque now is: ";
    deque.print_deque();

    deque.erase(deque.end().prev());
    cout << "The deque now is: ";
    deque.print_deque();

    cout << "===== End Test =====" << endl << endl;
}

void test_store_load() {
    cout << "===== Test store and load deque =====" << endl;
    Deque deque;

    deque.push_back(10);
    deque.push_back(15);
    deque.push_back(25);

    cout << "The deque now is: ";
    deque.print_deque();

    deque.store_deque("deque_demo.txt");
    cout << "Successfully stored deque to 'deque_demo.txt'" << endl;

    Deque restored_deque;
    restored_deque.load_deque("deque_demo.txt");
    cout << "The restored deque is: ";
    restored_deque.print_deque();

    cout << "===== End Test =====" << endl;
}

int main() {
    test_create_destroy();
    test_push_back();
    test_push_front();
    test_front_back();
    test_empty_size();
    test_pop_back();
    test_pop_front();
    // test_insert();
    // test_erase();
    // test_store_load();

    return 0;
}