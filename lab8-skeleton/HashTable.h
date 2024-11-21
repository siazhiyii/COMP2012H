#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "AVLTree.h"

template<typename T>
class HashTable {
private:
    AVLTree<T>* table;
    int capacity;

    int hashFunction(T key);

public:
    HashTable(int size);
    ~HashTable();

    void insert(T key);
    void remove(T key);
    void displayTable();
    void preOrder();
};

#include "HashTable.tpp"
#endif // HASHTABLE_H
