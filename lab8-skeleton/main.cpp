#include <iostream>
using namespace std;
#include "HashTable.h"


int main() {
    // intHashTable
    HashTable<int> intHashTable(5);

    for (int key = 0; key < 50; key++) {
        intHashTable.insert(key);
    }

    cout << "Initial int hash table:" << endl;
    intHashTable.displayTable();

    for (int key = 0; key < 50; key += 7) {
        intHashTable.remove(key);
    }

    cout << "Int hash table after removing some elements:" << endl;
    intHashTable.displayTable();


    // charHashTable
    HashTable<char> charHashTable(3);

    for (int key = 0; key < 25; key++) {
        charHashTable.insert('a' + key);
        charHashTable.insert('A' + key);
    }

    cout << "Char hash table:" << endl;
    charHashTable.displayTable();

    cout << "Preorder traversal of char hash table:" << endl;
    charHashTable.preOrder();
    return 0;
}
