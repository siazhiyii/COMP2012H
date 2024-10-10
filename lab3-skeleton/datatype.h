#ifndef __DATATYPES_H__
#define __DATATYPES_H__

#include <cstring>

enum ItemType { SONG, BOOK, FIGURE, GAME };

struct Item {
    const char* name;
    ItemType type;
    int price;
};

int compareItems(const Item& item1, const Item& item2);

#endif // __DATATYPES_H__