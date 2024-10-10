#include "datatype.h"

/**
 * Compare 2 items based on their prices and names.
 * Return a number representing the comparison between 2 items:
 * - A positive number: item1 is "larger" than item2. Sort item2 -> item1.
 * - A negative number: item1 is "smaller" than item2. Sort item1 -> item2.
 * - Zero: item1 and item2 are the same items.
*/
int compareItems(const Item& item1, const Item& item2) {
    if (item1.price != item2.price) return item1.price - item2.price;
    else return strcmp(item1.name, item2.name);
}
