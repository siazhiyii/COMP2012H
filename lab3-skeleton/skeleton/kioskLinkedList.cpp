#include "kiosk.h"
#include <iostream>
using namespace std;

/**
 * A Kiosk implemented as linked list.
 * KioskNode is a node in the linked list, with a pointer pointing to the next node in the list. If there is no next node, it should be nullptr.
 * Do NOT modify these structs, otherwise your code may not compile with the test cases.
*/
struct KioskNode {
    Item item;
    KioskNode* next;
};

struct Kiosk {
    KioskNode* head;
};

/**
 * Create an empty kiosk as a dynamic instance.
 * As you learn OOP, this is equivalent to a constructor.
*/
Kiosk* createKiosk()
{
    return new Kiosk{nullptr};
}

/**
 * Deallocate the kiosk and its content.
 * As you learn OOP, this is equivalent to a destructor.
*/
void deleteKiosk(Kiosk* kiosk)
{
    for (KioskNode* cur = kiosk->head; cur != nullptr; ) {
        KioskNode* next = cur->next;
        delete cur;
        cur = next;
    }
    delete kiosk;
}

/**
 * Add an item to the end of the linked list.
*/
void addItem(Kiosk* kiosk, const Item &item)
{
    // TODO
}

/**
 * Return true if the item exists in the kiosk.
*/
bool hasItem(const Kiosk* kiosk, const Item &item)
{
    // TODO
}

/**
 * Remove the provided item from the kiosk.
 * You can use hasItem() to check if the item exists. If it does not, simply return early.
 * Manage the item counter and linked list pointers correctly. The item order is not important.
*/
void removeItem(Kiosk* kiosk, const Item &item)
{
    // TODO
}

/**
 * Sort the items in the kiosk array according to compareItems().
 * You may use any sorting algorithm you'd like, as long as the output is correct.
 * Hint: you may either swap the items in the linked list nodes, or create a new head pointer and "move" the nodes to it in order.
*/
void sort(Kiosk* kiosk)
{
    // TODO
}

/**
 * Print the items in the kiosk matching the provided type.
*/
void printType(const Kiosk* kiosk, ItemType type)
{
    switch (type) {
        case SONG: cout << "SONGS:" << endl; break;
        case BOOK: cout << "BOOKS:" << endl; break;
        case FIGURE: cout << "FIGURES:" << endl; break;
        case GAME: cout << "GAMES:" << endl; break;
    }
    for (KioskNode* cur = kiosk->head; cur != nullptr; cur = cur->next) {
        if (cur->item.type == type) {
            cout << cur->item.name << ": " << cur->item.price << " HKD" << endl;
        }
    }
}

/**
 * Print the entire menu.
*/
void printMenu(const Kiosk* kiosk)
{
    printType(kiosk, SONG); cout << endl;
    printType(kiosk, BOOK); cout << endl;
    printType(kiosk, FIGURE); cout << endl;
    printType(kiosk, GAME); cout << endl;
}
