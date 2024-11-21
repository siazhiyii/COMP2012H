template<typename T>
HashTable<T>::HashTable(int size) : capacity(size) {
    table = new AVLTree<T>[capacity];
}

template<typename T>
HashTable<T>::~HashTable() {
    delete[] table;
}

template<typename T>
int HashTable<T>::hashFunction(T key) {
    return key % capacity;
}

template<typename T>
void HashTable<T>::insert(T key) {
    int index = hashFunction(key);
    table[index].insert(key);
}

template<typename T>
void HashTable<T>::remove(T key) {
    int index = hashFunction(key);
    table[index].remove(key);
}

template<typename T>
void HashTable<T>::displayTable() {
    for (int i = 0; i < capacity; ++i) {
        cout << "Bucket " << i << ": \n";
        table[i].print();
    }
}

template<typename T>
void HashTable<T>::preOrder() {
    for (int i = 0; i < capacity; ++i) {
        table[i].preOrder();
    }
}
