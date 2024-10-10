#include "kiosk.h"
#include <iostream>
using namespace std;

/**
 * A Kiosk implemented as linked list.
 * KioskNode is a node in the linked list, with a pointer pointing to the next node in the list. If there is no next node, it should be nullptr.
 * Do NOT modify these structs, otherwise your code may not compile with the test cases.
 */
struct KioskNode
{
    Item item;
    KioskNode *next;
};

struct Kiosk
{
    KioskNode *head;
};

/**
 * Create an empty kiosk as a dynamic instance.
 * As you learn OOP, this is equivalent to a constructor.
 */
Kiosk *createKiosk()
{
    return new Kiosk{nullptr};
}

/**
 * Deallocate the kiosk and its content.
 * As you learn OOP, this is equivalent to a destructor.
 */
void deleteKiosk(Kiosk *kiosk)
{
    for (KioskNode *cur = kiosk->head; cur != nullptr;)
    {
        KioskNode *next = cur->next;
        delete cur;
        cur = next;
    }
    delete kiosk;
}

/**
 * Add an item to the end of the linked list.
 */
void addItem(Kiosk *kiosk, const Item &item)
{
    // TODO
    KioskNode *newItem = new KioskNode;
    newItem->item = item;
    newItem->next = nullptr;

    if (kiosk->head == nullptr)
    {
        kiosk->head = newItem;
    }
    else
    {
        KioskNode *position = kiosk->head;
        while (position->next != nullptr)
        {
            position = position->next;
        }
        position->next = newItem;
    }
}

/**
 * Return true if the item exists in the kiosk.
 */
bool hasItem(const Kiosk *kiosk, const Item &item)
{
    // TODO
    if (kiosk->head == nullptr)
    {
        return false;
    }
    else
    {
        KioskNode *position = kiosk->head;
        while (position->next != nullptr)
        {
            if (compareItems(position->item, item) == 0)
            {
                return true;
            }
            position = position->next;
        }
        return false;
    }
}

/**
 * Remove the provided item from the kiosk.
 * You can use hasItem() to check if the item exists. If it does not, simply return early.
 * Manage the item counter and linked list pointers correctly. The item order is not important.
 */
void removeItem(Kiosk *kiosk, const Item &item)
{
    if (!hasItem(kiosk, item))
    {
        return;
    }

    KioskNode *position = kiosk->head;
    KioskNode *prev = nullptr;

    while (position != nullptr)
    {
        if (compareItems(position->item, item) == 0)
        {
            if (prev == nullptr)
            {
                kiosk->head = position->next;
            }
            else
            {
                prev->next = position->next;
            }
            delete position;
            return;
        }
        prev = position;
        position = position->next;
    }
}

/**
 * Sort the items in the kiosk array according to compareItems().
 * You may use any sorting algorithm you'd like, as long as the output is correct.
 * Hint: you may either swap the items in the linked list nodes, or create a new head pointer and "move" the nodes to it in order.
 */
void sort(Kiosk *kiosk)
{
    // TODO
    if (kiosk->head == nullptr)
        return;

    bool swapped;
    KioskNode *position;
    KioskNode *sortedPointer = nullptr;

    do
    {
        swapped = false;
        position = kiosk->head;

        while (position->next != sortedPointer)
        {
            if (compareItems(position->item, position->next->item) > 0)
            {
                Item temp = position->item;
                position->item = position->next->item;
                position->next->item = temp;
                swapped = true;
            }
            position = position->next;
        }
        sortedPointer = position;
    } while (swapped);
}

/**
 * Print the items in the kiosk matching the provided type.
 */
void printType(const Kiosk *kiosk, ItemType type)
{
    switch (type)
    {
    case SONG:
        cout << "SONGS:" << endl;
        break;
    case BOOK:
        cout << "BOOKS:" << endl;
        break;
    case FIGURE:
        cout << "FIGURES:" << endl;
        break;
    case GAME:
        cout << "GAMES:" << endl;
        break;
    }
    for (KioskNode *cur = kiosk->head; cur != nullptr; cur = cur->next)
    {
        if (cur->item.type == type)
        {
            cout << cur->item.name << ": " << cur->item.price << " HKD" << endl;
        }
    }
}

/**
 * Print the entire menu.
 */
void printMenu(const Kiosk *kiosk)
{
    printType(kiosk, SONG);
    cout << endl;
    printType(kiosk, BOOK);
    cout << endl;
    printType(kiosk, FIGURE);
    cout << endl;
    printType(kiosk, GAME);
    cout << endl;
}
