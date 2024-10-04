#include <iostream>
#include <fstream>
#include "Deque.h"

// TO DO 5
Deque::Deque()
{
    sentinel = new Node();        // create sentinal as node
    Node *emptyNode = new Node(); // create empty node
    ll_size = 2;                  // linked list has sentinal and normal node
    sentinel->next = emptyNode;
    sentinel->prev = emptyNode;
    emptyNode->next = sentinel;
    emptyNode->prev = sentinel;

    startIt = Iterator(emptyNode, true);
    endIt = Iterator(emptyNode, false);
}

Deque::~Deque()
{
    Node *temp = sentinel->next;
    while (temp != sentinel)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
    delete sentinel;
}

// TO DO 6
Iterator Deque::begin() const
{
    return startIt;
}

Iterator Deque::end() const
{
    return endIt;
}

int Deque::front() const
{
    if (sentinel->next == sentinel)
    {
        std::cout << "Cannot get front: deque is empty" << std::endl;
        return -1;
    }
    return sentinel->next->arr[0];
}

int Deque::back() const
{
    if (sentinel->prev == sentinel)
    {
        std::cout << "Cannot get back: deque is empty" << std::endl;
        return -1;
    }
    return sentinel->prev->arr[CHUNK_SIZE - 1];
}

// TO DO 7
bool Deque::empty() const
{
    Node nextNode = *sentinel->next;

    while (nextNode.next != sentinel)
    {
        for (int i = 0; i < CHUNK_SIZE; i++)
        {
            if (nextNode.arr[i] != NULL)
            {
                return false;
            }
            nextNode = *nextNode.next;
        }
    }
    return sentinel->next == sentinel;
}

int Deque::size() const
{
    int length = 0;
    Node *temp = sentinel->next;
    while (temp != sentinel)
    {
        length += CHUNK_SIZE;
        temp = temp->next;
    }
    return length;
}

// TO DO 8
void Deque::push_back(int val)
{
    Node *lastNode = sentinel->prev;
    int arr_pos = -1;
    for (int i = CHUNK_SIZE - 1; lastNode->arr[i] == -1; i--)
    {
        arr_pos = i;
    }
    if (arr_pos == -1)
    {
        Node *newNode = new Node();
        newNode->arr[0] = val;
        newNode->prev = lastNode;
        newNode->next = sentinel;
        lastNode->next = newNode;
        sentinel->prev = newNode;
    }
    else
    {
        lastNode->arr[arr_pos] = val;
    }
    return;
}

void Deque::push_front(int val)
{
    Node *firstNode = sentinel->next;
    int arr_pos = -1;
    for (int i = 0; firstNode->arr[i] == -1; i++)
    {
        arr_pos = i;
    }
    if (arr_pos == -1)
    {
        Node *newNode = new Node();
        newNode->arr[CHUNK_SIZE - 1] = val;
        newNode->prev = sentinel;
        newNode->next = firstNode;
        firstNode->prev = newNode;
        sentinel->next = newNode;
    }
    else
    {
        firstNode->arr[arr_pos] = val;
    }
    return;
}

void Deque::pop_back()
{
    if (empty())
    {
        std::cout << "Cannot pop_back: deque is empty" << std::endl;
        return;
    }
    Node *lastNode = sentinel->prev;
    int arr_pos = CHUNK_SIZE;
    for (int i = CHUNK_SIZE - 1; lastNode->arr[i] == -1; i--)
    {
        arr_pos = i;
    }
    if (arr_pos == 0)
    {
        Node *newLastNode = lastNode->prev;
        newLastNode->next = sentinel;
        sentinel->prev = newLastNode;
        delete lastNode;
    }
    else
    {
        lastNode->arr[arr_pos - 1] = -1;
    }
    return;
}

void Deque::pop_front()
{
    if (empty())
    {
        std::cout << "Cannot pop_front: deque is empty" << std::endl;
        return;
    }
    Node *firstNode = sentinel->next;
    int arr_pos = 0;
    for (int i = 0; firstNode->arr[i] == -1; i++)
    {
        arr_pos = i;
    }
    if (arr_pos == CHUNK_SIZE - 1)
    {
        Node *newFirstNode = firstNode->next;
        newFirstNode->prev = sentinel;
        sentinel->next = newFirstNode;
        delete firstNode;
    }
    else
    {
        firstNode->arr[arr_pos + 1] = -1;
    }
    return;
}

// TO DO 9
void Deque::print_deque() const
{
    if (empty())
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    Node *temp = sentinel->next;
    while (temp != sentinel)
    {
        for (int i = -1; i < CHUNK_SIZE - 1; i++)
        {
            if (temp->arr[i + 1] != NULL)
            {
                std::cout << temp->arr[i] << ", ";
            }
            else
            {
                std::cout << temp->arr[i] << "]";
                break;
            }
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

// TO DO 10
void Deque::insert(const Iterator &pos, int val)
{
    Node *endNode = sentinel->prev;
    int *curr = this->endIt.curr();

    if (pos.curr() == curr)
    {
        this->push_back(val);
        return;
    }

    while (curr != pos.curr() - 1)
    {
        int temp = *curr;
        if (endNode->arr[CHUNK_SIZE - 1] != -1)
        {
            Node *newNode = new Node();
            newNode->arr[0] = temp;
            newNode->prev = endNode;
            newNode->next = endNode->next;
            endNode->next->prev = newNode;
            endNode->next = newNode;
            endNode->arr[CHUNK_SIZE - 1] = -1;
            *curr--;
        }
        else
        {
            for (int i = CHUNK_SIZE - 1; i > 0; i--)
            {
                endNode->arr[i + 1] = endNode->arr[i];
                endNode->arr[i] = -1;
                *curr--;
            }
        }
        endNode = endNode->prev;
    }
    *curr = val;
    return;
}

void Deque::erase(const Iterator &pos)
{
    Node *endNode = sentinel->prev;
    int *curr = this->endIt.curr();

    if (*pos.curr() == front())
    {
        this->pop_front();
        return;
    }

    while (curr != pos.curr())
    {
        if (endNode->arr[0] != -1)
        {
            for (int i = 0; i < CHUNK_SIZE - 1; i++)
            {
                endNode->arr[i] = endNode->arr[i + 1];
            }
            endNode->arr[CHUNK_SIZE - 1] = -1;
            *curr++;
        }
        else
        {
            Node *temp = endNode;
            endNode = endNode->prev;
            endNode->next = temp->next;
            temp->next->prev = endNode;
            delete temp;
        }
    }
    return;
}

// TO DO 11
void Deque::store_deque(const char *filename) const
{
    std::ofstream file;
    file.open(filename);
    if (!file.is_open())
    {
        std::cout << "Cannot open file " << filename << std::endl;
        return;
    }
    Node *temp = sentinel->next;
    while (temp != sentinel)
    {
        for (int i = 0; i < CHUNK_SIZE; i++)
        {
            if (temp->arr[i] != -1)
            {
                file << temp->arr[i] << std::endl;
            }
        }
        temp = temp->next;
    }
    file.close();
    return;
}

void Deque::load_deque(const char *filename)
{
    std::ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        std::cout << "Cannot open file " << filename << std::endl;
        return;
    }
    while (!file.eof())
    {
        int val;
        file >> val;
        this->push_back(val);
    }
    file.close();
    return;
}
