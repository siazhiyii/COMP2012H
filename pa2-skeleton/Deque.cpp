#include <iostream>
#include <fstream>
#include "Deque.h"
// remove
// #include "Iterator.cpp"
// using namespace std;

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
    if (empty())
    {
        return startIt;
    }
    // Iterator beginIt;
    Node *firstNode = sentinel->next;
    while (firstNode != sentinel)
    {
        for (int i = 0; i < CHUNK_SIZE; i++)
        {
            if (firstNode->arr[i] != 0)
            {
                Iterator beginIt(firstNode, true);
                return beginIt;
                // beginIt.current = &firstNode->arr[i];
                // beginIt.node = firstNode;
                // return beginIt;
            }
        }
        firstNode = firstNode->next;
    }
    return startIt;
}

Iterator Deque::end() const
{
    if (empty())
    {
        return endIt;
    }
    // Iterator lastIt;
    Node *lastNode = sentinel->prev;
    while (lastNode != sentinel)
    {
        for (int i = CHUNK_SIZE - 1; i > -1; i--)
        {
            if (lastNode->arr[i] != 0)
            {
                Iterator lastIt(lastNode, false);
                return lastIt.next();
                // if (i == CHUNK_SIZE - 1)
                // {
                //     if (lastNode->next == sentinel)
                //     {
                //         Node *newNode = new Node();
                //         lastIt.current = &newNode->arr[0];
                //         lastIt.node = newNode;
                //         newNode->next = sentinel;
                //         newNode->prev = lastNode;
                //         lastNode->next = newNode;
                //         sentinel->prev = newNode;
                //         return lastIt;
                //     }
                //     else
                //     {
                //         lastNode = lastNode->next;
                //         lastIt.current = &lastNode->arr[0];
                //         lastIt.node = lastNode;
                //         return lastIt;
                //     }
                // }
                // else
                // {
                //     lastIt.current = &lastNode->arr[i + 1];
                //     lastIt.node = lastNode;
                //     return lastIt;
                // }
            }
        }
        lastNode = lastNode->prev;
    }
    return endIt;
}

int Deque::front() const
{
    if (empty())
    {
        std::cout << "Cannot get front: deque is empty" << std::endl;
        return -1;
    }
    return *begin().curr();
}

int Deque::back() const
{
    if (empty())
    {
        std::cout << "Cannot get back: deque is empty" << std::endl;
        return -1;
    }

    // int *endValueIndex = end().curr();
    // if (endValueIndex == &end().node->arr[0])
    // {
    //     const Node *prevNode = end().node->prev;
    //     return prevNode->arr[CHUNK_SIZE - 1];
    // }
    return *end().prev().curr();
}

// TO DO 7
bool Deque::empty() const
{
    Node *nextNode = sentinel->next;

    while (nextNode != sentinel)
    {
        for (int i = 0; i < CHUNK_SIZE; i++)
        {
            if (nextNode->arr[i] != 0)
            {
                return false;
            }
        }
        nextNode = nextNode->next;
    }
    return true;
}

int Deque::size() const
{
    int size = 0;
    if (empty())
    {
        return size;
    }
    Node *temp = sentinel->next;
    while (temp != sentinel)
    {
        for (int i = 0; i < CHUNK_SIZE; i++)
        {
            if (temp->arr[i] != 0)
            {
                size++;
            }
        }
        temp = temp->next;
    }
    return size;
}

// TO DO 8
void Deque::push_back(int val)
{
    if (val == 0)
    {
        return;
    }
    Node *lastNode = sentinel->prev;
    int arr_pos = -1;
    int i = CHUNK_SIZE - 1;
    while (i >= 0 && lastNode->arr[i] == 0)
    {
        arr_pos = i;
        i--;
    }
    if (arr_pos == -1)
    {
        Node *newNode = new Node();
        newNode->arr[0] = val;
        newNode->prev = lastNode;
        newNode->next = sentinel;
        lastNode->next = newNode;
        sentinel->prev = newNode;
        return;
    }
    lastNode->arr[arr_pos] = val;
    return;
}

void Deque::push_front(int val)
{
    Node *firstNode = sentinel->next;
    int arr_pos = -1;
    for (int i = 0; firstNode->arr[i] == 0; i++)
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

    int *delPointer = end().prev().curr();
    *delPointer = 0;
    return;
}

void Deque::pop_front()
{
    if (empty())
    {
        std::cout << "Cannot pop_front: deque is empty" << std::endl;
        return;
    }

    int *delPointer = begin().curr();
    *delPointer = 0;
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
    bool beginning = true;
    Node *nextNode = sentinel->next;
    while (nextNode != sentinel)
    {
        for (int i = 0; i < CHUNK_SIZE; i++)
        {
            if (nextNode->arr[i] != 0)
            {
                if (beginning)
                {
                    std::cout << nextNode->arr[i];
                    beginning = false;
                }
                else
                {
                    std::cout << ", " << nextNode->arr[i];
                }
            }
        }
        nextNode = nextNode->next;
    }
    std::cout << "]" << std::endl;
}

// TO DO 10
void Deque::insert(const Iterator &pos, int val)
{
    if (pos.equal(begin()))
    {
        this->push_front(val);
        return;
    }

    int tempValue = 0;

    if (!(pos.equal(end())))
    {
        tempValue = *end().prev().curr();
        this->pop_back();
        insert(pos, val);
    }
    else if (pos.equal(end()))
    {
        *pos.curr() = val;
    }

    if (tempValue != 0)
    {
        this->push_back(tempValue);
    }
}

void Deque::erase(const Iterator &pos)
{
    if (pos.equal(begin()))
    {
        this->pop_front();
        return;
    }

    if (pos.equal(end().prev()))
    {
        this->pop_back();
        return;
    }

    int tempValue;

    if (!(pos.next().next().equal(end())))
    {
        tempValue = *end().prev().curr();
        this->pop_back();
        erase(pos);
    }
    else if (pos.next().next().equal(end()))
    {
        *pos.curr() = 0;
    }
    this->push_back(tempValue);
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
// remove

// void Deque::print_deque2() const
// {
//     std::cout << "[";
//     bool beginning = true;
//     Node *nextNode = sentinel->next;
//     while (nextNode != sentinel)
//     {
//         for (int i = 0; i < CHUNK_SIZE; i++)
//         {
//             if (beginning)
//             {
//                 std::cout << nextNode->arr[i];
//                 beginning = false;
//             }
//             else
//             {
//                 std::cout << ", " << nextNode->arr[i];
//             }
//         }
//         nextNode = nextNode->next;
//     }
//     std::cout << "]" << std::endl;
// }

// int main()
// {
//     Deque deque;

//     deque.push_back(10);
//     deque.push_back(15);
//     deque.push_back(25);

//     cout << "The deque now is: ";
//     deque.print_deque2();

//     deque.insert(deque.begin(), 5);
//     cout << "The deque now is: ";
//     deque.print_deque2();

//     deque.insert(deque.end().prev(), 20);
//     cout << "The deque now is: ";
//     deque.print_deque2();
// }