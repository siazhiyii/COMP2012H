#ifndef PA2_ITERATOR_H
#define PA2_ITERATOR_H

const int CHUNK_SIZE = 8; // the chunk size, i.e., size of array in each Node

struct Node
{
    int arr[CHUNK_SIZE]; // the chunk
    Node *prev;          // previous Node
    Node *next;          // next Node
};

class Iterator
{
public:
    int *current;     // current position
    const Node *node; // current Node

public:
    Iterator() = default; // default constructor for dummy Iterator
    Iterator(Node *node, bool from_first);
    const int *first() const; // begin of the chunk, i.e., the position of first item
    const int *last() const;  // end of the chunk, i.e., the position after the last item
    bool equal(const Iterator &other) const;
    int *curr() const;
    Iterator next() const;
    Iterator prev() const;
};

#endif // PA2_ITERATOR_H
