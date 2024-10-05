#include <iostream>
#include <fstream>
#include "Iterator.h"

// TO DO 1
Iterator::Iterator(Node *node, bool from_first)
{
    this->node = node;
    if (from_first)
    {
        current = &node->arr[0];
        return;
    }
    else
    {
        for (int i = CHUNK_SIZE - 1; i > 0; i--)
        {
            if (&node->arr[i] != 0)
            {
                current = &node->arr[i];
                return;
            }
        }
        current = &node->arr[0];
        return;
    }
}

// TO DO 2
const int *Iterator::first() const
{
    return &node->arr[0];
}

const int *Iterator::last() const
{
    return &node->arr[CHUNK_SIZE];
}

// TO DO 3
bool Iterator::equal(const Iterator &other) const
{
    return (node == other.node) && (current == other.current);
}

int *Iterator::curr() const
{
    return current;
}

// TO DO 4
Iterator Iterator::next() const
{
    if (current == &node->arr[CHUNK_SIZE - 1])
    {
        return Iterator(node->next, true);
    }
    else
    {
        Iterator iterator = *this;
        iterator.current++;
        return iterator;
    }
}

Iterator Iterator::prev() const
{
    if (current == &node->arr[0])
    {
        return Iterator(node->prev, false);
    }
    else
    {
        Iterator iterator = *this;
        iterator.current--;
        return iterator;
    }
}