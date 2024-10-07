#include "kiosk.h"
#include <iostream>
using namespace std;

/**
 * A Kiosk implemented as dynamic-length array.
 * Do NOT modify this struct, otherwise your code may not compile with the test cases.
*/
struct Kiosk {
    Item* items;
    int numItems;
};

/**
 * Create an empty kiosk as a dynamic instance.
 * As you learn OOP, this is equivalent to a constructor.
*/
Kiosk* createKiosk()
{
    return new Kiosk{nullptr, 0};
}

/**
 * Deallocate the kiosk and its content.
 * As you learn OOP, this is equivalent to a destructor.
*/
void deleteKiosk(Kiosk* kiosk)
{
    delete[] kiosk->items;
    delete kiosk;
}

/**
 * Add an item to the end of the dynamic array.
*/
void addItem(Kiosk* kiosk, const Item &item)
{
    Item* newItems = new Item[kiosk->numItems + 1];
    for (int i = 0; i < kiosk->numItems; i++) {
        newItems[i] = kiosk->items[i];
    }
    newItems[kiosk->numItems++] = item;
    delete[] kiosk->items;
    kiosk->items = newItems;
}

/**
 * Return true if the item exists in the kiosk.
*/
bool hasItem(const Kiosk* kiosk, const Item &item)
{
    for (int i = 0; i < kiosk->numItems; i++) {
        if (compareItems(kiosk->items[i], item) == 0) {
            return true;
        }
    }
    return false;
}

/**
 * Remove the provided item from the kiosk.
 * You can use hasItem() to check if the item exists. If it does not, simply return early.
 * Manage the item counter and array size, as well as perform copying correctly. The item order is not important.
*/
void removeItem(Kiosk* kiosk, const Item &item)
{
    // TODO
}

/**
 * Sort the items in the kiosk array according to compareItems().
 * You may use any sorting algorithm you'd like, as long as the output is correct.
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
    for (int i = 0; i < kiosk->numItems; i++) {
        if (kiosk->items[i].type == type){
            cout << kiosk->items[i].name << ": " << kiosk->items[i].price << " HKD" << endl;
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
