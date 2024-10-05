#ifndef PA2_DEQUE_H
#define PA2_DEQUE_H

#include "Iterator.h"

#include <iostream>
#include <fstream>

class Deque {

    private:
        Iterator startIt;     // the position of first item in deque
        Iterator endIt;       // the position after last item in deque

        Node* sentinel;     // sentinel of the circular doubly-linked list
        int ll_size;        // size of linked list, notice that this is number of chunks, not items

    public:
        Deque();
        ~Deque();

        Iterator begin() const;
        Iterator end() const;
        int front() const;
        int back() const;

        bool empty() const;
        int size() const;

        void push_back(int val);
        void push_front(int val);
        void pop_back();
        void pop_front();

        void print_deque() const;
        void print_deque2() const;

        void insert(const Iterator& pos, int val);
        void erase(const Iterator& pos);

        void store_deque(const char* filename) const;
        void load_deque(const char* filename);

};

#endif //PA2_DEQUE_H